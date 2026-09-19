#define SERVO_PIN 9

// Generate one servo control pulse and return pulse width
int servoPulse(int angle) {
  // Convert angle (0-180) to pulse width (500-2500 microseconds)
  int pulseWidth = map(angle, 0, 180, 500, 2500);

  // Generate one pulse
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(pulseWidth);

  digitalWrite(SERVO_PIN, LOW);
  delayMicroseconds(20000 - pulseWidth);

  return pulseWidth;
}

void setup() {
  Serial.begin(9600);
  pinMode(SERVO_PIN, OUTPUT);
}

void loop() {
  // Servo at 0 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(0);
  }
  Serial.print("0 degrees: ");
  Serial.println(servoPulse(0));
  delay(1000);
  // Servo at 30 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(30);
  }
  Serial.print("30 degrees: ");
  Serial.println(servoPulse(30));
  delay(1000);

  // Servo at 60 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(60);
  }
  Serial.print("60 degrees: ");
  Serial.println(servoPulse(60));
  delay(1000);
  // Servo at 90 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(90);
  }
  Serial.print("90 degrees: ");
  Serial.println(servoPulse(90));
delay(1000);
  // Servo at 120 degrees
  for (int i = 0; i < 100; i++) {
   servoPulse(120);
  }
  Serial.print("120 degrees: ");
  Serial.println(servoPulse(120));
delay(1000);
  // Servo at 150 degrees
  for (int i = 0; i < 100; i++) {
  servoPulse(150);
  }
  Serial.print("150 degrees: ");
  Serial.println(servoPulse(150));
delay(1000);
  // Servo at 180 degrees
  for (int i = 0; i < 100; i++) {
  servoPulse(180);
  }
  Serial.print("180 degrees: ");
  Serial.println(servoPulse(180));

  delay(1000);
}
