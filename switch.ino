

void setup() {
  // Start Serial Monitor communication
  Serial.begin(9600);
}

void loop() {
  enum RobotMode {
    MANUAL,
    AUTONOMOUS,
    CALIBRATION,
    EMERGENCY
};

RobotMode mode = AUTONOMOUS;

switch (mode) {

    case MANUAL:
        Serial.println("Manual");
        break;

    case AUTONOMOUS:
        Serial.println("Autonomous");
        break;

    case CALIBRATION:
        Serial.println("Calibration");
        break;

    case EMERGENCY:
        Serial.println("Emergency");
        break;
}
delay(1000);
}
