#define pumpPin 13

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    Serial.read();
    digitalWrite(pumpPin, HIGH);
    delay(1000);
    return;
  } 

  digitalWrite(pumpPin, LOW);
}
