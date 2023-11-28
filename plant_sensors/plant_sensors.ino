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

void setup() {

  Serial.begin(9600);
  pinMode(power_pin, OUTPUT); //d7 pin becomes an output
  digitalWrite(power_pin, LOW); //turning the pin(sensor) off

  pinMode(light_sensor, INPUT); //optional??

  //---ultrasonic---
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop() {

  checkingForHuman();

  //waterLevelCheck();
  //delay (1000);

  //lightLevelCheck();
  delay (1000); 

  

}

