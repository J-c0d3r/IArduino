/*
 Basic MQTT example with DHCP and buzzer

 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topics "inTopic" and "buzzer", printing out any messages
    it receives.
    NB - it assumes the received payloads are strings not binary

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

const int buzzerPin = 6;
const int led = 3;

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xEC, 0xAA, 0xEE, 0x15, 0x30 }; //colocar matricula
//IPAddress ip(192, 168, 0, 15); comentado pois está dinamico no roteador
IPAddress broker(192, 168, 0, 102); //server ubunto/broker é o que faz a cmounicalçai 

EthernetClient ethClient;
PubSubClient client(ethClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if(strcmp(topic, "buzzer") == 0)//strcmp ele soma, em formato decimal os caracteres, 
  {
    int val = atoi((char*)payload);//char* variable pesquisar, coisa de ponteiro
    if(val >= 0 and val <= 1000)
    {
      tone(buzzerPin, val, 200);
    }
  }

//aqui onde irei colocar todos os codigos do sistema
   if(strcmp(topic, "LED") == 0)//nome do topico
  {
    int val = atoi((char*)payload);
    if(val >= 0 and val <= 1)//condição para o funcionamento
    {
      digitalWrite(led, val);
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
      client.publish("outTopic","hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
      client.subscribe("buzzer");
      client.subscribe("LED");//topico para ser subscrito
      client.subscribe("CozinhaLED")
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(57600);

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  Serial.println("Starting System...");
  
  if(Ethernet.begin(mac) == 0)
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
