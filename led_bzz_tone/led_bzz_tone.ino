int Bzz = 6;
int LedE = 3;
float seno;
int frequencia;
int i=0;
void setup() {

  pinMode(Bzz, OUTPUT);
  pinMode(LedE, OUTPUT);
  analogWrite(LedE, LOW);
}

void loop() {

  for (int x = 0; x < 180; x++) {
    if(i>254){
      i=0;
    }
    analogWrite(LedE, i);
    i++;
    seno = (sin(x * 3.1416 / 180));
    frequencia = 500 + (int(seno * 1000));
    tone(Bzz, frequencia);
    
    delay(20);
    
  }

}
