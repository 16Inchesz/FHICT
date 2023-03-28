
//ICT & Technology, exercise 2, Johnson Domacasse, 24-11-2022
#include <Arduino.h>
#include <OpenRichShield.h>

//2 hz display warning.
void display_warning()
{
  display.off();
  delay(200);
  display.on();
  delay(200);
}

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  display.show(humidity);
  Serial.print(humidity);
  Serial.print("%\n");  
  if(humidity >= 90)
  {
    display_warning();
  }
  delay(1000);
}