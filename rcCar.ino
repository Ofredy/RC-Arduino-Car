#include <SoftwareSerial.h>
#include <SoftwareSerial.h> 
#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *FL = AFMS.getMotor(2);
Adafruit_DCMotor *FR = AFMS.getMotor(1);
Adafruit_DCMotor *BL = AFMS.getMotor(3);
Adafruit_DCMotor *BR = AFMS.getMotor(4);

SoftwareSerial blue(2,3);

void setup() {
  AFMS.begin();
  Serial.begin(9600);
  blue.begin(9600);
    
}

void loop() {
  
  FL->setSpeed(255);
  FR->setSpeed(255);
  BL->setSpeed(255);
  BR->setSpeed(255);
  
  int dir;
  
  while( blue.available() ){ 
    dir = blue.read();
  }

      if(dir == 70){
        FL->run(FORWARD);
        FR->run(BACKWARD);
        BL->run(FORWARD);
        BR->run(BACKWARD);
      }
      if(dir == 66){
        FL->run(RELEASE);
        FR->run(RELEASE);
        BL->run(RELEASE);
        BR->run(RELEASE);
      }
      if(dir == 76){
        FL->run(RELEASE);
        FR->run(BACKWARD);
        BL->run(RELEASE);
        BR->run(BACKWARD);
      }
      if(dir == 82){
        FL->run(FORWARD);
        FR->run(RELEASE);
        BL->run(FORWARD);
        BR->run(RELEASE);
      }  
      
}
