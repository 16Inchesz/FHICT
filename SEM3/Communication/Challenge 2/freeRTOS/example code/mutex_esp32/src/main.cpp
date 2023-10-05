#include <Arduino.h>

// Arduino
// #include <Arduino_FreeRTOS.h>
// #include <semphr.h>
//const uint16_t stackDepth = 128;

// ESP32
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
const uint32_t stackDepth = 1052;

void Task1(void *pvParameters);
void Task2(void *pvParameters);

SemaphoreHandle_t mutex_v;
void setup()
{
  Serial.begin(115200);
  mutex_v = xSemaphoreCreateMutex();
  if (mutex_v == NULL)
  {
    Serial.println("Mutex can not be created");
  }
  const char *pcTask1 = " -- Task1 param-- ";
  xTaskCreate(Task1, "Task1", stackDepth, (void *)pcTask1, 1, NULL);
  xTaskCreate(Task2, "Task2", stackDepth, NULL, 1, NULL);
}

void Task1(void *pvParameters)
{
  while (1)
  {
    char *pcTaskParam;
    pcTaskParam = (char *)pvParameters;
    if (xSemaphoreTake(mutex_v, portMAX_DELAY))
    {
      for (int i = 0; i < 1000; i++)
      {
        Serial.print(1);
      }
      Serial.println("\nHi from Task1: ");
      Serial.print(pcTaskParam);
      xSemaphoreGive(mutex_v);
    }

    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void Task2(void *pvParameters)
{
  while (1)
  {
    if (xSemaphoreTake(mutex_v, portMAX_DELAY))
    {
      for (int i = 0; i < 1000; i++)
      {
        Serial.print(2);
      }
      Serial.print("\nHi from Task2: ");
      xSemaphoreGive(mutex_v);
      vTaskDelay(pdMS_TO_TICKS(77));
    }
  }
}

void loop()
{
}