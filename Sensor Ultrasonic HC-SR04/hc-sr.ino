#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int trigPin = 9;
const int echoPin = 10;

double duration;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(20, 4);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance - duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  lcd.clear()
  lcd.setCursor(0, 0);
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print(" cm ");
  delay(1000);
}