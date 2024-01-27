#include <DHT.h>

#define DHTPIN 2  //temperature and humadity sensor pin
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define gasSensorPin 0//gas sensor

#define littleRGBr 6
#define littleRGBg 5
#define littleRGBb 3

#define largeRGBr 9
#define largeRGBg 10
#define largeRGBb 11

float gasValue;
float tempValue;
float humValue;

void setup() {
  pinMode(littleRGBr, OUTPUT);
  pinMode(littleRGBg, OUTPUT);
  pinMode(littleRGBb, OUTPUT);

  pinMode(largeRGBr, OUTPUT);
  pinMode(largeRGBg, OUTPUT);
  pinMode(largeRGBb, OUTPUT);

  Serial.begin(115200);

  Serial.println("");
  Serial.println("Warming up...");

  delay(10000);

  Serial.println("Done!");
}

void loop() {
  gasValue = analogRead(gasSensorPin);
  tempValue = dht.readTemperature();
  humValue = dht.readHumidity();

  Serial.print("Gas value: ");
	Serial.println(gasValue);
  Serial.print("Temperature value: ");
	Serial.println(tempValue);
  Serial.print("Humadity value: ");
	Serial.println(humValue);
  Serial.println("---------------------------");
  delay(3000);
}