// Information & Technology, exercise 3, Johnson Domacasse, 15-11-2022
#include <Arduino.h>

int total;
int check;

void setup() {
  Serial.begin(9600);
  check = 1;
  total = 1;
}

//like exercise 2, use "check" variable to initialize program. 
//"total" will not print 0 and will then start from 1 till 99, since 101 passed the threshhold.
void loop() {
  if (check != 0){
    if (total <= 100){
        Serial.println(total);
        total = total + 2;
    }
  } 
  delay(100);
}