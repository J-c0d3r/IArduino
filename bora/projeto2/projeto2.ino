#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h";
#include <Servo.h>

rgb_lcd lcd;

#define ReleLC 7
#define ReleLQ 8
#define ReleS 2
#define LedE 3
#define Bot 5
#define Bzz 6
#define POT A2
#define Temp A3

Servo MotorG;
Servo MotorP;

int estaPG = 0;
int estaPQ = 0;
int estaLQ = 0;
int estaLC = 0;

char val = "";

int esco = 0;
int pot0 = 0;
long tempo = 0;
unsigned long atual = 0;

float seno;
float frequencia;

int a = 0;
int B = 4275;               // B value of the thermistor
int R0 = 100000;            // R0 = 100k

void setup() {
  Serial.begin(9600);
  Serial.println("Seja bem vindo ao nosso sistema :)");
  Serial.println("Escolha uma das opções abaixo:");
  Serial.println("1 - Portao da garagem");
  Serial.println("2 - Porta do quarto");
  Serial.println("3 - Lampada do quarto");
  Serial.println("4 - Lampada da cozinha");

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ola, Senhor(a)");
  lcd.setRGB(0, 255, 255);
  delay(1000);
  
  pinMode(ReleLC, OUTPUT);
  pinMode(ReleLQ, OUTPUT);
  pinMode(ReleS, OUTPUT);
  pinMode(LedE, OUTPUT);
  pinMode(Bot, INPUT);
  pinMode(POT, INPUT);
  pinMode(Bzz, OUTPUT);
  pinMode(Temp, INPUT);
  MotorG.attach(A0);
  MotorP.attach(A1);
  digitalWrite(ReleLC, LOW);
  digitalWrite(ReleLQ, LOW);
  digitalWrite(ReleS, LOW);
  digitalWrite(LedE, LOW);
  digitalWrite(Bzz, LOW);

}

void loop() {

  a = analogRead(Temp);

  float R = 1023.0 / a - 1.0;
  R = R0 * R;
  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15; // convert to temperature via datasheet

  while (temperature >= 45.5) {
    
    for (int x = 0; x < 180; x += 10) {
      seno = (sin(x * 3.1416 / 180));
      frequencia = 500 + (int(seno * 1000));
      digitalWrite(LedE, x);
      tone(Bzz, frequencia);

      delay(20);
    }

    Serial.print("temperature = ");
    Serial.println(temperature);
    delay(100);
    a = analogRead(Temp);

    R = 1023.0 / a - 1.0;
    R = R0 * R;
    temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15;
    if(!(temperature>=45.5)){
      setup();
    }
  }

  digitalWrite(LedE, LOW);
  noTone(Bzz);

  delay(40);
  
  val = Serial.read();

  if ((val == '1') && (estaPG == 1)) {

    MotorG.write(90);
    Serial.println("Portao da garagem fechou!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Portao Garagem");
    lcd.setCursor(0, 1);
    lcd.print("Fechou!");
    delay(1200);
    lcd.clear();
    estaPG = 0;

  } else if ((val == '1') && (estaPG == 0)) {

    MotorG.write(0);
    Serial.println("Portao da garagem abriu!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Portao Garagem");
    lcd.setCursor(0, 1);
    lcd.print("Abriu!");
    delay(1200);
    lcd.clear();
    estaPG = 1;

  }

  if ((val == '2') && (estaPQ == 1)) {

    MotorP.write(0);
    Serial.println("Porta do quarto fechou!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Porta Quarto");
    lcd.setCursor(0, 1);
    lcd.print("Fechou!");
    delay(1200);
    lcd.clear();
    estaPQ = 0;

  } else if ((val == '2') && (estaPQ == 0)) {

    MotorP.write(90);
    Serial.println("Porta do quarto abriu!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Porta Quarto");
    lcd.setCursor(0, 1);
    lcd.print("Abriu!");
    delay(1200);
    lcd.clear();
    estaPQ = 1;

  }

  if ((val == '3') && (estaLQ == 1)) {

    digitalWrite(ReleLQ, HIGH);
    Serial.println("Lampada do quarto acendeu!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampada");
    lcd.setCursor(0, 1);
    lcd.print("Acendeu!");
    delay(1200);
    lcd.clear();
    estaLQ = 0;

  } else if ((val == '3') && (estaLQ == 0)) {

    digitalWrite(ReleLQ, LOW);
    Serial.println("Lampada do quarto apagou!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampada");
    lcd.setCursor(0, 1);
    lcd.print("Apagou!");
    delay(1200);
    lcd.clear();
    estaLQ = 1;

  }

  if ((val == '4') && (estaLC == 1)) {

    digitalWrite(ReleLC, HIGH);
    Serial.println("Lampada da cozinha acendeu!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampada");
    lcd.setCursor(0, 1);
    lcd.print("Acendeu!");
    delay(1200);
    lcd.clear();
    estaLC = 0;

  } else if ((val == '4') && (estaLC == 0)) {

    digitalWrite(ReleLC, LOW);
    Serial.println("Lampada da cozinha apagou!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampada");
    lcd.setCursor(0, 1);
    lcd.print("Apagou!");
    delay(1200);
    lcd.clear();
    estaLC = 1;

  }

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
    delay(40);


  }
}
