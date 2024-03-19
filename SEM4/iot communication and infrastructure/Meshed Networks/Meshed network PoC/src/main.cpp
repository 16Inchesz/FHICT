#include <Arduino.h>
#include "painlessMesh.h"
#include "Arduino_JSON.h"
#include "DHTesp.h"

#define   MESH_PREFIX     "Mesh Research"
#define   MESH_PASSWORD   "strongpassword123"
#define   MESH_PORT       5555
#define   DHTPIN          19

//number of this node
int nodeNumber = 3;

//instances
DHTesp dht;
Scheduler userScheduler;
painlessMesh mesh;

//Functions
void sendMessage();
String GetReadings();

//Used to change the frequency to which data is being sent.
Task taskSendMessage( TASK_SECOND * 3 , TASK_FOREVER, &sendMessage );

String readings;  //used to send data to other nodes
String GetReadings(){
  JSONVar data;
  data["node"] = nodeNumber;
  data["temperature"] = dht.getTemperature();
  data["humidity"] = dht.getHumidity();
  readings = JSON.stringify(data);
  return readings;
}

void sendMessage() {
  String msg = GetReadings();
  mesh.sendBroadcast( msg );
}

/// @brief Function used to parse the received data into information.
/// @param from 
/// @param msg 
void receivedCallback( uint32_t from, String &msg) {
  Serial.printf("Received from %u msg=%s\n", from, msg.c_str());
  JSONVar data = JSON.parse(msg.c_str());
  int node = data["node"];
  double temp = data["temperature"];
  double hum = data["humidity"];
  Serial.print("Node: ");
  Serial.println(node);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");
  Serial.println();
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void setup() {
  Serial.begin(115200);

  dht.setup(DHTPIN, DHTesp::DHT22);

  mesh.setDebugMsgTypes( ERROR | STARTUP ); //set before INIT!
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask( taskSendMessage );
  taskSendMessage.enable();
}

void loop() {
  mesh.update();
}