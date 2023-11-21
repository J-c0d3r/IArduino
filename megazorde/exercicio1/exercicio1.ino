int LED = 3;

void setup() {

  Serial.begin(9600);
  pinMode(LED, 3);
  analogWrite(LED, 0);

}

void loop() {

  Serial.println("V(led) = 2V");
  analogWrite(LED, 102);
  delay(2000);
  Serial.println("V(led) = 4V");
  analogWrite(LED, 204);
  delay(2000);

}
