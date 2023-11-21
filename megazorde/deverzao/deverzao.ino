int BOT = 7;
int LED = 5;
int BZZ = 6;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BZZ, OUTPUT);
  pinMode(BOT, INPUT);
  digitalWrite(LED, HIGH);
}

void loop() {

  int bot = digitalRead(BOT);

  if(bot==1){
    digitalWrite(LED, LOW);
    digitalWrite(BZZ, HIGH);
    delay(800);       
  }else{
    digitalWrite(LED, HIGH);
    digitalWrite(BZZ, LOW);
  }
  
}
