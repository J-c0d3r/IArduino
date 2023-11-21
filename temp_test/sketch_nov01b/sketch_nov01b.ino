const int tmp = A0;
//const int p = 8;

void setup() {
  //lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(tmp, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  //digitalWrite(p,LOW);
  int Temp = analogRead(tmp);
  float volts = Temp * 5.0;
  volts /= 1024.0;
  volts = (volts - 0.5) * 100;
  //float c = (volts - .5) * 100;
  //float f = (c * 9 / 5 + 32);
  Serial.println(volts);
  //lcd.setCursor(5, 0);
  //lcd.print(c);
  delay(500);
  // put your main code here, to run repeatedly:

}
