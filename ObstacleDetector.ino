int distance = 15;

void setup() {
    Serial.begin(115200);

    if (distance < 20) {
        Serial.println("Obstacle detected");
    }
    else {
        Serial.println("Path clear");
    }
}

void loop() {
}