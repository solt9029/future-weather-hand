#define outputPin 2 // used as 5V
#define trigPin 10
#define echoPin 11
#define pumpPin 13
#define distanceThreshold 15

void setup() {
  Serial.begin(9600);

  pinMode(outputPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pumpPin, OUTPUT);

  digitalWrite(outputPin, HIGH);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float distanceDelay = pulseIn(echoPin, HIGH);
  float distance = 340 * distanceDelay / 2 / 10000;
  bool isHandInserted = distanceDelay > 0 && distance < distanceThreshold;

  Serial.write(1);
  delay(1000);
  if (Serial.available() > 0 && isHandInserted) {
    Serial.read();
    digitalWrite(pumpPin, HIGH);
    delay(1000);
    digitalWrite(pumpPin, LOW);
    Serial.println("pump");
  }
}
