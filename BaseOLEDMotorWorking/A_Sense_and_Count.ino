void countRevs() {
  while (count < maxcount)
  {
    xval = analogRead(x);
    yval = analogRead(y);
    getSetSpeed();
    getSetDirection();

    sensorState = digitalRead(SENSORPIN);
    if (sensorState == LOW) {
      // turn LED on:
      digitalWrite(LEDPIN, HIGH);
    }
    else {
      // turn LED off:
      digitalWrite(LEDPIN, LOW);
    }

    if (sensorState && !lastState) {
      //  Serial.println("Unbroken");
    }
    if (!sensorState && lastState) {
      //  Serial.println("Broken");
      count++;
    }
    lastState = sensorState;

  }



}

