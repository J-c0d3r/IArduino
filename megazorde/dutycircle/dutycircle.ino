int LED = 5;
float POT = A0;
int BZZ = 3;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BZZ, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop() {

  float pot = analogRead(POT);
  pot = map(pot,0,1023,0.0,5.0);
  Serial.print("Tensão de entrada: ");
  Serial.println(pot);
    
  if(pot>0 && pot <=1){
    analogWrite(LED, 0);
  }else if(pot>1 && pot<=2){
    analogWrite(LED, 51);
  }else if(pot>2 && pot<=3){
    analogWrite(LED, 102);
  }else if(pot>3 && pot<=4){
    analogWrite(LED, 153);
  }else if(pot>4.0 && pot<=4.5){
    analogWrite(LED, 204);
  }else if(pot>4.5){
    analogWrite(LED, 0);
    //digitalWrite(BZZ, HIGH);
    while(){
      
    }
  }
 
}
