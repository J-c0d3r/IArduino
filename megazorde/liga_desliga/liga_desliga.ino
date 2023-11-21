int LED = 6;
int BOT = 5;
int leitor = 0;
int leitor2 = 0;
int estado = 0;

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BOT, INPUT);

}

void loop() {
  
  leitor = digitalRead(BOT);
  if(leitor==HIGH){
    estado = estado+1;
    delay(500);
  }
  
  if(estado==1){
    digitalWrite(LED, HIGH);
  }
  if(estado==2){

  int luz=0;
    while(estado==2){
      int teste = digitalRead(BOT);
      if(teste==0){
        luz=1-luz;
        digitalWrite(LED, luz);
        delay(350);
      }else{
        estado++;
      }
    }

    /*
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    //delay(500);
    */
  }
  if(estado==3){
    digitalWrite(LED, LOW);
    delay(250);
    estado=0;
    delay(250);
  }
  
  
  
  /*
  if((leitor==HIGH)&&(leitor2==LOW)){
    estado = 1 - estado;
    delay(200);
  }
  leitor2 = leitor;
  if(estado==1){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
*/
}
