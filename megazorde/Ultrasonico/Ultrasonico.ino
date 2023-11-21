#include <Ultrasonic.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int Trigger = 4;
int Echo = 5;

Ultrasonic ultrasonic(Trigger, Echo);

void setup() {

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setRGB(0,0,0);
  lcd.setCursor(0,0);
  
}

void loop() {

   float cm;
   long microsec = ultrasonic.timing();
   cm = ultrasonic.convert(microsec, Ultrasonic::CM);
   if(cm>3100 || cm<=10){
      lcd.setRGB(0,128,0); //verde
   }else if(cm>10 && cm<=20){
      lcd.setRGB(0,0,255); //azul
   }else if(cm>20 && cm<=30){
      lcd.setRGB(255,255,0); //amarelo
   }else if(cm>30){
      lcd.setRGB(255,0,0); //vermelho
   }
   
   Serial.print("MS: ");
   Serial.println(microsec);
   Serial.print("CM: ");
   Serial.println(cm);
   Serial.println("");
   delay(500);
   
}
