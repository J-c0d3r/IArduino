
int BZZ = 6;
int t;

void setup() {

  Serial.begin(9600);
  pinMode(BZZ, OUTPUT);
  analogWrite(BZZ, LOW);

}

void loop() {

  String mensagem = Serial.read();
    
  t = mensagem.toInt();
  Serial.println(t);
  delay(1000);
  if (t == 1) {
    analogWrite(BZZ, HIGH);
    delay(200);
    analogWrite(BZZ, LOW);
    delay(50);
    analogWrite(BZZ, HIGH);
    delay(200);
    analogWrite(BZZ, LOW);
    delay(50);
  }
  //delay(1000);
}
