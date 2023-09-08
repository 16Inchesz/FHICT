/*
  ExpirationTimer.h

  Author: Gerald H. Hilderink <gerald.hilderink@gmail.com>
  Date:   10-03-2023

  Description:
  See ExpirationTimer.h.
*/

#include <Arduino.h>
#include "ExpirationTimer.h"

unsigned long lastTime;

void ResetTimer() { lastTime = millis(); }
bool HasTimerExpired(unsigned long timeout) {
  return (millis() - lastTime > timeout);
}