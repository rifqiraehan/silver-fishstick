#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int pirPin = 8;
int pirStat = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  pirStat = digitalRead(pirPin);
  
  if (pirStat == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Ada objek");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Tidak ada objek");
  }
}
