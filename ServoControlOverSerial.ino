/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myServo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int armaturePositionMatrix[] = {700, 1200, 1500, 2000, 2300};

void setup() 
{ 
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
//For the Arduino

void loop() 
{ 
  char byteRead;
  if (Serial.available()){
    byteRead = Serial.read();
    //byteRead=byteRead-'0';
  }
  
  if (byteRead > 0){
    
    switch(byteRead){
       case '2' :
       {
         myServo.writeMicroseconds (armaturePositionMatrix[0]);
         delay(200);
         break;
       }
       case '4' :
       {
         myServo.writeMicroseconds (armaturePositionMatrix[4]);
         delay(200);
         break;
       }
     }          
  }
} 
