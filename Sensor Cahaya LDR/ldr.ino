#include "Wire.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int analogSensorReading = analogRead(A0);
  bool digitalSensorReading = analogRead(2);

  Serial.print("Analog Reading: ");
  Serial.println(analogSensorReading);
  Serial.print("Digital Reading: ");
  Serial.println(digitalSensorReading);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Analog: ");
  lcd.print(analogSensorReading);
  lcd.setCursor(0, 1);
  lcd.print("Digital: ");
  lcd.print(digitalSensorReading);

  delay(1000);
}
