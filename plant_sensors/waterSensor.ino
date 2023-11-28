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
