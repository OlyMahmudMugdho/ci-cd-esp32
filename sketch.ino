#define TRIG_PIN 12
#define ECHO_PIN 13

const unsigned long ECHO_TIMEOUT_US = 30000;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);

  delay(500);

  Serial.println();
  Serial.println("HC-SR04 + ESP32-S3 Diagnostic");
  Serial.println("Place a flat object 20-50 cm away.");
  Serial.println("--------------------------------");
}

void loop() {
  // Ensure the trigger starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);

  // Send a 10 us trigger pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Allow a short settling interval
  delayMicroseconds(200);

  // Measure the ECHO pulse
  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);

  if (duration == 0) {
    Serial.println("NO ECHO: Check power, TRIG, ECHO and GND");
  } else {
    float distanceCm = duration * 0.0343f / 2.0f;

    Serial.print("Duration: ");
    Serial.print(duration);
    Serial.print(" us | Distance: ");
    Serial.print(distanceCm, 2);
    Serial.println(" cm");
  }

  delay(250);
}
