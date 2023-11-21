#include <Wire.h>
#include "rgb_lcd.h";

rgb_lcd lcd;

int esco = 0;
int escoT = 0;
int RELE = 4;
int TOU = 5;
int POT = A2;
char t = "";
unsigned long inicial = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.setRGB(0, 255, 255);
  pinMode(RELE, OUTPUT);
  pinMode(TOU, INPUT);
  pinMode(POT, INPUT);
  digitalWrite(RELE, LOW);
  //lcd.print("teste");
}

void loop() {

  unsigned long atual = millis();
  t = Serial.read();

  float pot = analogRead(POT);

  if (pot <= 255.75) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pao quentinho!");
    lcd.setCursor(0, 1);
    lcd.print("1 minuto");
    esco = digitalRead(TOU);
    delay(17);
    if (esco == 1) {
      escoT = 1;
    }
  }
  if (escoT == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Obg pela escolha");
    lcd.setCursor(0, 1);
    lcd.print("Pao quentinho 1'");
    lcd.print(atual / 1000);
    delay(50);
  }



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
  delay(50);
}
