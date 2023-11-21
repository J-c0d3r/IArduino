#include <math.h>

int Tmp = A3;
int Bzz = 6;
int LedE = 3;
float seno;
float frequencia;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int Temp = A3 ;     // Grove - Temperature Sensor connect to A3

void setup() {

  Serial.begin(9600);
  pinMode(Tmp, INPUT);
  pinMode(Bzz, OUTPUT);
  digitalWrite(Bzz, LOW);
}

void loop() {

  int a = analogRead(Temp);

  float R = 1023.0 / a - 1.0;
  R = R0 * R;

  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15; // convert to temperature via datasheet

  Serial.print("temperature = ");
  Serial.println(temperature);
  delay(100);
  if (temperature >= 45.5) {

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

  }
  digitalWrite(LedE, LOW);
  noTone(Bzz);
}
