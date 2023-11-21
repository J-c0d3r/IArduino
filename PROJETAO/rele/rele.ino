int RELE = 4;
char val = "";

void setup() {

  Serial.begin(9600);
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, HIGH);
}

void loop() {

  val = Serial.read();
  if (val == '1') {
    digitalWrite(RELE, HIGH);
  } else if (val == '0') {
    digitalWrite(RELE, LOW);
  }

}
