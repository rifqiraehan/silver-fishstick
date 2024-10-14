#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
float val;
int tempPin = A1;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float val = analogRead(tempPin);
  float mv = (val/1024.0)*5;
  float cel = mv*100;
  float farh = (cel*9)/5 + 32;
  Serial.print("Temperature: ");
  Serial.print(cel);
  Serial.println("Fahrenheit");
  Serial.print(farh);

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Temperature: ");
  lcd.print(cel);

  lcd.setCursor(0, 0);
  lcd.print("Fahrenheit: ");
  lcd.print(farh);
  delay(1000);

}