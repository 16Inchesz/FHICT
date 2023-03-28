 // Information & Technology, exercise 2, Johnson Domacasse, 15-11-2022
#include <Arduino.h>

int total;
int counter;
int check;

void setup() {
  Serial.begin(9600);
  counter = 0;
  check = 0;
}
//"check" variable to initialize the program. "counter" variable to keep track of it and "total" variable to print it all.
void loop() {
  if (check == 0){
    if (total <= 100){
        Serial.println(total);
        counter += 1;
        total = counter * 2;
    }
  } 
  delay(100);
}