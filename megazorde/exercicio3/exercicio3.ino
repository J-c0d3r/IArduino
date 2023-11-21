int LED = 2;
int BZZ = 4;
char inv = "";

int stateLed = 0;
int stateBuzz = 0;

void setup() {

  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BZZ, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(BZZ, LOW);

}

void loop() {

  inv = Serial.read();

  if (inv == '1') {
    stateBuzz = !stateBuzz;
  }
  if (inv == '2') {
    stateLed = !stateLed;
  }

  digitalWrite(BZZ, stateBuzz);
  digitalWrite(LED, stateLed);
}
