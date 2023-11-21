int ReleL = 8;
int ReleS = 7;

void setup() {

  pinMode(ReleL, OUTPUT);
  digitalWrite(ReleL, LOW);

}

void loop() {
  
  //Lampada
  digitalWrite(ReleL, HIGH);

  digitalWrite(ReleL, LOW);
  //

  //Sanduiche
  digitalWrite(ReleS, HIGH);
  
  digitalWrite(ReleS, LOW)
  //
}
