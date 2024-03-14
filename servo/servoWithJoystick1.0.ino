#include <Servo.h>

Servo rotor;
int servoPin = 3;
int joyXPin = 4;
int joyFunctionPin = 3;

int rotX, rotXConverted, joyFunction = 0;

void setup() {
  rotor.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  joyFunction = analogRead(joyFunctionPin);

  if(joyFunction == 0){
    rotor.write(0);
      delay(1000);
    rotor.write(45);
      delay(1000);
    rotor.write(90);
      delay(1000);
    rotor.write(135);
      delay(1000);
    rotor.write(180);
      delay(1000);
  }

  rotX = analogRead(joyXPin);
    Serial.print(rotX);
    Serial.println();

  rotXConverted = map(rotX, 0, 1023, 0,160);  
  rotor.write(rotXConverted);

  delay(100);
}
