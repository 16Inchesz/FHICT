#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "network id";
const char* password = "network password";
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;
const char* mqttTopic = "nr_workshop_greetings";  //topic to subscribe to
const char* mqttClientId = "ESP32Client";

WiFiClient espClient;
PubSubClient client(espClient);

//fucntion to connect to the wifi.
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//fucntion to connect/reconnect to mqtt.
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(mqttClientId)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();

  //publish a message to the MQTT topic
  String message = "Hello from ESP32!";
  client.publish(mqttTopic, message.c_str());

  //publish every 10 seconds, see screenshot in document.
  delay(10000);
}

