const int trigPin = 4;
const int echoPin = 5;

const int greenLED = 18;
const int redLED = 7;

const float tankHeight = 40.0;   // cm

void setup() {

  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2.0;

  float waterHeight = tankHeight - distance;

  if (waterHeight < 0)
    waterHeight = 0;

  if (waterHeight > tankHeight)
    waterHeight = tankHeight;

  float percentage = (waterHeight / tankHeight) * 100.0;

  Serial.println("----------------------");
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Water Height : ");
  Serial.print(waterHeight);
  Serial.println(" cm");

  Serial.print("Level : ");
  Serial.print(percentage);
  Serial.println(" %");

  if (percentage >= 80) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

  } else if (percentage <= 30) {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

  } else {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
  }

  delay(1000);
}
