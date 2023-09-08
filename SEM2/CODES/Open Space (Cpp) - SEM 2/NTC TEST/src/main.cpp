//IMPORTANT DETAIL!! The values are inverse, meaning if you measure a high value, the voltage will be low.
#include <Arduino.h>

#define NTC_ANALOGPIN A0

//Delay for reading values at a second interval.
unsigned long current_time = 0;
unsigned long previous_time = 0;
const int TEMP_INTERVAL = 1000;

/// @brief this function converts the raw values from the sensor into celcius.
/// @param RawADC 
/// @return Temp
double ThermistorConverter(int RawADC){
  double Temp;
  Temp = log(10000.0*((1024.0 / RawADC - 1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp -= 273.15;            // Convert Kelvin to Celcius
  return Temp;
}

/// @brief This functions reads and display the temperature from the NTC sensor.
void DisplayTemperature(){
  if(current_time - previous_time > TEMP_INTERVAL){
    int rawValue = analogRead(NTC_ANALOGPIN);
    double temperature = ThermistorConverter(rawValue);
    Serial.print("|Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C|");
    previous_time = current_time;
  }
}

void setup() {
  pinMode(NTC_ANALOGPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  current_time = millis();
  DisplayTemperature();
}