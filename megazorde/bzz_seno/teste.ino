float seno;
int frequencia;

void setup() {
//int  buzzer=6;
  pinMode(6, OUTPUT);

}

void loop() {
  for(int x=0;x<180;x++){
      seno=(sin(x*3.1416/180));
      frequencia = 500+(int(seno*1000));
      //tone(6, frequencia);
      delay(20);
  }
}
