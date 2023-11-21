int LED = 3;
int POT = A0;
int v;
int i = 0;
void setup() {

  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
  analogWrite(LED, LOW);
}

void loop() {

  for (i = 0; i < 255; i++) {
    analogWrite(LED, i);
    Serial.println(i);
    delay(7);
  }
  //delay(10);
  //digitalWrite(LED, HIGH) ;

  for (i = 254; i >= 0; i--) {
    analogWrite(LED, i);
    Serial.println(i);
    delay(7);
  }


  /*
    i = 254;
    do {
    analogWrite(LED, i);
    Serial.println(i);
    delay(7);
    i=i-1;
    } while (i > 0);
  */

  //v=analogRead(POT);
  //analogWrite(LED,v);



}
