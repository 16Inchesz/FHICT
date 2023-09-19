#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsClient.h>

//wiFi credentials
const char* ssid = "Generaal de Kockstraat 1a";
const char* password = "12345678";

//webSocket server address
const char* serverAddress = "127.0.0.1";
const uint16_t serverPort = 1880;
const char* serverPath = "/ws/challenge";

//create a WebSocket client object
WebSocketsClient webSocket;

//function to keep track if the server is alive and receive messages.
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

  //connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  //set up WebSocket event handler
  webSocket.begin(serverAddress, serverPort, serverPath);
  webSocket.onEvent(onWebSocketEvent);
}

void loop() {
  webSocket.loop();

  //send a message to the WebSocket server
  if (webSocket.isConnected()) {
    webSocket.sendTXT("Hello from ESP32!");
    delay(5000);  //send a message every 5 seconds
  }
}
