#define pumpPin 13

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  Serial.write(1);
  delay(1000);
  if (Serial.available() > 0) {
    Serial.read();
    digitalWrite(pumpPin, HIGH);
    delay(1000);
    digitalWrite(pumpPin, LOW);
  }
}
