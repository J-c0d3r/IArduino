#define LED 3
#define TOU 4
int tempo=0;
int TO=0;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(TOU, INPUT);
}

void loop() {

  TO = digitalRead(TOU);
  while(TO==1){
  TO = digitalRead(TOU);
  tempo=millis();
  }
  if(tempo>=1000){
    //delay(1000);
    digitalWrite(LED, HIGH);
    
    
  }else{
    digitalWrite(LED, LOW);
  }

}
