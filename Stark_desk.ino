#include <Arduino.h>

int DeskUp = 7;
int DeskDown = 6;
const int JoyX = A2;
const int JoyY = A3;
int Joy_button = 3;
int value_X = 0;
int value_Y = 0;
#define LIGHTSENSORPIN A6
bool hasRun = true;
bool test = false;

String Test = "";

void setup() {
  
Serial.begin(9600);
pinMode(DeskUp, OUTPUT);
pinMode(DeskDown, OUTPUT);
pinMode(LIGHTSENSORPIN, INPUT);

}

void loop() {
value_X = analogRead(JoyX);
value_Y = analogRead(JoyY);
Serial.print("X=");
Serial.print(value_X);
Serial.print(" Y=");
Serial.print(value_Y);
int lightValue = analogRead(LIGHTSENSORPIN); 
//Read light level (0-1023)
Serial.print("Raw Value: ");
Serial.println(lightValue);

if (Serial.available() > 0){
  Test = Serial.readStringUntil('\n');
  Test.trim();
}


if (Test == "test" && !test){
  digitalWrite(DeskUp, HIGH);
  delay(2500);
  digitalWrite(DeskUp, LOW);
  delay(2500);
  digitalWrite(DeskDown, HIGH);
  delay(2500);
  digitalWrite(DeskDown,LOW);
  delay(2500);
  test = true;
}
if (value_Y < 400){
  digitalWrite(DeskUp, HIGH); digitalWrite(DeskDown, LOW);
  }
  else if (value_Y > 710) {
  digitalWrite(DeskDown, HIGH); (DeskUp, LOW);
  }
  else {digitalWrite (DeskUp, LOW); (DeskDown, LOW);
  }


if (lightValue < 5  && hasRun){
  digitalWrite(DeskUp, HIGH);
  delay(3500);
  digitalWrite(DeskUp, LOW);
  hasRun = false; 
  }
  else if (lightValue > 15 && !hasRun){
    digitalWrite(DeskDown, HIGH);
    delay(3500);
    digitalWrite(DeskDown,LOW);
    hasRun = true; 
    }
  else {
   digitalWrite(DeskUp,LOW);(DeskDown,LOW);
      }
}

