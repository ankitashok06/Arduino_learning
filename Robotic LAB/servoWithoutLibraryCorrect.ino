#define SERVO_PIN 9

// Function to generate one servo control pulse
void servoPulse(int angle) {
  // Convert angle (0-180) to pulse width (1000-2000 microseconds)
  int pulseWidth = map(angle, 0, 180, 500, 2500);

  // Generate one pulse
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(pulseWidth);

  digitalWrite(SERVO_PIN, LOW);
  delayMicroseconds(20000 - pulseWidth);
}

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
}

void loop() {
  // Servo at 0 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(0);
  }
  for (int i = 0; i < 90; i++){
    servoPulse(i);
  }
  // Servo at 90 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(90);
  }
  for (int i = 90; i < 180; i++){
    servoPulse(i);
  }
  // Servo at 180 degrees
  for (int i = 0; i < 100; i++) {
    servoPulse(180);
  }
  for (int i = 180; i < 0; i--){
    servoPulse(i);
  }
}