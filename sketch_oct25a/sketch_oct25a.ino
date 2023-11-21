//char t1 = "";
//String t2 = "";
byte t3 = "";

void setup() {
  Serial.begin(9600);

}

void loop() {

  t3 = Serial.read();
  //t1 = Serial.readStringUntil("\n");

  if ( t3 != "") {
    Serial.println(t3);
  }

  delay(1000);
}
