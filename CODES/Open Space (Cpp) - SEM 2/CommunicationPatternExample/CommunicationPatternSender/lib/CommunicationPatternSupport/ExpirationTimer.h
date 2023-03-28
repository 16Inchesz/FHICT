/*
  ExpirationTimer.h

  Author: Gerald H. Hilderink <gerald.hilderink@gmail.com>
  Date:   10-03-2023

  Description:
  The Timer library provides necessary functions to start a timer
  and o determine if the timer has expired or not.
*/

#ifndef EXPIRATIONTIMER_H
#define EXPIRATIONTIMER_H

/**
 * @brief Reset the timer and let it start counting.
 *
 */
void ResetTimer();

/**
 * @brief Check if the timer has expired the specified timeout since last reset.
 *
 * @param timeout The expiration time.
 * @return true The time has expired.
 * @return false The time has not expired.
 */
bool HasTimerExpired(unsigned long timeout);

#endif  // EXPIRATIONTIMER_H