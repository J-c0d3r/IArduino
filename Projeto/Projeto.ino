#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

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

float seno;
float frequencia;
int B = 4275;
int R0 = 100000;
int esco = 0;
int pot0 = 0;
long tempo = 0;
unsigned long atual = 0;

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xEC, 0xAA, 0xEE, 0x15, 0x30 }; //colocar matricula
//IPAddress ip(192, 168, 0, 15); comentado pois está dinamico no roteador
IPAddress broker(192, 168, 2, 4); //server ubunto/broker eh o que faz a comunicacao

EthernetClient ethClient;
PubSubClient client(ethClient);

void teste(){

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

  void callback(char* topic, byte* payload, unsigned int length);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  //aqui onde irei colocar todos os codigos do sistema

  if (strcmp(topic, "CozinhaLamp") == 0) //strcmp ele soma, em formato decimal os caracteres,
  {

    int val = atoi((char*)payload);//char* variable pesquisar, coisa de ponteiro
    if (val == 1)
    {
      digitalWrite(ReleLC, HIGH);

    } else if (val == 0 ) {

      digitalWrite(ReleLC, LOW);
    }
  }

  if (strcmp(topic, "QuartoLamp") == 0) //strcmp ele soma, em formato decimal os caracteres,
  {

    int val = atoi((char*)payload);//char* variable pesquisar, coisa de ponteiro
    if (val == 1)
    {
      digitalWrite(ReleLQ, HIGH);

    } else if (val == 0 ) {

      digitalWrite(ReleLQ, LOW);
    }
  }

  if (strcmp(topic, "CozinhaSand") == 0)
  {
    unsigned long fim = millis();
    int val = atoi((char*)payload);
    if (val == 1) {
      atual = millis();
      digitalWrite(ReleS, HIGH);
      esco = 1;
      tempo = 60000;
    }
    if ((fim - atual) >= tempo && esco == 1) {
      digitalWrite(ReleS, LOW);
      atual = 0;
      esco = 0;
      val = 0;
    }

    if (val == 3) {
      atual = millis();
      digitalWrite(ReleS, HIGH);
      esco = 3;
    }
    if ((fim - atual) >= tempo && esco == 3) {
      digitalWrite(ReleS, LOW);
      atual = 0;
      esco = 0;
      val = 0;
    }

    if (val == 5) {
      atual = millis();
      digitalWrite(ReleS, HIGH);
      esco = 5;
    }
    if ((fim - atual) >= tempo && esco == 5) {
      digitalWrite(ReleS, LOW);
      atual = 0 ;
      esco = 0;
      val = 0;
    }

    if (val == 7) {
      atual = millis();
      digitalWrite(ReleS, HIGH);
      esco = 7;
    }
    if ((fim - atual) >= tempo && esco == 7) {
      digitalWrite(ReleS, LOW);
      atual = 0 ;
      esco = 0;
      val = 0;
    }
  }

  if (strcmp(topic, "GaragemPortao") == 0)
  {
    int val = atoi((char*)payload);
    if (val == 1)
    {
      MotorG.write(90);

    } else if (val == 0) {

      MotorG.write(0);

    }
  }

  if (strcmp(topic, "QuartoPorta") == 0)
  {
    int val = atoi((char*)payload);
    if (val == 1)
    {
      MotorP.write(90);

    } else if (val == 0) {

      MotorP.write(0);

    }
  }

  memset(payload, 0, length);
  teste();
}



void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");//topico para ser subscrito
      client.subscribe("CozinhaLamp");
      client.subscribe("CozinhaSand");
      client.subscribe("QuartoLamp");
      client.subscribe("GaragemPortao");
      client.subscribe("QuartoPorta");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}

void setup()
{
  Serial.begin(115200);

  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 255);
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

  Serial.println("Starting System...");

  if (Ethernet.begin(mac) == 0)
  {
    Serial.println("Failed to configure Ethernet using DHCP");
  }
  else
  {
    Serial.println("Succeeded to configure Ethernet using DHCP");
  }
  // print your local IP address:
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
  }
  Serial.println();
  // Allow the hardware to sort itself out
  delay(1500);

  client.setServer(broker, 1883);
  client.setCallback(callback);

}

void loop()
{
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

}
