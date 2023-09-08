/*
  Messaging.cpp

  Author: Gerald H. Hilderink <gerald.hilderink@gmail.com>
  Date:   10-03-2023

  Description:
  See Messaging.h
*/

#include "Messaging.h"

#include "ExpirationTimer.h"

/// @brief The state space of the state-machine.
/// The initial state is RA_WAIT_FOR_ACK.
/// The terminate state is the initial state.
enum ReadAcknowledgeStates {
  RA_WAIT_FOR_ACK,
  RA_VALIDATING_ACK,
  RA_VALIDATED_ACK,
  RA_DONE,
  RA_FAILED,
  RA_UNKNOWN,
  RA_TIMEDOUT,
  RA_CORRUPTED
};

// Global variables.
// These variables have unique names in global space, otherwise the compiler
// returns an error of multiple definitions of the variable.
enum ReadAcknowledgeStates ra_state = RA_WAIT_FOR_ACK;
String ra_msg;

void SendMessage(String message) { Serial.print(message); }

String ReadMessage() {
  if (Serial.available()) {
    String msg;
    msg = Serial.readStringUntil(';');
    // msg does not contain end token ';'.
    return msg;
  } else {
    return "";
  }
}

String StripMessage(String message) {
  // Remove spaces and remove '$' symbol.
  message.trim();
  return message.substring(1);
}

bool IsValidMessage(String message) {
  if (message[0] == '$') {
    // Count the '$' symbols in the payload. If more '$' symbols than
    // 1 are found then this means that the message is invalid.
    for (unsigned int i = 1; i < message.length(); i++) {
      if (message[i] == '$') {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool MessageAvailable() { return Serial.available(); }

enum AckResults ReadAcknowledge(unsigned long timeout) {
  enum AckResults result = UNDEFINED;
  switch (ra_state) {
    case RA_WAIT_FOR_ACK:
      if (!HasTimerExpired(timeout)) {
        if (MessageAvailable()) {
          ra_msg = ReadMessage();
          ra_state = RA_VALIDATING_ACK;
        }
      } else {
        ra_state = RA_TIMEDOUT;
      }
      break;
    case RA_VALIDATING_ACK:
      if (IsValidMessage(ra_msg)) {
        ra_msg = StripMessage(ra_msg);  // Use string after start token '$'
        ra_state = RA_VALIDATED_ACK;
      } else {
        ra_state = RA_CORRUPTED;
      }
      break;
    case RA_VALIDATED_ACK:
      if (ra_msg == "ACK") {
        ra_state = RA_DONE;  // Message was successfully accepted.
      } else if (ra_msg == "NACK") {
        ra_state = RA_FAILED;  // Message was unsuccessfully accepted.
      } else {
        ra_state = RA_UNKNOWN;  // Acknowledge was unknown.
      }
      break;
    case RA_DONE:
      // Continue with the next state.
      result = DONE;
      ra_state = RA_WAIT_FOR_ACK;
      break;
    case RA_FAILED:
      // Message failed to be accepted.
      result = FAILED;
      ra_state = RA_WAIT_FOR_ACK;
      break;
    case RA_UNKNOWN:
      // Acknowledge was valid but unknown.
      result = UNKNOWN;
      ra_state = RA_WAIT_FOR_ACK;
      break;
    case RA_TIMEDOUT:
      // Reading Acknowledge was timed out.
      result = TIMEDOUT;
      ra_state = RA_WAIT_FOR_ACK;
      break;
    case RA_CORRUPTED:
      // Acknowledge was corrupt.
      result = CORRUPTED;
      ra_state = RA_WAIT_FOR_ACK;
      break;
  }
  return result;
}