#define gasSensorPin 0 // gas sensor

#define RGBr 6 // RGB LEDs pins
#define RGBg 5
#define RGBb 3

float gasValue; // variable to save data from the sensor

void setup()
{
  pinMode(RGBr, OUTPUT); // set RGB LEDs as a output
  pinMode(RGBg, OUTPUT);
  pinMode(RGBb, OUTPUT);

  Serial.begin(115200);

  Serial.println("");
  Serial.println("Warming up...");

  delay(10000); // sensor needs some time to warm up

  Serial.println("Done!");
}

void loop()
{
  gasValue = analogRead(gasSensorPin);

  Serial.print("Gas value: ");
  Serial.println(gasValue);
  Serial.println("---------------------------");
  delay(3000);
}