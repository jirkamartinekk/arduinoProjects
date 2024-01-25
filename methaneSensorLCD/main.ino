#define MQ2pin (5)
#include <LiquidCrystal.h>

float sensorValue;
int r_led = 11;
int g_led = 10;
int b_led = 9;
const int rs = 12, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(r_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(b_led, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);

  Serial.println("Nacitani systemu");
  lcd.print("Nacitani systemu");

  delay(5000);

  Serial.println("Spusteni za: 10s");
  lcd.clear();
  lcd.print("Spusteni za: 10s");
  delay(1500);


  Serial.println("Spusteni za: 9s");
  lcd.clear();
  lcd.print("Spusteni za: 9s");
  delay(1500);


  Serial.println("Spusteni za: 8s");
  lcd.clear();
  lcd.print("Spusteni za: 8s");
  delay(1500);


  Serial.println("Spusteni za: 7s");
  lcd.clear();
  lcd.print("Spusteni za: 7s");
  delay(1500);


  Serial.println("Spusteni za: 6s");
  lcd.clear();
  lcd.print("Spusteni za: 6s");
  delay(1500);


  Serial.println("Spusteni za: 5s");
  lcd.clear();
  lcd.print("Spusteni za: 5s");
  delay(1500);

  Serial.println("Spusteni za: 4s");
  lcd.clear();
  lcd.print("Spusteni za: 4s");
  delay(1500);

  Serial.println("Spusteni za: 3s");
  lcd.clear();
  lcd.print("Spusteni za: 3s");
  delay(1500);

  Serial.println("Spusteni za: 2s");
  lcd.clear();
  lcd.print("Spusteni za: 2s");
  delay(1500);

  Serial.println("Spusteni za: 1s");
  lcd.clear();
  lcd.print("Spusteni za: 1s");
  delay(1500);

  Serial.println("Sensor aktivni!");
  lcd.clear();
  lcd.print("Sensor aktivni!");

  delay(3000);
}

void loop() {

  sensorValue = analogRead(MQ2pin);

  lcd.setCursor(0, 0);

  Serial.print("Hodnota: ");
  Serial.print(sensorValue);

  if (sensorValue < 80) {
    ledColor(0, 255, 0);  // zelena
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nizka hladina.");
    lcd.setCursor(0, 1);
    lcd.print("Hodnota: ");
    lcd.print(sensorValue);
  } else if (sensorValue > 900) {
    ledColor(0, 242, 242);  // modra
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Senzor odpojen...");
  } else {
    ledColor(255, 0, 0);  // cervena
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vysoka hladina!");
    lcd.setCursor(0, 1);
    lcd.print("Hodnota: ");
    lcd.print(sensorValue);
  }

  Serial.println("");
  delay(3500);  // hodnota do dalsiho cteni
}

void ledColor(int rValue, int gValue, int bValue) {
  analogWrite(r_led, rValue);
  analogWrite(g_led, gValue);
  analogWrite(b_led, bValue);
}
