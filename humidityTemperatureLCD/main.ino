#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
#include "LiquidCrystal.h"

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
	dht.begin();
	lcd.begin(16, 2);

	lcd.print("DHT11 sensor...");
	lcd.setCursor(0, 1);
	lcd.print("Humadity/Temperature");
}

void loop()
{
	delay(2000);
	float V = dht.readHumidity();
	float T = dht.readTemperature();

	// check if any reads failed and if exit
	if (isnan(V) || isnan(T))
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("ERROR");
		return;
	}

	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Temperature: ");
	lcd.print(T);
	lcd.print((char)223);
	lcd.print("C");
	lcd.setCursor(0, 1);
	lcd.print("Humadity:  ");
	lcd.print(V);
	lcd.print("%");
}