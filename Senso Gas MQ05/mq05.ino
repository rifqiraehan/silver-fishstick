#define sensorPin A4
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.println(" Sensor Gas ");
  lcd.clear();
}

void loop() {
  int readSensor = analogRead(sensorPin);
  lcd.print("Analog output: ");
  lcd.println(readSensor);
  
  Serial.print("Analog output: ");
  Serial.println(readSensor);
  lcd.setCursor(1, 0);
  delay(1000);
  lcd.clear();
}