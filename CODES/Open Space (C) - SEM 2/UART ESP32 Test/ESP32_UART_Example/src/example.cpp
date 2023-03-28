#include <Arduino.h>

#include "Messaging.h"
#include "Timer.h"

const unsigned long TIMEOUT = 5000;

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

enum States state = INIT;

void fsm() {
  enum AckResults result; // Do not declare anything in a switch.
  switch (state) {
    case INIT:
      state = LEDON;
      break;
    case LEDON:
      SendMessage("$SetLedOn;");
      state = LEDON_READ_ACK;
      break;
    case LEDON_READ_ACK:
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
      break;
    case LEDON_FAILED_ACK:
      break;
    case LEDON_UNKNOWN_ACK:
      break;
    case LEDON_TIMEDOUT_ACK:
      break;
    case LEDON_CORRUPTED_ACK:
      break;
  }
}
