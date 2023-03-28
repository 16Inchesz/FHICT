#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <FastLED.h>
using namespace std;

#define FANPIN 3
#define LED_PIN 5
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define SEALEVELPRESSURE_HPA (1013.25)

unsigned long current_time = 0;
unsigned long previous_time = 0;
const float UPPER_TEMP = 24.5;
const float LOWER_TEMP = 23.5;

const int NUM_LEDS = 60;
const int BRIGHTNESS = 64;
 
CRGB leds[NUM_LEDS];

byte degree[8] =
    {
        0b00011,
        0b00011,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000};

//fansystem ------------------------------------------------------------------------------------------------------------------------
Adafruit_BME280 bme;

byte fanduty = 0;
void setFanSpeed(byte speed){
  // Determine the fan duty value.
  fanduty = map(speed, 0, 100, 0, 255);
  // Continues speed.
  analogWrite(FANPIN, fanduty);
}

void swingFan(){
  // Swing the fan.
  analogWrite(FANPIN, 255);
  delay(45);
  // Continues speed.
  analogWrite(FANPIN, fanduty);
}

float temperature = 0;
float humidity = 0;
const int BME_INTERVAL = 2000;
void bmeValues(){
  if ((current_time - previous_time) > BME_INTERVAL)
  {
    temperature = bme.readTemperature(); // read temperature for fan
    //Serial.print("Temperature = ");
    //Serial.print(temperature);
    //Serial.println("*C");

    humidity = bme.readHumidity();
    //Serial.print("Humidity = ");
    //Serial.print(humidity);
    //Serial.println("%");

    //Serial.print("Pressure = ");
    //Serial.print(bme.readPressure() / 100.0F);
    //Serial.println("hPa");

    //Serial.print("Approx. Altitude = ");
    //Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    //Serial.println("m");

    //Serial.println();
    previous_time = current_time;
  }
}

void tempsystem_init(){
  pinMode(FANPIN, OUTPUT);
  if (!bme.begin(0x76))
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

bool isFanOn = false;
void tempSystem(){
  if (temperature >= UPPER_TEMP){
    if (isFanOn == false){
      setFanSpeed(90);
      swingFan();
      isFanOn = true;
    }
  } 
  if (temperature <= LOWER_TEMP){
    if (isFanOn == true){
      setFanSpeed(0);
      swingFan();
      isFanOn = false;
    }
  }
}
//------------------------------------------------------------------------------------------------------------------------------------

//lightsystem ------------------------------------------------------------------------------------------------------------------------

//Motion sensor
const int motionPin = 7;
float motionValue = 0;
bool motionState = false; // We start with no motion detected.
int time;

//Ledstrip
int ledStripBrightness;

//millis
unsigned long brightnessHandlerTimer;
unsigned int intervalBrightness = 500;
unsigned long morningEveningTimer;
unsigned int timerInterval = 100;

struct buttonPressed
{
  int pin;
  int buttonState;
  int LastButtonState;
  unsigned long ButtonDebounceTime;
};

struct buttonPressed lightButton;
struct buttonPressed smartButton;

bool lightOnOff = true;
bool smartOnOff = true;
bool guiControl = false;
int brightnessGui;

//Potentiometers
const int TIME_OF_DAY_POTENTIOMETER = A0;
const int BRIGHTNESS_POTENTIOMETER = A1;

//Light sensor
const int LDR_PIN = A2;

enum dayState 
{
  MORNING,
  EVENING
};

dayState guiTimeOfDay;

int counter(int motionValue)
{
  if(motionValue == HIGH)
  {
    time = 500;
  }
  if(time != 0)
  {
    time--;
  }
  return time;
}

bool motionDetection()
{
  bool motionLightsOnOff;
    // If there is still time left, do the following:
  if (counter(digitalRead(motionPin)) != 0) {
    // Change the motion state to true (motion detected):
    motionLightsOnOff = true;
    if (motionState == false) {
      motionState = true;
    }
  }
  // If no motion is detected (motionPin = LOW), do the following:
  else {
    // Change the motion state to false (no motion):
    motionLightsOnOff = false;
    if (motionState == true) {
      motionState = false;
    }
  }
  return motionLightsOnOff;
}

int previousBrightness;
void brightnessHandler(int mappedBrightness)
{
  if(millis() - brightnessHandlerTimer > intervalBrightness)
  {
    brightnessHandlerTimer = millis();
    if(mappedBrightness != previousBrightness){
      previousBrightness = mappedBrightness;
      if(mappedBrightness <= 3){ledStripBrightness = 0;}
      else if(mappedBrightness <= 25){ledStripBrightness = 13;}
      else if(mappedBrightness <= 50){ledStripBrightness = 25;}
      else{ledStripBrightness = 30;}
    }
  }
}

struct buttonPressed createButton(int pin)
{
  struct buttonPressed button;
  button.pin = pin;
  button.buttonState = LOW;
  button.LastButtonState = LOW;
  button.ButtonDebounceTime = 0;
  pinMode(button.pin, INPUT);
  return button;
}

struct buttonPressed pressedLight(struct buttonPressed button)
{
  if (millis() - button.ButtonDebounceTime > 40) 
  {
    button.ButtonDebounceTime = millis(); // Reset timer for button.
    button.buttonState = digitalRead(button.pin); // Read button.

    if (button.buttonState != button.LastButtonState)// Edge detection.
    { 
      if (button.buttonState == LOW) { // Button seems to be pressed.
        // do something when button is pressed.
        lightOnOff = !lightOnOff;
      }
      button.LastButtonState = button.buttonState; // Keep last button state.
    }
  }
  return button;
}

struct buttonPressed pressedSmart(struct buttonPressed button)
{
  if (millis() - button.ButtonDebounceTime > 40) 
  {
    button.ButtonDebounceTime = millis(); // Reset timer for button.
    button.buttonState = digitalRead(button.pin); // Read button.

    if (button.buttonState != button.LastButtonState)// Edge detection.
    { 
      if (button.buttonState == LOW) { // Button seems to be pressed.
        // do something when button is pressed.
        smartOnOff = !smartOnOff;
      }
      button.LastButtonState = button.buttonState; // Keep last button state.
    }
  }
  return button;
}
enum dayState timeOfDay = MORNING;
enum dayState morning_evening()
{
  if(millis() - morningEveningTimer > timerInterval)
  {
    morningEveningTimer = millis();
    
    int timeDay = analogRead(TIME_OF_DAY_POTENTIOMETER);
    byte mappedTime = map(timeDay, 0, 1023, 0, 25);
    if(mappedTime > 12 && mappedTime > 11)
    {
      timeOfDay = EVENING;
    }
    else
    {
      timeOfDay = MORNING;
    }
  }
  return timeOfDay;
}

void colourForTimeOfDay(dayState timeOfDay)
{
  FastLED.setBrightness(ledStripBrightness);
  switch (timeOfDay)
  {
  case MORNING:
    for(int i =0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::AliceBlue;
    }
    FastLED.show();
    break;
  case EVENING:
    for(int i =0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::OrangeRed;
    }
    FastLED.show();
    break;
  default:
    break;
  }
}



  dayState currentState;
void smartHandler(){
  if(smartOnOff){
    if(motionDetection() == true && lightOnOff == true){  
      currentState = morning_evening();
      int mappedBrightness = map(analogRead(LDR_PIN), 0, 1023, 50, 0);
      brightnessHandler(mappedBrightness);
    }
    else{ 
      brightnessHandler(0);
    }
  }
  else if(guiControl){
    if(lightOnOff == true){
      brightnessHandler(brightnessGui);
      currentState = guiTimeOfDay;
      //colourForTimeOfDay(guiTimeOfDay);
    }
  }
  else if(lightOnOff){
    currentState = morning_evening();
    int mappedBrightness = map(analogRead(BRIGHTNESS_POTENTIOMETER), 0, 1023, 0, 60);
    brightnessHandler(mappedBrightness);
  }
  else{
    brightnessHandler(0);
  }
}

void lightsystem_init(){
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);//uses the array now set to NUM_LEDS with RGB
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);//Prevents the leds from drawing to much power
  FastLED.clear();//clears the LED strip for new code
  FastLED.show();//Allows to show the new code

  lightButton = createButton(2);
  smartButton = createButton(4);

  pinMode(LDR_PIN, INPUT);
  pinMode(TIME_OF_DAY_POTENTIOMETER, INPUT);
  pinMode(BRIGHTNESS_POTENTIOMETER, INPUT);
}

void lightsystem(){
  colourForTimeOfDay(currentState);
  lightButton = pressedLight(lightButton);
  smartButton = pressedSmart(smartButton);
  motionDetection();
  smartHandler();
}
//------------------------------------------------------------------------------------------------------------------------------------

//alarmsystem ------------------------------------------------------------------------------------------------------------------------

const int PIN_REDLED = 12;
const int PIN_GREENLED = 11;
const int PIN_BUZZER = 8;
const int PIN_BTN = 6;
const int PIN_POT = A4;
const int SMOKE_DETECTOR = A3;
int lastButtonState = HIGH;
int mode = 0;
int icounter = 0;
bool alarmToggle;

//Threshold value
const int sensorThresh = 400;

//Array filled with sensors lasts measurements
const int arrayLenght = 8;
int samples[arrayLenght];

void alarmOn(){
  digitalWrite(PIN_REDLED, HIGH);
  digitalWrite(PIN_GREENLED, LOW);
  alarmToggle = true;
  for (int i = 0; i < 80; i++) 
    {
      digitalWrite (PIN_BUZZER, HIGH) ;
      delay (1) ;
      digitalWrite (PIN_BUZZER, LOW) ;
      delay (1) ;
    }
}

void alarmOff(){
  alarmToggle = false;      
  digitalWrite(PIN_REDLED, LOW);
  digitalWrite(PIN_GREENLED, HIGH);
  digitalWrite(PIN_BUZZER, LOW);
}

void buttonPressedSelectMode(){
  int buttonState = digitalRead(PIN_BTN);
  bool buttonPressed = ((lastButtonState==LOW) && (buttonState==HIGH));
  if(buttonPressed)
  {
    mode++;
    if (mode > 1) 
    {
      mode = 0; // begin state
    }
  }
  lastButtonState=buttonState;
}

float GetAVG(int value){
  samples[icounter] = value;
  icounter = (icounter + 1) % arrayLenght;
  int sum=0;
  for(int i=0;i<arrayLenght;i++)
  {
      sum+=samples[i];
  }
  float tempSum = sum;
  float avgValue = tempSum/arrayLenght;
  return avgValue;
}

void modeRun(){
  int newValue;
  if (mode==0) {
    newValue = analogRead(PIN_POT);
  }else{
    newValue = analogRead(SMOKE_DETECTOR);
  }
  float avgValue = GetAVG(newValue);
  //Serial.print("Sensor1 value: ");
  //Serial.println(avgValue);
  if (avgValue > sensorThresh) {
    alarmOn();
  }else {
    alarmOff();
  }
}

void alarmsystem_init(){
  pinMode(PIN_REDLED, OUTPUT);
  pinMode(PIN_GREENLED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_POT, INPUT);
  pinMode(SMOKE_DETECTOR,INPUT);
}

void alarmsystem(){
  buttonPressedSelectMode();
  modeRun();
}

//------------------------------------------------------------------------------------------------------------------------------------
struct Data{
  int smartSwitch;
  int lightSwitch;
  int brightness;
};
struct Data data;

unsigned long sendTimer = 0;
void connectionHandlerSend(double temperature, double humidity, bool fan, bool alarm, bool smartOnOff){
  if(millis() - sendTimer > 500){
    sendTimer = millis();
    Serial.println(String(temperature) + "#" + String(humidity) + "#" + String(!fan) + "#" + String(alarm) + "#" + String(smartOnOff) + "#" + String(lightOnOff) + "#");
  }
}

void connectionHandlerRecieve(){
  if(Serial.available())
  {
    String input;
    input = Serial.readStringUntil('\n');
    input.trim();
    if(input == "smartOn/Off"){smartOnOff = !smartOnOff;}
    else if(input == "lightsOn/Off"){lightOnOff = !lightOnOff;}
    else if(input == "guiControlOn/Off"){guiControl = !guiControl;}
    else if(input == "guiControlOff"){guiControl = false;}
    else if(input == "MORNING"){guiTimeOfDay = MORNING;}
    else if(input == "EVENING"){guiTimeOfDay = EVENING;}  
    else{
      brightnessGui = input.toInt();
    }
  }
}

void setup()
{
  Serial.begin(9600);
  tempsystem_init();
  lightsystem_init();
  alarmsystem_init();
}

void loop(){
  //Serial.println(String(morning_evening()));
  //Serial.println(smartOnOff);

  current_time = millis();
  connectionHandlerSend(temperature, humidity, isFanOn, alarmToggle, smartOnOff);
  connectionHandlerRecieve();
  bmeValues();
  tempSystem();
  lightsystem();
  alarmsystem();
} 