/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Fontys University of Applied Science
 * Name: Buzzer Demo
 * Date: 07/01/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include <Arduino.h>
#include <OpenRichShield.h>

const int PIN_BUZZER = 3; // The buzzer is on Pin 3

// frequencies of the tones
const int c4 = 261; // c4 (tone C on the 4th octave)
const int cs4 = 277; // c#4
const int d4 = 294;
const int ds4 = 311;
const int e4 = 330;
const int f4 = 349;
const int fs4 = 370;
const int g4 = 392;
const int gs4 = 415;
const int a4 = 440;
const int as4 = 466;
const int h4 = 494;

const int quarternote = 250;
const int halfnote = 2*quarternote;
const int wholenote = 4*quarternote;


void setup()
{
    pinMode(PIN_BUZZER, OUTPUT);
    digitalWrite(PIN_BUZZER, LOW); // set it to silent in case it was on

    // play here since we only want to here the song once.

    
    tone(PIN_BUZZER,c4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,d4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,e4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,c4,halfnote);
    delay(wholenote*2);

    tone(PIN_BUZZER,c4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,d4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,e4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,c4,halfnote);
    delay(wholenote*2);
    
    tone(PIN_BUZZER,e4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,f4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,g4,halfnote);
    delay(wholenote*2);
    
    tone(PIN_BUZZER,e4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,f4,halfnote);
    delay(halfnote);
    tone(PIN_BUZZER,g4,halfnote);
    delay(wholenote*2);

    }

void loop()
{
}
