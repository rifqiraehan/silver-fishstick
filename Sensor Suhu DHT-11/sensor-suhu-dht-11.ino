#include <DHT.h>

#define DHTPIN 11
#define DHTTYPE DHT11

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11!");
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(2000);
  float humidity_1 = dht.readHumidity();
  float celcius_1 = dht.readTemperature();
  float fahrenheit_1 = dht.readTemperature(true);

  if(isnan(humidity_1) || isnan(celcius_1) || isnan(fahrenheit_1)) {
    Serial.println("Pembacaan sensor tidak berhasil");
    return;
  }

  float htof = dht.computeHeatIndex(fahrenheit_1, humidity_1);
  float htoc = dht.computeHeatIndex(celcius_1, humidity_1, false);

  Serial.print("Kelembaban: ");
  Serial.print(humidity_1);
  Serial.print("%\t");
  Serial.print("Suhu: ");
  Serial.print(celcius_1);
  Serial.print("°");
  Serial.print("C / ");

  Serial.print(fahrenheit_1);
  Serial.print("°");
  Serial.print("F\t");

  Serial.print("Indeks Panas: ");
  Serial.print(htof);
  Serial.print("°");
  Serial.print("F / ");
  Serial.print(htoc);
  Serial.print("°");
  Serial.print("C ");

  lcd.clear();

  lcd.setCursor(5, 0);
  lcd.print("--DHT11--");

  lcd.setCursor(0, 1);
  lcd.print("Suhu: ");

  lcd.setCursor(6, 1);
  lcd.print(celcius_1);

  lcd.setCursor(12, 1);
  lcd.print("C");

  lcd.setCursor(0, 2);
  lcd.print("Hum: ");

  lcd.setCursor(6, 2);
  lcd.print(humidity_1);

  lcd.setCursor(12, 2);
  lcd.print("%");
  
  delay(2000);

  lcd.clear();
}
