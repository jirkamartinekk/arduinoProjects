#include <HCSR04.h> // ultrasonicSensor library (HCSR04-ultrasonic-sensor-lib-2.0.2.zip) must be installed

#define greenLight (6) // 6 is just a port, you can change it
#define yellowLight (5)
#define redLight (3)

HCSR04 hc(11, 10); // declare the echo and trig ports

int distance;

void setup()
{
  pinMode(greenLight, OUTPUT); // set the defined ports as a OUTPUT or INPUT
  pinMode(yellowLight, OUTPUT);
  pinMode(redLight, OUTPUT);

  Serial.begin(9600); // begin printing to the console
}

void loop()
{

  distance = hc.dist(); // save the output from the sensor as a distance variable

  if (distance == 0) // change the number of distance for different colors
  {
    digitalWrite(greenLight, HIGH); // high = active, low = inactive
    digitalWrite(yellowLight, HIGH);
    digitalWrite(redLight, HIGH);
  }
  else if (distance <= 25)
  {
    digitalWrite(greenLight, HIGH);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, LOW);
  }
  else if (distance < 50)
  {
    digitalWrite(yellowLight, HIGH);
    digitalWrite(greenLight, LOW);
    digitalWrite(redLight, LOW);
  }
  else
  {
    digitalWrite(redLight, HIGH);
    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, LOW);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  delay(500);
}