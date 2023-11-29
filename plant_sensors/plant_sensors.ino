//---water---
#define power_pin 7 //digital pin to control the power of sensor, turning it on/off when needed
#define water_sensor A5 
int water_level = 0; //storing the sensor value

//---light---
#define light_sensor A0
int light_level;

//---ultrasonic---
const int trigPin = 11; //yellow
const int echoPin = 12; //orange
int distanceToHuman;
long duration; //wave travel time
bool humanIsHere = false;



//---led---
#include <LedControl.h>

const int DIN_PIN = 5;
const int CS_PIN = 4;
const int CLK_PIN = 3;

//sad face
const uint64_t SAD [] PROGMEM = {
  0x0000e00000e00000,
  0x0000e00808e00000,
  0x0000e80808e80000,
  0x0004e80808e80400,
  0x0204e80808e80402,
  0x0304e80808e80403
};
const int SAD_LEN = sizeof(SAD)/8;

//happy face
const uint64_t HAPPY[] PROGMEM = {
  0x0000f00000f00000,
  0x0000f00101f00000,
  0x0000f10101f10000,
  0x0002f10101f10200,
  0x0402f10101f10204,
  0x0c02f10101f1020c
};
const int HAPPY_LEN = sizeof(HAPPY)/8;

//turning off
const uint64_t OFF[] PROGMEM = {
  0xffffffffffffffff,
  0x007e7e7e7e7e7e00,
  0x00003c3c3c3c0000,
  0x0000001818000000,
  0x0000001818000000,
  0x0000000000000000
};
const int OFF_LEN = sizeof(OFF)/8;



LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);


void setup() {

  Serial.begin(9600);
  pinMode(power_pin, OUTPUT); //d7 pin becomes an output
  digitalWrite(power_pin, LOW); //turning the pin(sensor) off

  pinMode(light_sensor, INPUT); //optional??

  //---ultrasonic---
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  

  //---sad face---
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);

}

void loop() {

  //happyFaceAnimation();

  if (humanIsHere == false){
    sadFaceAnimation();
    checkingForHuman();
  }

  if (humanIsHere){
    turningOffAnimation();
  }

  //checkingForHuman();
  
  //waterLevelCheck();
  //delay (1000);

  //lightLevelCheck();
  //delay (1000); 


}

