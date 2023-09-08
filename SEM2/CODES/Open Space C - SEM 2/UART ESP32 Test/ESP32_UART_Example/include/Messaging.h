/*
  Messaging.h

  Author: Gerald H. Hilderink <gerald.hilderink@gmail.com>
  Date:   10-03-2023

  Description:
  The Messaging library provides necessary functions to communicate
  via the serial port at a higher level of abstraction than the
  Serial object provides.
*/

#pragma onces
#include <Arduino.h>

/**
 * @brief ReadAcknowledge states.
 *
 * These states are returned by ReadAcknowledge().
 */
enum AckResults { DONE, FAILED, TIMEDOUT, UNKNOWN, CORRUPTED, UNDEFINED };

/**
 * @brief Send the specified message via the serial port.
 *
 * @param message The string to be send.
 */
void SendMessage(String message);

/**
 * @brief Read a message from the serial port.
 *
 * @return String The string received.
 */
String ReadMessage();

/**
 * @brief Checks if a message is available or not?
 *
 * @return true The first character of a message as arrived.
 * @return false Nothing has arrived.
 */
bool MessageAvailable();

/**
 * @brief Checks if the specified message is valid. Invalid begin-
 *        tokens and end-tokens will be detected, which determines
 *        that the message was corrupt or not.
 *
 * @param message The message to be checked.
 * @return true The message is correct.
 * @return false The message is corrupt.
 */
bool IsValidMessage(String message);

/**
 * @brief Trim the specified message and return the trimmed version.
 *        Trimming means that the begin-token will be removed.
 * 
 * @param message 
 * @return String 
 */
String TrimMessage(String message);

/**
 * @brief Read the acknowledge-tokens after sending a message.
 * 
 * @param timeout Specifies the maximum delay for waiting on 
 *                acknowledge-tokens.
 * @return enum AckResults State of receiving acknowledge-tokens.
 */
enum AckResults ReadAcknowledge(unsigned long timeout);