void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int aSensorReading = analogRead(A2);
  bool dSensorReading = digitalRead(4);

  Serial.print(aSensorReading);
  Serial.print(" ");
  Serial.println(dSensorReading);

  delay(300);
}
