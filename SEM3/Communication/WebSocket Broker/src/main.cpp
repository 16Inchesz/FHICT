#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsClient.h>

// WiFi credentials
const char* ssid = "Generaal de Kockstraat 1a";
const char* password = "12345678";

// WebSocket server address
const char* serverAddress = "127.0.0.1";
const uint16_t serverPort = 1880;
const char* serverPath = "/ws/challenge";

// Create a WebSocket client object
WebSocketsClient webSocket;

void onWebSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.println("Connected to WebSocket server");
      break;
    case WStype_TEXT:
      Serial.print("Received message: ");
      Serial.println((char*)payload);
      break;
    case WStype_DISCONNECTED:
      Serial.println("Disconnected from WebSocket server");
      break;
  }
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set up WebSocket event handler
  webSocket.begin(serverAddress, serverPort, serverPath);
  webSocket.onEvent(onWebSocketEvent);
}

void loop() {
  webSocket.loop();

  // Send a message to the WebSocket server
  if (webSocket.isConnected()) {
    webSocket.sendTXT("Hello from ESP32!");
    delay(5000);  // Send a message every 5 seconds
  }
}
