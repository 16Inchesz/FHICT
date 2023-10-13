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

//define mutexes for LEDs
SemaphoreHandle_t mutexLED1;
SemaphoreHandle_t mutexLED2;
SemaphoreHandle_t mutexLED3;
SemaphoreHandle_t mutexLED4;

//define mutexes for scenes
SemaphoreHandle_t mutexScene1;
SemaphoreHandle_t mutexScene2;
SemaphoreHandle_t mutexScene3;

//define a queue for scenes
QueueHandle_t scene1Queue;
QueueHandle_t scene2Queue;
QueueHandle_t scene3Queue;

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

  mutexLED1 = xSemaphoreCreateMutex();
  mutexLED2 = xSemaphoreCreateMutex();
  mutexLED3 = xSemaphoreCreateMutex();
  mutexLED4 = xSemaphoreCreateMutex();

  mutexScene1 = xSemaphoreCreateMutex();
  mutexScene2 = xSemaphoreCreateMutex();
  mutexScene3 = xSemaphoreCreateMutex();

  scene1Queue = xQueueCreate(10, sizeof(const char*));
  scene2Queue = xQueueCreate(10, sizeof(const char*));
  scene3Queue = xQueueCreate(10, sizeof(const char*));

  if ((mutexLED1 == NULL) || (mutexLED2 == NULL) || (mutexLED3 == NULL) || (mutexLED4 == NULL) ||
      (mutexScene1 == NULL) || (mutexScene2 == NULL) || (mutexScene3 == NULL)) {
    Serial.println("Mutex couldn't be created");
  }

  if ((scene1Queue == NULL) || (scene2Queue == NULL) || (scene3Queue == NULL)) {
    Serial.println("Queue couldn't be created");
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
  while(1){
    int sceneNumber = *((int*)pvParameters);
    const char** sceneSteps = nullptr;
    QueueHandle_t sceneQueue = nullptr;
    int sceneLength = 0;
    SemaphoreHandle_t sceneMutex = nullptr;

    switch (sceneNumber) {
        case 1:
          sceneQueue = scene1Queue;
          sceneMutex = mutexScene1;
          break;
        case 2:
          sceneQueue = scene2Queue;
          sceneMutex = mutexScene2;
          break;
        case 3:
          sceneQueue = scene3Queue;
          sceneMutex = mutexScene3;
          break;
        default:
          break;
    }

    if (sceneQueue != nullptr) {
      //receive scene steps from the queue
      xQueueReceive(sceneQueue, &sceneSteps, portMAX_DELAY);
      sceneLength = sizeof(scene1) / sizeof(scene1[0]);

      //execute scene steps
      if (sceneSteps != nullptr) {
        xSemaphoreTake(sceneMutex, portMAX_DELAY);
        executeScene(sceneSteps, sceneLength);
        xSemaphoreGive(sceneMutex);
      }
    }

    vTaskDelay(pdMS_TO_TICKS(100));
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
          const char** sceneSteps = nullptr;
          switch (sceneNumber) {
            case 1:
              sceneSteps = scene1;
              break;
            case 2:
              sceneSteps = scene2;
              break;
            case 3:
              sceneSteps = scene3;
              break;
            default:
              break;
          }

          if (sceneSteps != nullptr) {
            //s scene steps to the appropriate queue
            switch (sceneNumber) {
              case 1:
                xQueueSend(scene1Queue, &sceneSteps, portMAX_DELAY);
                break;
              case 2:
                xQueueSend(scene2Queue, &sceneSteps, portMAX_DELAY);
                break;
              case 3:
                xQueueSend(scene3Queue, &sceneSteps, portMAX_DELAY);
                break;
              default:
                break;
            }
            
            //create a new thread to execute the scene
            xTaskCreate(sceneExecutionTask, "Scene Execution Task", stackDepth, &sceneNumber, 2, NULL);
            //echo the received number back to the serial monitor
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
    }
    vTaskDelay(pdMS_TO_TICKS(100)); 
  }
}



void loop() {

}
