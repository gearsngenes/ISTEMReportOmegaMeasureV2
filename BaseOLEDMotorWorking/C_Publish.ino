void publishRPS(){
  unsigned long deltaT = millis() - curtime;
    
    Serial.print("no of rotations:"); Serial.print(count); Serial.print(" detaT: "); Serial.println(deltaT);
    
    rps = (count * 1000.0) / (deltaT);  //Divide number of revolutions by change in time, the 1000 is there to convert from milliseconds to seconds
    omega = rps *3.14159*2;             //convert RPS to Omega by multiplying by 2pi
    
    //Publish data to the computer and to the OLED
    Serial.print("RPS: "); Serial.println(rps);
    Serial.print("Omg.: "); Serial.println(omega);
    oledPrint();
    
    Reset the count and start over
    count = 0;
}

