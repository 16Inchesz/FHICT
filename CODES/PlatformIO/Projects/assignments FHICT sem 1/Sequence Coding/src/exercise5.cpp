// ICT & Technology, exercise 5, Johnson Domacasse, 22-11-2022

#include <Arduino.h>
#include <OpenRichShield.h>

// CONSTANTS (Could also be const int's)
#define POTPIN A0
#define NTCPIN A1
#define LDRPIN A2
#define BUTTON1 9
#define BUTTON2 8

//Initializing PINs functions.
void init_potentiometer()
{
    pinMode(POTPIN, INPUT);
}

void init_temperaturemeter()
{
    pinMode(NTCPIN, INPUT);
}

void init_brightnessmeter()
{
    pinMode(LDRPIN, INPUT);
}

void init_buttons()
{
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
}
void setup()
{
    Serial.begin(9600);
    init_brightnessmeter();
    init_potentiometer();
    init_temperaturemeter();
    init_buttons();
}

//increment and decrementfunctions. state is also declared here because I need it for the functions.
int state = 0;
void increment()
{
    state++;
}

void decrement()
{
    state--;
}

// reading and displaying functions
void read_display_brightness()
{
    int brightness = analogRead(LDRPIN);
    display.show(brightness);
}
void read_display_temperature()
{
    int temp = analogRead(NTCPIN);
    display.show(temp);
}
void read_display_potentiometer()
{
    int angle = analogRead(POTPIN);
    display.show(angle);
}

//if the 2 below variables are placed within the loop function, it would not register as efficiently.
int lastButton1State = HIGH;
int lastButton2State = HIGH;
void loop()
{
    int button1State = digitalRead(BUTTON1);
    int button2State = digitalRead(BUTTON2);
    // button 1
    if (button1State == LOW && lastButton1State == HIGH)
    {
        increment();
        if (state == 3)
        {
            state = 0;
        }
    }
    // button 2
    if (button2State == LOW && lastButton2State == HIGH)
    {
        decrement();
        if (state == -1)
        {
            state = 2;
        }
    }
    lastButton1State = button1State;
    lastButton2State = button2State;
    if (state == 0)
    {
        read_display_brightness();
    }
    else if (state == 1)
    {
        read_display_temperature();
    }
    else if (state == 2)
    {
        read_display_potentiometer();
    }
    delay(10);
}
