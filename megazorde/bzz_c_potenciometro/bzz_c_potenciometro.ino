int bzz = 6;
int pot = A1;
int LED = A2;

void setup() {

  pinMode(bzz, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(LED, OUTPUT);
  //Serial.begin(9600);
  analogWrite(LED, LOW);

}

void loop() {

  int potV = analogRead(pot);
  int pwm = map(potV, 0, 1024, 0, 255);

  analogWrite(bzz, pwm);
  analogWrite(LED, pwm);

}
