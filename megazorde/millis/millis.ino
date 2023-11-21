#define LED 3
#define TOU 4

int tempo=0;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(TOU, INPUT);
  Serial.begin(9600);
}

void loop() {

  int TO = digitalRead(TOU);
  while(TO==1){
    TO = digitalRead(TOU);
  int currentMillis = millis(); //pega o tempo atual
  tempo = currentMillis - tempo;  
  }
   if(tempo>=2000){
    digitalWrite(LED, HIGH);
   }else{
    digitalWrite(LED, LOW);
    tempo=0;
   }
Serial.print("Time: ");
int teste = millis();
Serial.println(teste);
}
