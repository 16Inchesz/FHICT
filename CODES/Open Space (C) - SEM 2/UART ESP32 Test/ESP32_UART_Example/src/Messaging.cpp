/*
  Messaging.cpp

  Author: Gerald H. Hilderink <gerald.hilderink@gmail.com>
  Date:   10-03-2023

  Description:
  See Messaging.h
*/

#include "Messaging.h"
#include "Timer.h"

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

enum AckResults result = UNDEFINED;
enum ReadAcknowledgeStates ra_state = RA_WAIT_FOR_ACK;

void SendMessage(String message) {
    Serial.print(message);
}

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

String TrimMessage(String message) {
  message.trim();
  return message.substring(1);
}

bool IsValidMessage(String message) {
  if (message[0] == '$') {
    // Count the number of '$' symbols in the payload. If more '$' symbols than
    // 1 are found then this means that the message is invalid.
    unsigned int number = 1;
    unsigned int length = message.length();
    for (int i = 1; i < length; i++) {
      if (message[i] == '$') {
        number++;
      }
    }
    return (number == 1);
  }
  return false;
}


bool MessageAvailable() { return Serial.available(); }

enum AckResults ReadAcknowledge(unsigned long timeout) {
  String msg;
  enum AckResults result = UNDEFINED;
  switch (ra_state) {
    case RA_WAIT_FOR_ACK:
      if (!HasTimerExpired(timeout)) {
        if (MessageAvailable()) {
          msg = ReadMessage();
          ra_state = RA_VALIDATING_ACK;
        }
      } else {
        ra_state = RA_TIMEDOUT;
      }
      break;
    case RA_VALIDATING_ACK:
      if (IsValidMessage(msg)) {
        msg = TrimMessage(msg);  // Use string after start token '$'
        ra_state = RA_VALIDATED_ACK;
      } else {
        ra_state = RA_CORRUPTED;
      }
      break;
    case RA_VALIDATED_ACK:
      if (msg == "ACK") {
        ra_state = RA_DONE;  // Message was successfully accepted.
      } else if (msg == "NACK") {
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