int LED = 2;
int MIC = A0;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(MIC, OUTPUT);

}

void loop() {

  int mic = analogRead(MIC);
  if(mic>500){
    digitalWrite(LED, HIGH);
  }

}
