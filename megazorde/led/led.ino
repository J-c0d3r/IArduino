int LED = 5;
int BOT = 4;
//int var = 0;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BOT, INPUT);
  digitalWrite(LED, LOW);
  digitalWrite(BOT, 0);
}

void loop() {

  int bot = digitalRead(BOT);
  int led = digitalRead(LED);

  if(led==0){
     if(bot==1){
      digitalWrite(LED, HIGH);
     }
  }else if(led!=0){
    if(bot==1){
      digitalWrite(LED, LOW);
    }
  }
  



/*
  int bot = digitalRead(BOT);
  if(bot==0){
    var++;
  }else{
    var++;
  }
  */
  
  /*
  if(var%2!=0){
    digitalWrite(LED, HIGH);
  }
  if(var%2==0){
    digitalWrite(LED, LOW);
  }
  */
  
  
  
  /*
  if(bot==1){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
  */
  
  
  
  /*
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  delay(100);
  */
}
