#include <Servo.h>

Servo motor;
int rotation = 1;

void setup() {
  motor.attach(3);
}

void loop() {
    motor.write(0);
  delay(1000);
    motor.write(90);
  delay(5000);
}
