#define pumpPin 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pumpPin, HIGH);
  delay(2000);
  digitalWrite(pumpPin, LOW);
  delay(2000);
}
