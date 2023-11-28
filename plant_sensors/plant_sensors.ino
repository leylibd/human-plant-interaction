//---water---
#define power_pin 7 //digital pin to control the power of sensor, turning it on/off when needed
#define water_sensor A5 
int water_level = 0; //storing the sensor value

//---light---
#define light_sensor A0
int light_level;

//---ultrasonic---
const int trigPin = 11; //green
const int echoPin = 12; //blue
int distanceToHuman;
long duration; //wave travel time
bool humanIsHere = false;


//---led---
#include <LedControl.h>

const int DIN_PIN = 5;
const int CS_PIN = 4;
const int CLK_PIN = 3;

const uint64_t IMAGES[] PROGMEM = {
  0x0000000000242424,
  0x0000001800242424,
  0x0000003c00242424,
  0x0000423c00242424,
  0x0081423c00242424,
  0x8181423c00242424
};
const int IMAGES_LEN = sizeof(IMAGES)/8;


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

  sadFaceAnimation();

  //checkingForHuman();

  //waterLevelCheck();
  //delay (1000);

  //lightLevelCheck();
  //delay (1000); 

  

}

