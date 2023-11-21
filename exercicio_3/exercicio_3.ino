int LED = 3;
int POT = A0;
int BZZ = 4;
int saida = 0;
void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BZZ, OUTPUT);
  pinMode(POT, INPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600); //imprimir no monitor serial
}

void loop() {
  
  float pot = analogRead(POT);
  saida = map(pot, 0, 1023, 0, 5);

  //Serial.println(pot);
  //Serial.println(saida);
  
  Serial.print("Tensão de entrada: ");
  Serial.print(pot*5/1023);
  Serial.print("    Tensão de saída: ");
  Serial.println(saida);

  if (pot > 820 && pot <= 921) {
    analogWrite(LED, 204);

    //delay(100);

  }
  else if (pot > 615 && pot <= 820) {
    analogWrite(LED, 153);

    //delay(100);
  }
  else if (pot > 410 && pot <= 615) {
    analogWrite(LED, 102);

    ///delay(100);
  }
  else if (pot > 205 && pot <= 410) {
    analogWrite(LED, 51);

    //delay(100);
  }
  else if (pot >= 0 && pot < 205) {
    analogWrite(LED, 0);
   
    //delay(100);
  }
  else {
    analogWrite(LED, 0);
    digitalWrite(BZZ, HIGH);
    char b = "";
    while ( b != '0' ) {
      b = Serial.read();
      delay(100);
    }
    digitalWrite(BZZ, LOW);
  }


}
