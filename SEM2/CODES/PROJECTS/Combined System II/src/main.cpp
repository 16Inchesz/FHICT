#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <FastLED.h>

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
const int BME_INTERVAL = 2000;
void bmeValues(){
  temperature = bme.readTemperature(); // read temperature for fan
  if ((current_time - previous_time) > BME_INTERVAL)
  {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println("*C");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println("%");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println("hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println("m");

    Serial.println();
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

int counter(int motionValue)
{
  if(motionValue == HIGH)
  {
    time = 5;
  }
  if(time != 0)
  {
    time--;
  }
  //Serial.println(time);
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
      Serial.println("Motion detected!");
      motionState = true;
      //Serial.println(ledStripBrightness);
    }
  }
  // If no motion is detected (motionPin = LOW), do the following:
  else {
    // Change the motion state to false (no motion):
    motionLightsOnOff = false;
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
      //Serial.println(ledStripBrightness);
    }
  }
  return motionLightsOnOff;
}


void brightnessHandler(int mappedBrightness)
{
  if(millis() - brightnessHandlerTimer > intervalBrightness)
  {
    brightnessHandlerTimer = millis();
    if(mappedBrightness <= 1){
      ledStripBrightness = 0;
    }
    if(((mappedBrightness > 1) && (mappedBrightness < 49)) || ((mappedBrightness > 1) && (mappedBrightness < 50))){
      ledStripBrightness = 25;
    }
    if(((mappedBrightness >= 50) && (mappedBrightness < 74)) || ((mappedBrightness >= 50) && (mappedBrightness < 75))){
      ledStripBrightness = 50;
    }
    if(((mappedBrightness >= 75) && (mappedBrightness <= 96)) || ((mappedBrightness >= 75) && (mappedBrightness <= 97))){
    ledStripBrightness = 75;
    }
    if(mappedBrightness >= 98){
      ledStripBrightness = 100;
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

dayState morning_evening()
{
  if(millis() - morningEveningTimer > timerInterval)
  {
    morningEveningTimer = millis();
    enum dayState timeOfDay;
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
    return timeOfDay;
  }
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

void smartHandler(){
  if(smartOnOff == true){
    if(motionDetection() == true && lightOnOff == true){
      int mappedBrightness = map(analogRead(LDR_PIN), 0, 1023, 100, 0);
      brightnessHandler(mappedBrightness);
    }
    else{ 
      brightnessHandler(0);
    }
  }
  else if(lightOnOff == true){
    int mappedBrightness = map(analogRead(BRIGHTNESS_POTENTIOMETER), 0, 1023, 0, 100);
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
  lightButton = pressedLight(lightButton);
  smartButton = pressedSmart(smartButton);
  motionDetection();
  dayState timeOfDay = morning_evening();
  colourForTimeOfDay(timeOfDay);
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

//Threshold value
const int sensorThresh = 400;

//Array filled with sensors lasts measurements
const int arrayLenght = 8;
int samples[arrayLenght];

void alarmOn(){
  digitalWrite(PIN_REDLED, HIGH);
  digitalWrite(PIN_GREENLED, LOW);
  for (int i = 0; i < 80; i++) 
    {
      digitalWrite (PIN_BUZZER, HIGH) ;
      delay (1) ;
      digitalWrite (PIN_BUZZER, LOW) ;
      delay (1) ;
    }
}

void alarmOff(){      
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

void setup()
{
  Serial.begin(9600);
  tempsystem_init();
  lightsystem_init();
  alarmsystem_init();
}

void loop(){
  current_time = millis();
  bmeValues();
  tempSystem();
  lightsystem();
  alarmsystem();
} 