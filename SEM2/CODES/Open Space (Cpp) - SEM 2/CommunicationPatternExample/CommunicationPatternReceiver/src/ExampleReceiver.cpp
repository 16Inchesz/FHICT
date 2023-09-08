#include "ExampleReceiver.h"

#include <Arduino.h>

#include "ExpirationTimer.h"
#include "Messaging.h"

/// @brief The state space of this state-machine.
enum States {
  INIT,
  RECEIVE_MSG,
  VALIDATING_MSG,
  HANDLE_MSG,
  UNKNOWN_MSG,
  CORRUPTED_MSG,
  LED_IS_ON,
  LED_IS_OFF,
};

/// @brief The initial state.
enum States state = INIT;
String msg;  // Must be unique name omn global space.
bool result = false;

/// @brief Turn yellow LED on.
void YellowLedOn();

/// @brief Turn yellow LED on.
void YellowLedOff();

/// @brief Turn red LED on.
void RedLedOn();

/// @brief Turn red LED off.
void RedLedOff();

/// @brief Turn blue LED on.
void BlueLedOn();

/// @brief Turn blue LED off.
void BlueLedOff();

/// @brief The finite state-machine.
void fsm() {
  switch (state) {
    case INIT:
      state = RECEIVE_MSG;
      break;
    case RECEIVE_MSG:
      if (MessageAvailable()) {
        msg = ReadMessage();
        result = IsValidMessage(msg);
      }
      state = VALIDATING_MSG;
      break;
    case VALIDATING_MSG:
      if (result) {
        msg = StripMessage(msg);
        state = HANDLE_MSG;
      } else {
        SendMessage("$NACK;");
        YellowLedOn();
        state = CORRUPTED_MSG;
      }
      break;
    case HANDLE_MSG:
      if (msg == "LedOn") {
        SendMessage("$ACK;");
        RedLedOn();
      } else if (msg == "LedOff") {
        SendMessage("$ACK;");
        RedLedOff();
      } else {
        SendMessage("$NACK;");
        BlueLedOn();
      }
      break;
    case CORRUPTED_MSG:
      // Must be further designed.
      break;
    case UNKNOWN_MSG:
      // Must be further designed.
      break;
    case LED_IS_ON:
      // Must be further designed.
      break;
    case LED_IS_OFF:
      // Must be further designed.
      break;
  }
}

void SetupLeds() { /* not implemented yet */
}
void YellowLedOn() { /* not implemented yet */
}
void YellowLedOff() { /* not implemented yet */
}
void RedLedOn() { /* not implemented yet */
}
void RedLedOff() { /* not implemented yet */
}
void BlueLedOn() { /* not implemented yet */
}
void BlueLedOff() { /* not implemented yet */
}