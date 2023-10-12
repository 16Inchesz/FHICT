#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <string.h>


//led constants
#define LED_1_PIN 14  //Sprinkler 1
#define LED_2_PIN 26  //Sprinkler 2
#define LED_3_PIN 21  //Sprinkler 3
#define LED_4_PIN 22  //Sprinkler 4

//stack depth for the esp32
const uint32_t stackDepth = 1052;

//threads
void sceneExecutionTask(void *pvParameters);
void uartReaderTask(void *pvParameters);


//define semaphores for both threads.
SemaphoreHandle_t uartReaderSemaphore;
SemaphoreHandle_t sceneExecutionSemaphore;

//define mutexes for LEDs
SemaphoreHandle_t mutexLED1;
SemaphoreHandle_t mutexLED2;
SemaphoreHandle_t mutexLED3;
SemaphoreHandle_t mutexLED4;

//define mutexes for scenes
SemaphoreHandle_t mutexScene1;
SemaphoreHandle_t mutexScene2;
SemaphoreHandle_t mutexScene3;

//functions
void executeScene(const char* scene[], int sceneLength);
void toggleLED(int ledPin, int state);

//scenes
const char* scene1[] = { "sp1 on", "wait 5", "sp1 off", "sp2 on", "wait 5", "sp2 off" };
const char* scene2[] = { "sp2 on", "wait 5", "sp2 off", "sp3 on", "wait 5", "sp3 off" };
const char* scene3[] = { "sp3 on", "wait 5", "sp3 off", "sp4 on", "wait 5", "sp4 off" };

void setup() {
  Serial.begin(9600);

  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);

  uartReaderSemaphore = xSemaphoreCreateMutex();
  sceneExecutionSemaphore = xSemaphoreCreateMutex();

  mutexLED1 = xSemaphoreCreateMutex();
  mutexLED2 = xSemaphoreCreateMutex();
  mutexLED3 = xSemaphoreCreateMutex();
  mutexLED4 = xSemaphoreCreateMutex();

  mutexScene1 = xSemaphoreCreateMutex();
  mutexScene2 = xSemaphoreCreateMutex();
  mutexScene3 = xSemaphoreCreateMutex();

  if ((uartReaderSemaphore == NULL) || (sceneExecutionSemaphore == NULL)){
    Serial.println("Mutex can not be created");
  }
  xTaskCreate(uartReaderTask, "UART Reader Task", stackDepth, NULL, 2, NULL);
}

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
  Serial.println("inside the execute scene function");
  for (int i = 0; i < sceneLength; i++) {
    if (strcmp(scene[i], "sp1 on") == 0) {
      xSemaphoreTake(mutexLED1, portMAX_DELAY);
      toggleLED(LED_1_PIN, HIGH);
    } else if (strcmp(scene[i], "sp2 on") == 0) {
      xSemaphoreTake(mutexLED2, portMAX_DELAY);
      toggleLED(LED_2_PIN, HIGH);
    } else if (strcmp(scene[i], "sp3 on") == 0) {
      xSemaphoreTake(mutexLED3, portMAX_DELAY);
      toggleLED(LED_3_PIN, HIGH);
    } else if (strcmp(scene[i], "sp4 on") == 0) {
      xSemaphoreTake(mutexLED4, portMAX_DELAY);
      toggleLED(LED_4_PIN, HIGH);
    } else if (strcmp(scene[i], "sp1 off") == 0) {
      toggleLED(LED_1_PIN, LOW);
      xSemaphoreGive(mutexLED1);
    } else if (strcmp(scene[i], "sp2 off") == 0) {
      toggleLED(LED_2_PIN, LOW);
      xSemaphoreGive(mutexLED2);
    } else if (strcmp(scene[i], "sp3 off") == 0) {
      toggleLED(LED_3_PIN, LOW);
      xSemaphoreGive(mutexLED3);
    } else if (strcmp(scene[i], "sp4 off") == 0) {
      toggleLED(LED_4_PIN, LOW);
      xSemaphoreGive(mutexLED4);
    } else if (strcmp(scene[i], "wait 5") == 0) {
      vTaskDelay(pdMS_TO_TICKS(5000));
    }
  }
}

/// @brief task to call the executeScene function based on received value.
/// @param pvParameters 
void sceneExecutionTask(void *pvParameters) {
  Serial.println("\nInside sceneExecutionTask");
  while(1){
    if (xSemaphoreTake(sceneExecutionSemaphore, portMAX_DELAY)){
        int sceneNumber = *((int*)pvParameters);
        const char** scene = nullptr;
        SemaphoreHandle_t sceneMutex = nullptr;
        int sceneLength = 0;

        Serial.println(sceneNumber);
        switch (sceneNumber) {
            case 1:
            scene = scene1;
            sceneMutex = mutexScene1;
            sceneLength = sizeof(scene1) / sizeof(scene1[0]);
            break;
            case 2:
            scene = scene2;
            sceneMutex = mutexScene2;
            sceneLength = sizeof(scene2) / sizeof(scene2[0]);
            break;
            case 3:
            scene = scene3;
            sceneMutex = mutexScene3;
            sceneLength = sizeof(scene3) / sizeof(scene3[3]);
            break;
            default:
            break;
        }
        
        if (scene != nullptr) {
            xSemaphoreTake(sceneMutex, portMAX_DELAY);
            executeScene(scene, sceneLength);
            xSemaphoreGive(sceneMutex);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
        xSemaphoreGive(sceneExecutionSemaphore);
    }
    vTaskDelete(NULL);
  }
}

/// @brief task to continuously read from the serial monitor
/// @param pvParameters 
void uartReaderTask(void *pvParameters) {
  char receivedChar;
  while (1) {
    if (Serial.available()) {
      receivedChar = Serial.read();
      if (isdigit(receivedChar)) {
        int sceneNumber = receivedChar - '0';
        if (sceneNumber >= 1 && sceneNumber <= 3) {
          //valid scene number received, start a new thread to execute the scene
          xTaskCreate(sceneExecutionTask, "Scene Execution Task", stackDepth, &sceneNumber, 2, NULL);
          
          //echo the received number back to my serial monitor
          Serial.println(receivedChar);
        } else {
          //invalid scene number
          Serial.println("Error: invalid scene number.");
        }
      } else {
        //invalid character received.
        Serial.println("Error: invalid character.");
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100)); 
  }
}



void loop() {

}
