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
  humanIsHere = false;//not

  distanceSensorOn();

  if (distanceToHuman < 80){
    humanIsHere = true;
    Serial.print("human is here!! distance: ");
    Serial.println(distanceToHuman);
  }
  else{
    Serial.println("not here ");
  }

}

void distanceSensorOff() {

  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
}