#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR=255, colorG=120, colorB=0;

void setup() {

  lcd.begin(16,2);
   
  lcd.setRGB(colorR, colorG, colorB);
  lcd.write(B11110101);
  

}

void loop() {
  /*
  lcd.print("teste");
  colorR=0;
  setup();
  lcd.print("teste2");
  delay(500);
  colorR=255;
  colorG=255;
  colorB=255;
  setup();
  
  delay(500);
  */
}
