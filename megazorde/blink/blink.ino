int LED = 3;
char estado = "";
char mensagem = "";

void setup() {

  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
}

void loop() {  
  
  //char estado = "";
  //String x=x+serial.read();
  //x+=serial.read();

  //quando a variavel mensagem volta no loop, ela recebe vazio do serial
  mensagem = Serial.read();

  if(mensagem == '1' || estado == '1'){
      //preciso pegar o 255 e dividir pela voltagem
      //255/5=51
      estado = '1';
      analogWrite(LED, 51);
      delay(1000);
      analogWrite(LED, 0);
      delay(1000);
      //analogWrite(LED, 51);
  }else if(mensagem == '5' || estado == '5'){
      estado = '5';
      analogWrite(LED, 255);
      delay(1000);
      analogWrite(LED, 0);
      delay(1000);
  }

    Serial.print("Estado = ");
    Serial.println(estado);
    delay(300);
  
}
