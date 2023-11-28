#define power_pin 7 //digital pin to control the power of sensor, turning it on/off when needed
#define water_sensor A5 

#define light_sensor A0

int water_level = 0; //storing the sensor value

int light_level;

void setup() {

  Serial.begin(9600);
  pinMode(power_pin, OUTPUT); //d7 pin becomes an output
  digitalWrite(power_pin, LOW); //turning the pin(sensor) off

  pinMode(light_sensor, INPUT); //optional

}

void loop() {
  //waterLevelCheck();


  lightLevelCheck();
  delay (1000); //remove for light????

  

}

//-----------------------------LIGHT-----------------------------------------------
void lightLevelCheck(){
  light_level = analogRead(light_sensor); //get the value from photocell sensor
  Serial.print("Light level is: ");
  Serial.println(light_level);

  lowLight();
  perfectLight();
  tooMuchLight();
}

void lowLight(){
  if(light_level < 400){
    Serial.print("it's too dark! :((");
  }
}

void perfectLight(){
  if (light_level >=400 && light_level < 850 ){
    Serial.print("perfect light!");
  }
}

void tooMuchLight(){
  if (light_level >= 850){
    Serial.print("too bright!!!!!!");
  }
}


//------------------------------WATER------------------------------------------------
void waterLevelCheck(){

  digitalWrite(power_pin, HIGH); //turning sensor on
  delay(10);

  water_level = analogRead(water_sensor); //get the value from the sensor
  digitalWrite(power_pin, LOW); //turning sensor off

  Serial.print("Water level is: ");
  Serial.println(water_level);

  lowWater();
  perfectWater();
  tooMuchWater();

}

void lowWater(){
  if (water_level < 130) {
    Serial.print("not enough water :((");
  }
}

void perfectWater(){
  if (water_level >= 130 && water_level < 160){
    Serial.print("that is perfect :')");
  }
}

void tooMuchWater(){
  if (water_level >= 160){
    Serial.print("too much water!!!!!!");
  }
}
