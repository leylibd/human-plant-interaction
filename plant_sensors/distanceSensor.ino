void distanceSensorOn(){
  //clearing the trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //turning trigger on
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceToHuman = duration * 0.0343 / 2;

  

}

void checkingForHuman(){

  distanceSensorOn();

  if (distanceToHuman < 55){
    Serial.print("human is here!! distance: ");
    Serial.println(distanceToHuman);
    humanIsHere == true;
  }
  else{
    Serial.print("not here ");
  }

}

void distanceSensorOff() {

  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
}