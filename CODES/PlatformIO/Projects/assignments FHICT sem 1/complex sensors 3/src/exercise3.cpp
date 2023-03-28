// ICT & Technology, exercise 3, Johnson Domacasse, 24-11-2022
#include <Arduino.h>
#include <OpenRichShield.h>

#define POTPIN A0
#define YELLOWLED 7
#define BLUELED 6
#define GREENLED 5
#define REDLED 4

// 2 hz display warning.
void display_warning()
{
  display.off();
  delay(1000);
  display.on();
  delay(1000);
}

// Initialize potentiometer.
void init_potentiometer()
{
  pinMode(POTPIN, INPUT);
}

//read humid
float humidity;
float read_humidity()
{
  humidity = dht.readHumidity();
  display.show(humidity);
  Serial.print(humidity);
  Serial.print("%\n");
  return humidity;
}
// read temperature
int temperature;
int read_temperature()
{
  int angle;
  angle = analogRead(POTPIN);
  temperature = map(angle, 0, 1023, -5, 40);
  return temperature;
}

// LED control
void leds_off()
{
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(BLUELED, LOW);
  digitalWrite(GREENLED, LOW);
  digitalWrite(REDLED, LOW);
}
void perfect_temp()
{
  leds_off();
  digitalWrite(GREENLED, HIGH);
}
void warning_temp()
{
  leds_off();
  digitalWrite(YELLOWLED, HIGH);
  digitalWrite(BLUELED, HIGH);
}
void critical_temp()
{
  leds_off();
  digitalWrite(REDLED, HIGH);
  digitalWrite(BLUELED, HIGH);
}

//Arduino Functions
void setup()
{
  Serial.begin(9600);
  init_potentiometer();
  dht.begin();
}

//states were used for better debugging, code without states is commented below.
int state = 0;
void loop()
{
  read_humidity();
  read_temperature();

  if (humidity >= 90)
  {
    display_warning();
  }
  
  //set states
  if (temperature >= 14 && temperature <= 22) // perfect temp
  {
    state = 1;
  }
  else if (temperature < 14 && temperature >= 10) // cold becoming too cold
  {
    state = 2;
  }
  else if (temperature > 22 && temperature <= 25) // hot becoming to hot.
  {
    state = 2;
  }
  else if (temperature < 10) // too cold
  {
    state = 3;
  }
  else if (temperature > 25) // too hot
  {
    state = 3;
  }

  //run states
  if (state == 1)
  {
    perfect_temp();
  } else if (state == 2)
  {
    warning_temp();
  }
  else if (state == 3)
  {
    critical_temp();
  }
  delay(500);
}

/*
void loop()
{
  read_humidity();
  read_temperature();

  if (humidity >= 90)
  {
    display_warning();
  }

  if (temperature >= 14 && temperature <= 22) // perfect temp
  {
    perfect_temp();
  }
  else if (temperature < 14 && temperature >= 10) // cold becoming too cold
  {
    warning_temp();
  }
  else if (temperature > 22 && temperature <= 25) // hot becoming to hot.
  {
    warning_temp();
  }
  else if (temperature < 10) // too cold
  {
    critical_temp();
  }
  else if (temperature > 25) // too hot
  {
    critical_temp();
  }
  delay(500);
}
*/
