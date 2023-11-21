#include <Wire.h>
#include "rgb_lcd.h"
#define BOT 2
#define TOU 4
#define POT A0
rgb_lcd lcd;
String vet[25];

byte coracao[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100
};

void setup() {

  pinMode(BOT, INPUT);
  pinMode(TOU, INPUT);
  pinMode(POT, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(0, 0, 128);
  lcd.setCursor(0, 0);
  lcd.print("ESCOLHA: BOTAO?");
  lcd.setCursor(0, 1);
  lcd.print("TOUCH?POTENCIO.?");
  lcd.createChar(1, coracao);
}

void loop() {

  int bot = digitalRead(BOT); //Patricia
  int tou = digitalRead(TOU); //Renilson
  float pot = analogRead(POT);  //Rilary

  if (bot == 1) {
    patricia();
  }

  if (tou == 1) {
    renilson();
  }

  if (pot > 300) {
    rilary();
  }
}

void patricia() {

  vet[0] = "Patricia";
  vet[1] = "Sabia";
  vet[2] = "Que...";
  vet[3] = "Eu";
  vet[4] = "TENHO";
  vet[5] = "a";
  vet[6] = "MELHOR";
  vet[7] = "SOGRA";
  vet[8] = "do";
  vet[9] = "MUNDO!!! :)";

  lcd.setRGB(255, 0, 0); //vermelho

  for (int i = 0; i < 10; i++) {
    lcd.clear();
    lcd.display();
    lcd.setCursor(i, 0);
    if (i == 9) {
      lcd.setCursor(3, 0);
    }
    lcd.print(vet[i]);
    delay(700);
    lcd.noDisplay();
    delay(300);
  }

  setup();

}

void renilson() {

  vet[0] = "Renilson";
  vet[1] = "Sabia";
  vet[2] = "Que...";
  vet[3] = "Eu";
  vet[4] = "TENHO";
  vet[5] = "o";
  vet[6] = "MELHOR";
  vet[7] = "SOGRO";
  vet[8] = "do";
  vet[9] = "MUNDO!!! :)";
  vet[10] = "Me ensina a";
  vet[11] = "fazer comida? :)";

  lcd.setRGB(0, 255, 0); //mudar a cor

  for (int i = 0; i < 12; i++) {

    if (i != 10 && i != 11) {
      lcd.clear();
      lcd.display();
      lcd.setCursor(i, 0);
    }

    if (i == 10) {
      lcd.clear();
      lcd.display();
      lcd.setCursor(2, 0);
      lcd.print(vet[i]);
      delay(500);
    }
    else if (i == 11) {
      lcd.display();
      lcd.setCursor(0, 2);
      lcd.print(vet[i]);
      delay(3300);
    }
    else if (i == 9) {
      lcd.setCursor(2, 0);
      lcd.print(vet[i]);
    }
    else {
      lcd.print(vet[i]);
    }

    delay(700);
    lcd.noDisplay();
    delay(300);

  }

  setup();

}

void rilary() {

  vet[0] = "Rilary";
  vet[1] = "Sabia";
  vet[2] = "Que...";
  vet[3] = "Eu";
  vet[4] = "TENHO";
  vet[5] = "a";
  vet[6] = "MELHOR";
  vet[7] = "PESSOA";
  vet[8] = "desse";
  vet[9] = "MUNDO";
  vet[10] = "TODO???";
  vet[11] = "QUE";
  vet[12] = "EH";
  vet[13] = "VOCE :)";
  vet[14] = "";
  vet[15] = "VOCE";
  vet[16] = "EH";
  vet[17] = "UMA";
  vet[18] = "LINDEZA";
  vet[19] = "DE";
  vet[20] = "AMORZINHO :)";
  
  lcd.setRGB(255, 255, 0); //amarelo

  for (int i = 0; i < 21; i++) {
    lcd.clear();
    lcd.display();
    lcd.setCursor(i, 0);

    if (i >= 9) {
      lcd.setCursor(3, 0);
    }
    if (i == 20) {
      lcd.print(vet[i]);
      lcd.setCursor(7, 2);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      delay(3000);
    } else {
      lcd.print(vet[i]);
      delay(700);
    }

    if (i == 14) {
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      lcd.write(1);
      delay(700);
    }

    lcd.noDisplay();
    delay(300);
  }

  setup();

}
