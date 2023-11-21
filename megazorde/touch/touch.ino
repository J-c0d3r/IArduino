int LED = 6;
int Tou = 3;
int soma=0;

void setup() {
  
  pinMode(6, OUTPUT);
  pinMode(3, INPUT);

}

void loop() {

  int sensorValue = digitalRead(Tou);
  int soma=soma+1;
  
  if(soma==1){
    digitalWrite(LED, HIGH);
  }
  if(soma==2){
    digitalWrite(LED, LOW);
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED,LOW);
  }
  if(soma==3){
    digitalWrite(LED, HIGH);
    delay(80);
    digitalWrite(LED, LOW);
    delay(80);
    digitalWrite(LED, HIGH);
    delay(80);
    digitalWrite(LED, LOW);
  }

}
