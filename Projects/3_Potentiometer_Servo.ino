#include <Servo.h>

const int potPin = A4;
const int servoPin = 9;

Servo myServo;

void setup() {
  Serial.begin(9600);

  pinMode(potPin, INPUT);

  myServo.attach(servoPin);
}

void loop() {
  int potValue = analogRead(potPin);
  int angle = map(potValue, 0, 1023, 0, 180);
  Serial.println(angle);
  myServo.write(angle);

  delay(20);
}