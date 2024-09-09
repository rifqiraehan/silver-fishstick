#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int sensorMin = 0;
const int sensorMax = 1024;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int sensorReading = analogRead(A3);
  bool dReading = digitalRead(2);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  lcd.setCursor(0, 0);
  lcd.print(sensorReading);

  delay(100);

  lcd.setCursor(0, 1);
  lcd.print("");
  delay(100);

  lcd.setCursor(0, 2);
  lcd.print(dReading);
  delay(100);

  lcd.setCursor(0, 3);
  lcd.print(range);
  delay(100);

  lcd.clear();
}
