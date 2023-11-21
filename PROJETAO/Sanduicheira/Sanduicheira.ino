#include <Wire.h>
#include "rgb_lcd.h";

rgb_lcd lcd;

int esco = 0;
int pot0 = 0;
int ReleS = 2;
int Bot = 5;
int POT = A2;
int Bzz = 6;
//char t = "";
long tempo = 0;
unsigned long atual = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  //lcd.print("Ola, Juan");
  lcd.setRGB(0, 255, 255);
  //delay(5000);
  pinMode(ReleS, OUTPUT);
  pinMode(Bot, INPUT);
  pinMode(POT, INPUT);
  pinMode(Bzz, OUTPUT);
  digitalWrite(Bzz, LOW);
  digitalWrite(ReleS, LOW);
}

void loop() {

  unsigned long fim = millis();
  //t = Serial.read();
  if (pot0 == 0) {
    float pot = analogRead(POT);

    if (pot <= 256) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pao quentinho!");
      lcd.setCursor(0, 1);
      lcd.print("1 Minuto");
      esco = digitalRead(Bot);
      if (esco == 1) {
        digitalWrite(ReleS, HIGH);
        pot0 = 1;
        tempo = 60000;
        atual = millis();
      }

    } else if (pot <= 512) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mistao!");
      lcd.setCursor(0, 1);
      lcd.print("3 Minutos");
      esco = digitalRead(Bot);
      if (esco == 1) {
        digitalWrite(ReleS, HIGH);
        pot0 = 1;
        tempo = 180000;
        atual = millis();
      }

    } else if (pot <= 767) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Queijo derretido");
      lcd.setCursor(0, 1);
      lcd.print("5 Minutos");
      esco = digitalRead(Bot);
      if (esco == 1) {
        digitalWrite(ReleS, HIGH);
        pot0 = 1;
        tempo = 300000;
        atual = millis();
      }
    } else {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Carvao!");
      lcd.setCursor(0, 1);
      lcd.print("7 Minutos");
      esco = digitalRead(Bot);
      if (esco == 1) {
        digitalWrite(ReleS, HIGH);
        pot0 = 1;
        tempo = 420000;
        atual = millis();
      }
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Obg pela escolha");
    lcd.setCursor(0, 1);
    lcd.print("Tempo: ");
    lcd.print((fim - atual) / 1000);
    //lcd.print("Pão quentinho 1'");
    if ((fim - atual) >= tempo) {
      pot0 = 0;
      digitalWrite(ReleS, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Paozinho pronto!");
      lcd.setCursor(0, 1);
      lcd.print("Pode saborear ;)");
      digitalWrite(Bzz, HIGH);
      delay(200);
      digitalWrite(Bzz, LOW);
      delay(50);
      digitalWrite(Bzz, HIGH);
      delay(200);
      digitalWrite(Bzz, LOW);

      delay(1500);
    }

  }

  delay(40);


  /*
    if (t == '1') {
    inicial = millis();
    digitalWrite(RELE, HIGH);
    esco = 1;
    }
    if (atual - inicial == 60000 && esco == 1) {
    digitalWrite(RELE, LOW);
    inicial = 0;
    esco = 0;
    }

    if (t == '3') {
    inicial = millis();
    digitalWrite(RELE, HIGH);
    esco = 3;
    }
    if (atual - inicial == 180000 && esco == 3) {
    digitalWrite(RELE, LOW);
    inicial = 0;
    esco = 0;
    }

    if (t == '5') {
    inicial = millis();
    digitalWrite(RELE, HIGH);
    esco = 5;
    }
    if (atual - inicial == 300000 && esco == 5) {
    digitalWrite(RELE, LOW);
    inicial = 0 ;
    esco = 0;
    }

    if (t == '7') {
    inicial = millis();
    digitalWrite(RELE, HIGH);
    esco = 7;
    }
    if (atual - inicial == 420000 && esco == 7) {
    digitalWrite(RELE, LOW);
    inicial = 0 ;
    esco = 0;
    }
  */
}
