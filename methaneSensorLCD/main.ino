#define MQ2pin (5)
#include <LiquidCrystal.h>

float sensorValue;
int r_led = 11;
int g_led = 10;
int b_led = 9;
const int rs = 12, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  pinMode(r_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(b_led, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);

  Serial.println("System loading");
  lcd.print("System loading");

  delay(5000);

  Serial.println("Time left: 10s");
  lcd.clear();
  lcd.print("Time left: 10s");
  delay(1500);

  Serial.println("Time left: 9s");
  lcd.clear();
  lcd.print("Time left: 9s");
  delay(1500);

  Serial.println("Time left: 8s");
  lcd.clear();
  lcd.print("Time left: 8s");
  delay(1500);

  Serial.println("Time left: 7s");
  lcd.clear();
  lcd.print("Time left: 7s");
  delay(1500);

  Serial.println("Time left: 6s");
  lcd.clear();
  lcd.print("Time left: 6s");
  delay(1500);

  Serial.println("Time left: 5s");
  lcd.clear();
  lcd.print("Time left: 5s");
  delay(1500);

  Serial.println("Time left: 4s");
  lcd.clear();
  lcd.print("Time left: 4s");
  delay(1500);

  Serial.println("Time left: 3s");
  lcd.clear();
  lcd.print("Time left: 3s");
  delay(1500);

  Serial.println("Time left: 2s");
  lcd.clear();
  lcd.print("Time left: 2s");
  delay(1500);

  Serial.println("Time left: 1s");
  lcd.clear();
  lcd.print("Time left: 1s");
  delay(1500);

  Serial.println("Done!");
  lcd.clear();
  lcd.print("Done!");

  delay(3000);
}

void loop()
{

  sensorValue = analogRead(MQ2pin);

  lcd.setCursor(0, 0);

  Serial.print("Hodnota: ");
  Serial.print(sensorValue);

  if (sensorValue < 80)
  {
    ledColor(0, 255, 0); // green
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nizka hladina.");
    lcd.setCursor(0, 1);
    lcd.print("Hodnota: ");
    lcd.print(sensorValue);
  }
  else if (sensorValue > 900)
  {
    ledColor(0, 242, 242); // blue
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Senzor odpojen...");
  }
  else
  {
    ledColor(255, 0, 0); // red
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vysoka hladina!");
    lcd.setCursor(0, 1);
    lcd.print("Hodnota: ");
    lcd.print(sensorValue);
  }

  Serial.println("");
  delay(3500);
}

void ledColor(int rValue, int gValue, int bValue)
{
  analogWrite(r_led, rValue);
  analogWrite(g_led, gValue);
  analogWrite(b_led, bValue);
}
