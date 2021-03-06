void countRevs() {  //Counts the number of times a revolution completes
  while (count < maxcount)  //Do this as long as count is less than [x]
  {
    //-------------Important Note
    // ----- KEEP controlling the motor through the joystick, even in While Loop
    xval = analogRead(x);  
    yval = analogRead(y);          
    getSetSpeed();
    getSetDirection();
    //-------End Important note
    sensorState = digitalRead(SENSORPIN);  //Receive the IR Sensor 
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
      count++;  //if broken, count it as one revolution
    }
    lastState = sensorState;

  }



}

