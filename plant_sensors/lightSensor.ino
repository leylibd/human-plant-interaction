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

