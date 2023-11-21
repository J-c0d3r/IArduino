#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR = 255;
int colorG = 0;
int colorB = 0;

void setup() {

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  //lcd.begin("");;

}

void loop() {

  lcd.display();
  lcd.print("Cossar");
  colorR=128;
  colorG=128;
  colorB=128;
  lcd.setRGB(colorR, colorG, colorB);
  //lcd.setRBG(colorR=128, colorG =128, colorB = 128);
  delay(800);

  lcd.clear();
  lcd.noDisplay();
  delay(500);
  
  lcd.display();
  lcd.print("eh");
  delay(800);

  lcd.clear();
  lcd.noDisplay();
  delay(500);
  
  lcd.display();
  lcd.print("vida");
  delay(800);

  lcd.clear();
  lcd.noDisplay();
  delay(500);
  
  lcd.display();
  lcd.print("meu caro");
  delay(850);

  lcd.clear();
  lcd.noDisplay();
  delay(500);

}
