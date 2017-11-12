//---------OLED Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306();

//--------------Joystick Pins and Variables
int x = A0; //X axis pin
int y = A1; //Y axis pin
int xval = 0;
int yval = 0;
int speedval = 0;

//--------------TB66 Pins; MOTOR CONTROL
int pwmB=5;  //RPM control

//BO pins control direction
int BO1=6;  //BIN1
int BO2=9;  //BIN2


#define LEDPIN 13

#define SENSORPIN 10

int count = 0;//Counter to keep track of revolutions
float rps = 0.0, omega = 0.0;

int sensorState = 0, lastState = 0;       // variable for reading the pushbutton status

const int maxcount = 5;  //Maximum number of revolutions before calculating RPS and Omega
unsigned long curtime = 0;  //Time at the start of cycle

void setup() {

  //LED is an OUTPUT
  pinMode(LEDPIN, OUTPUT);

  // IR Receiver
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH); //This forces the sensor to activate for the first time, afterwards, only digital READS

  Serial.begin(115200);  //Speed of data being sent to Serial Monitor

  //OLED setup
  oledSetup();

  //Joystick
  pinMode(x, INPUT);  //gets values from joystick
  pinMode(y, INPUT);

  pinMode(BO1, OUTPUT);  //sends values to TB66
  pinMode(BO2, OUTPUT);  //sends values to TB66
}

void loop() {
  xval = analogRead(x);  //Get the Xvalue
  yval = analogRead(y);  //Get the Yvalue
  getSetSpeed();         //Control the motor speed
  getSetDirection();     //Control the motor Direction
  //-------------------
  curtime = millis();     //RECORD the start time of the cycle (milliseconds)
  countRevs();            //Count [max] revolutions
  
   if (count == maxcount)  //when [x] revolutions complete, calculate the average RPS and omega
    {
      publishRPS();
    }
}

