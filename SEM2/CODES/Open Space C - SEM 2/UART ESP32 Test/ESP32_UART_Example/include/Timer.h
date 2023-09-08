/*
  Timer.h

  Author: Gerald H. Hilderink <gerald.hilderink@gmail.com>
  Date:   10-03-2023

  Description:
  The Timer library provides necessary functions to start a timer
  and te determine if the timer has expired or not.
*/

#pragma once

void ResetTimer();
bool HasTimerExpired(unsigned long timeout);