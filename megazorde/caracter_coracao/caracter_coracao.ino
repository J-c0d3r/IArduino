#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

//coracao
byte coracao[8]={
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

  //lcd.init();
  //lcd.backlight();
  lcd.begin(16,2);
  lcd.setRGB(255,0,128);

  lcd.createChar(1, coracao);
  lcd.begin(16,2);
  
}

void loop() {
  lcd.setCursor(0,0);
  lcd.write(1);
  lcd.noDisplay();
  delay(400);
  lcd.display();
  lcd.setCursor(3,1);
  lcd.write(1);
  delay(600);
}
