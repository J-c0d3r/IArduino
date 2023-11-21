#include <Crescer.h>
int RELE = 4, temp=0;;
char val = "";
int seg=0;
Tempora temp1;
Tempora temp3;
Tempora temp5;

void setup() {

  Serial.begin(9600);
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, LOW);
  temp1.defiSP(1000);
  temp3.defiSP(3000);
  temp5.defiSP(5000);
}

void loop() {

  val = Serial.read();
  
  if (val == '1') {
    digitalWrite(RELE, temp1.Saida(true));
  }
  if (val == '3') {
    digitalWrite(RELE, HIGH);
    temp = temp3.Saida(true);
    //digitalWrite(RELE, temp);
  }
  if (val == '5') {
    digitalWrite(RELE, HIGH);
  }
  if(temp==1){
    digitalWrite(RELE, LOW);
  }

}
