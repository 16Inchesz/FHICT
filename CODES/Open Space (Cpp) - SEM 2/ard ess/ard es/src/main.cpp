#include <Arduino.h>
#define BUTTON_D10_MASK (1 << PB2)
#define BUTTON_D11_MASK (1 << PB3)

#define LED_D10_MASK (1 << PD5)
#define LED_D11_MASK (1 << PD6)

// defining intervals used for buttons/ timers
const int interval20Hz = 50;
const int interval4hz = 250;

// timer for buttons
unsigned long timeButtonD10 = 0;
unsigned long timeButtonD11 = 0;
unsigned long timeStartButtonD10 = 0;
unsigned long timeStartButtonD11 = 0;
unsigned long timeStartBlink = 0;
unsigned long saved_delaytimetwo = 0;
/// States for buttons
bool StateButtonD10 = true;
bool StateButtonD11 = true;
bool prevStateBtnD10 = 0;
bool prevStateBtnD11 = 0;
bool button_one_state = 0;
bool button_two_state = 0;
uint16_t timer = 0;
uint16_t saved_delaytime = 0;

void setup()
{
  Serial.begin(9600);
  DDRD = DDRD | B01100000;
  DDRB = DDRB &= ~BUTTON_D10_MASK;
  DDRB = DDRB &= ~BUTTON_D11_MASK;
}

void LED_D10_ON()
{
  PORTD = (PORTD | LED_D10_MASK) & 0x7F;
  PORTD &= ~LED_D11_MASK;
}

void LED_D11_ON()
{
  PORTD = (PORTD | LED_D11_MASK) & 0x7F;
  PORTD &= ~LED_D10_MASK;
}

void BlinkLEDS()
{
  if (timer - timeStartBlink < interval4hz)
  {
    PORTD = PORTD | LED_D10_MASK;
    PORTD &= ~LED_D11_MASK;
    Serial.println("D10");
  }
  if ((timer - timeStartBlink >= interval4hz) && (timer - timeStartBlink < 2 * interval4hz))
  {
    PORTD = PORTD | LED_D11_MASK;
    PORTD &= ~LED_D10_MASK;
    Serial.println("D11");
  }
  if (timer - timeStartBlink >= 2 * interval4hz)
  {
    timeStartBlink = timer;
  }
}

void ReadButtonD10()
{
  // sets state of button
  button_one_state = !(PINB &= BUTTON_D10_MASK);

  // checks if button has been pressed
  if (button_one_state && saved_delaytimetwo == 0)
  {
    saved_delaytimetwo = timer;
    Serial.println("button pressed");
  }

  // checks if button is not pressed
  if (!button_one_state && saved_delaytimetwo != 0)
  {
    if (timer - saved_delaytimetwo >= 100)
    {
      saved_delaytimetwo = 0;
      PORTD &= ~LED_D10_MASK;
      Serial.println("button released");
    }
  }

  // this happens when button is still pressed after certain time has passed
  if (button_one_state && saved_delaytimetwo != 0 && timer - saved_delaytimetwo >= 100)
  {
    PORTD = PORTD | LED_D10_MASK;
  }
}
void ReadButtonD11()
{
  // sets state of button
  button_two_state = !(PINB &= BUTTON_D11_MASK);

  // checks if button has been pressed
  if (button_two_state && saved_delaytimetwo == 0)
  {
    saved_delaytimetwo = timer;
    Serial.println("button pressed");
  }

  // checks if button is not pressed
  if (!button_two_state && saved_delaytimetwo != 0)
  {
    if (timer - saved_delaytimetwo >= 100)
    {
      saved_delaytimetwo = 0;
      PORTD &= ~LED_D11_MASK;
      Serial.println("button released");
    }
  }

  // this happens when button is still pressed after certain time has passed
  if (button_two_state && saved_delaytimetwo != 0 && timer - saved_delaytimetwo >= 100)
  {
    PORTD = PORTD | LED_D11_MASK;
  }
}

void ButtonManager()
{
  if ((StateButtonD10 == StateButtonD11) == 0)
  {
    BlinkLEDS();
  }
  ReadButtonD10();
  ReadButtonD11();
}

void loop()
{
  // ButtonManager();
  // ReadButtonD10();
  ReadButtonD11();
  timer = millis();
}