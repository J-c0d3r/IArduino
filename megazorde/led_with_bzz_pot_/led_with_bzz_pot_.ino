int LED = 5;
int BZZ = 6;
int POT = A1;
int BOT = 4;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BZZ, OUTPUT);
  pinMode(POT, INPUT); 
  pinMode(BOT, INPUT);

}

void loop() {

  int pot = analogRead(POT);
  int pwm = map(pot, 0, 1024, 0, 255);

  analogWrite(LED, pwm);
  analogWrite(BZZ, pwm);

  int bot = digitalRead(BOT);
  int led = digitalRead(LED);
  if(led!=0){
    if(bot==1){
      analogWrite(LED, pwm);
    }else{
      analogWrite(LED, pwm);
    }
  }

}
