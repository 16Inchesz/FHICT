#include "ExampleSender.h"

#include <Arduino.h>

#include "ExpirationTimer.h"
#include "Messaging.h"

/// @brief The maximum waiting for acknowledgment.
const unsigned long TIMEOUT = 5000;

/// @brief The state space of this state-machine.
enum States {
  INIT,
  LEDON,
  LEDON_READ_ACK,
  NEXT_STATE,
  LEDON_FAILED_ACK,
  LEDON_UNKNOWN_ACK,
  LEDON_TIMEDOUT_ACK,
  LEDON_CORRUPTED_ACK
};

/// @brief The initial state.
enum States state = INIT;

/// @brief The finite state-machine.
void fsm() {
  enum AckResults result;  // Do not declare anything in a switch.
  switch (state) {
    case INIT:
      state = LEDON;
      break;
    case LEDON:
      // Send a message.
      SendMessage("$SetLedOn;");
      // After sending a message, wait for acknowledge-token.
      state = LEDON_READ_ACK;
      break;
    case LEDON_READ_ACK:
      // Read acknowledge-token and branch based on result.
      result = ReadAcknowledge(TIMEOUT);
      switch (result) {
        case DONE:
          state = NEXT_STATE;
          break;
        case FAILED:
          state = LEDON_FAILED_ACK;
          break;
        case TIMEDOUT:
          state = LEDON_TIMEDOUT_ACK;
          break;
        case UNKNOWN:
          state = LEDON_UNKNOWN_ACK;
          break;
        case CORRUPTED:
          state = LEDON_CORRUPTED_ACK;
          break;
        case UNDEFINED:
          break;
      }
      break;
    case NEXT_STATE:
      // Must be further designed.
      break;
    case LEDON_FAILED_ACK:
      // Must be further designed.
      break;
    case LEDON_UNKNOWN_ACK:
      // Must be further designed.
      break;
    case LEDON_TIMEDOUT_ACK:
      // Must be further designed.
      break;
    case LEDON_CORRUPTED_ACK:
      // Must be further designed.
      break;
  }
}
