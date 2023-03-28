// Information & Technology, exercise 1, Johnson Domacasse, 15-11-2022

#include <Arduino.h>

int counter;
int check;

void setup() {
    Serial.begin(9600);
    counter = 0;
    check = false;
    Serial.println(counter);
}
void loop() {
    //Delay can be altered if you want it to go faster/slower. Higher number for slower and lower number for slower.
    //Check if variable determine if variable "checK" is true of false then run the code block.

    if (check == false){
        if (counter >= 0){
            counter += 1;
            Serial.println(counter);
            delay(100);
            if (counter == 100){
                check = true;
            }
        }
    }
    if (check == true){
        if (counter <= 100){
            counter -= 1;
            Serial.println(counter);
            delay(100);
            if (counter == 0){
                check = false;
            }
        }
    } 
}
