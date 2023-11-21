#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

rgb_lcd lcd;

#define ReleLC 7
#define ReleLQ 8
Servo MotorG;
Servo MotorP;

// Update these with values suitable for your network.
byte mac[] = {  0xDE, 0xEC, 0xAA, 0xEE, 0x15, 0x30 }; //colocar matricula
//IPAddress ip(192, 168, 0, 15); comentado pois está dinamico no roteador
IPAddress broker(192, 168, 2, 4); //server ubunto/broker eh o que faz a comunicacao

EthernetClient ethClient;
PubSubClient client(ethClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if (strcmp(topic, "CozinhaLamp") == 0)
  {

    int val = atoi((char*)payload);
    if (val == 1)
    {
      digitalWrite(ReleLC, HIGH);
      Serial.println("Lampada da cozinha acendeu!");
      lcd.setCursor(0, 0);
      lcd.print("Lampada");
      lcd.setCursor(0, 1);
      lcd.print("Acendeu!");
      delay(1200);
      lcd.clear();

    } else if (val == 0 ) {

      digitalWrite(ReleLC, LOW);
      Serial.println("Lampada da cozinha apagou!");
      lcd.setCursor(0, 0);
      lcd.print("Lampada");
      lcd.setCursor(0, 1);
      lcd.print("Apagou!");
      delay(1200);
      lcd.clear();
    }
  }

  if (strcmp(topic, "QuartoLamp") == 0)
  {

    int val = atoi((char*)payload);
    if (val == 1)
    {
      digitalWrite(ReleLQ, HIGH);
      Serial.println("Lampada do quarto acendeu!");
      lcd.setCursor(0, 0);
      lcd.print("Lampada");
      lcd.setCursor(0, 1);
      lcd.print("Acendeu!");
      delay(1200);
      lcd.clear();

    } else if (val == 0 ) {

      digitalWrite(ReleLQ, LOW);
      Serial.println("Lampada do quarto apagou!");
      lcd.setCursor(0, 0);
      lcd.print("Lampada");
      lcd.setCursor(0, 1);
      lcd.print("Apagou!");
      delay(1200);
      lcd.clear();
    }
  }

  if (strcmp(topic, "GaragemPortao") == 0)
  {
    int val = atoi((char*)payload);
    if (val == 1)
    {
      MotorG.write(0);
      Serial.println("Portao da garagem abriu!");
      lcd.setCursor(0, 0);
      lcd.print("Portao Garagem");
      lcd.setCursor(0, 1);
      lcd.print("Abriu!");
      delay(1200);
      lcd.clear();

    } else if (val == 0) {

      MotorG.write(90);
      Serial.println("Portao da garagem fechou!");
      lcd.setCursor(0, 0);
      lcd.print("Portao Garagem");
      lcd.setCursor(0, 1);
      lcd.print("Fechou!");
      delay(1200);
      lcd.clear();

    }
  }

  if (strcmp(topic, "QuartoPorta") == 0)
  {
    int val = atoi((char*)payload);
    if (val == 1)
    {
      MotorP.write(90);
      Serial.println("Porta do Quarto abriu!");
      lcd.setCursor(0, 0);
      lcd.print("Porta do Quarto");
      lcd.setCursor(0, 1);
      lcd.print("Abriu!");
      delay(1200);
      lcd.clear();
    } else if (val == 0) {

      MotorP.write(0);
      Serial.println("Porta do Quarto fechou!");
      lcd.setCursor(0, 0);
      lcd.print("Porta do Quarto");
      lcd.setCursor(0, 1);
      lcd.print("Fechou!");
      delay(1200);
      lcd.clear();

    }
  }

  memset(payload, 0, length);
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
  lcd.print("Iniciando");
  lcd.setCursor(0, 1);
  lcd.print("sistema...");
  pinMode(ReleLC, OUTPUT);
  pinMode(ReleLQ, OUTPUT);
  MotorG.attach(A0);
  MotorP.attach(A1);
  digitalWrite(ReleLC, LOW);
  digitalWrite(ReleLQ, LOW);

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
