#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
const int pingPin = 7;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Jarak Sensor");
}

void loop() {
  float duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  lcd.setCursor(0, 1);
  lcd.print("inches: ");
  lcd.print(inches);

  lcd.setCursor(0, 2);
  lcd.print("Centimeters: ");
  lcd.print(cm);
}

float microsecondsToInches( float microseconds) {
  return microseconds / 74 / 2;
}

float microsecondsToCentimeters( float microseconds) {
  return microseconds / 29 / 2;
}
