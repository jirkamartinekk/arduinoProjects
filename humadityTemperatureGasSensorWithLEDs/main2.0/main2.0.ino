#define gasSensorPin 0 // gas sensor

#define RGB_red 6 // RGB LEDs pins
#define RGB_green 5
#define RGB_blue 3

float gasValue; // variable to save data from the sensor

void setup()
{
  pinMode(RGB_red, OUTPUT); // set RGB LEDs as a output
  pinMode(RGB_green, OUTPUT);
  pinMode(RGB_blue, OUTPUT);

  Serial.begin(115200);

  Serial.println("");
  Serial.println("Warming up...");

  delay(10000); // sensor needs some time to warm up

  Serial.println("Done!");
}

void loop()
{
  gasValue = analogRead(gasSensorPin);

  if(gasValue <= 32){
    analogWrite(RGB_red, 7);
    analogWrite(RGB_green, 247);
    analogWrite(RGB_blue, 2);
  }else if(gasValue <= 35){
    analogWrite(RGB_red, 25);
    analogWrite(RGB_green, 153);
    analogWrite(RGB_blue, 0);
  }else{
    analogWrite(RGB_red, 247);
    analogWrite(RGB_green, 2);
    analogWrite(RGB_blue, 2);
  }

  Serial.print("Gas value: ");
  Serial.println(gasValue);
  Serial.println("---------------------------");
  delay(3000);
}