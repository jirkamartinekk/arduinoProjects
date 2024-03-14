#include <Servo.h>

Servo rotor;
int servoPin = 3;
int joyXPin = 1;
int joyPressPin = 0;

int joyX, joyXConverted, joyPress, pressActive = 0;

void setup() {
  rotor.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  joyPress = analogRead(joyPressPin);

  if(joyPress == 0 && pressActive == 0){
    pressActive = 1;
  }else{
    pressActive = 0;
  }

  if(pressActive == 1){
    Serial.println("Active");
    joyX = analogRead(joyXPin);
    joyXConverted = map(joyX, 0, 1023, 0,160);  
    rotor.write(joyXConverted);
  }

  Serial.println(joyXConverted);
  Serial.println(joyPress);

  delay(100);
}