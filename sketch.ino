#define TRIG_PIN 5
#define ECHO_PIN 6

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);
  delay(500);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("NO ECHO");
  } else {
    float distance = duration * 0.0343 / 2.0;

    Serial.print("Duration: ");
    Serial.print(duration);
    Serial.print(" us | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(200);
}
