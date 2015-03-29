//For Arduino to interface with Myo
//Adopted from JakeChapeskie

#include <MyoController.h>
#include <Servo.h>

#define FIST_PIN 4
#define WAVEIN_PIN 5
#define WAVEOUT_PIN 6
#define FINGERSSPREAD_PIN 7
#define DOUBLETAP_PIN 8

MyoController myo = MyoController();
Servo myServo;

int armaturePositionMatrix[] = {700, 1200, 1500, 2000, 2300};

void setup() {
  
  myServo.attach(9);
  
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  Serial.begin(9600);
  
  myo.initMyo();
}

void loop()
{
   //Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN,LOW); 
      digitalWrite(WAVEIN_PIN,LOW);
      digitalWrite(WAVEOUT_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      digitalWrite(DOUBLETAP_PIN,LOW);
      break;
    case fist:
      digitalWrite(FIST_PIN,HIGH);
      Serial.println(FIST_PIN);
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH);
      Serial.println(WAVEIN_PIN);      
      myServo.writeMicroseconds(armaturePositionMatrix[4]);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH);
      Serial.println(WAVEOUT_PIN);
      myServo.writeMicroseconds(armaturePositionMatrix[0]);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      Serial.println(FINGERSSPREAD_PIN);
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH);
      Serial.println(DOUBLETAP_PIN);
      break;
   } 
   delay(100);
}
