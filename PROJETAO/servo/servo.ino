#include <Servo.h>
Servo motor;

int POT = A0;


void setup() {

  motor.attach(A1);

}

void loop() {

  int pot = analogRead(POT);
  pot = map(pot, 0,1023,0,180);
  motor.write(pot);
  delay(15);

}
