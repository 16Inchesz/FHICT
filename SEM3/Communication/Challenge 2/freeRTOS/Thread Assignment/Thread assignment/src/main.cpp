#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <string.h>

const uint32_t stackDepth = 1052;

//led constants
#define LED_1_PIN 14  //Sprinkler 1
#define LED_2_PIN 26  //Sprinkler 2
#define LED_3_PIN 21  //Sprinkler 3
#define LED_4_PIN 22  //Sprinkler 4

//scenes
const char* scene1[] = {
  "sp1 on", "wait 5", "sp1 off", "sp2 on", "wait 5", "sp2 off"
};

const char* scene2[] = {
  "sp2 on", "wait 5", "sp2 off", "sp3 on", "wait 5", "sp3 off"
};

const char* scene3[] = {
  "sp3 on", "wait 5", "sp3 off", "sp4 on", "wait 5", "sp4 off"
};

/// @brief function to control the LED based on the which LED and which state.
/// @param ledPin 
/// @param state 
void toggleLED(int ledPin, int state) {
  digitalWrite(ledPin, state);
}

/// @brief function to execute each scene and toggle what needs to be toggled.
/// @param scene 
/// @param sceneLength 
void executeScene(const char* scene[], int sceneLength) {
  for (int i = 0; i < sceneLength; i++) {
    if (strcmp(scene[i], "sp1 on") == 0) {
      toggleLED(LED_1_PIN, HIGH);
    } else if (strcmp(scene[i], "sp2 on") == 0) {
      toggleLED(LED_2_PIN, HIGH);
    } else if (strcmp(scene[i], "sp3 on") == 0) {
      toggleLED(LED_3_PIN, HIGH);
    } else if (strcmp(scene[i], "sp4 on") == 0) {
      toggleLED(LED_4_PIN, HIGH);
    } else if (strcmp(scene[i], "sp1 off") == 0) {
      toggleLED(LED_1_PIN, LOW);
    } else if (strcmp(scene[i], "sp2 off") == 0) {
      toggleLED(LED_2_PIN, LOW);
    } else if (strcmp(scene[i], "sp3 off") == 0) {
      toggleLED(LED_3_PIN, LOW);
    } else if (strcmp(scene[i], "sp4 off") == 0) {
      toggleLED(LED_4_PIN, LOW);
    } else if (strcmp(scene[i], "wait 5") == 0) {
      vTaskDelay(pdMS_TO_TICKS(5000));
    }
  }
}

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
}

void loop() {
  executeScene(scene1, sizeof(scene1)/ sizeof(scene1[0]));
  delay(1000);
  executeScene(scene2, sizeof(scene2)/ sizeof(scene2[0]));
  delay(1000);
  executeScene(scene3, sizeof(scene2)/ sizeof(scene2[0]));
  delay(1000);
}
