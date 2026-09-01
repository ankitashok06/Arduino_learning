
// Store 5 sensor values
int sensorData[5] = {100, 110, 120, 130, 10};

void setup() {
  // Start Serial Monitor communication
  Serial.begin(9600);
}

void loop() {
  int sum = 0;

  // Add all sensor values
  for (int i = 0; i < 5; i++) {
    sum = sum + sensorData[i];
  }

  // Calculate average
  float average = (float)sum / 5;

  // Display average in Serial Monitor
  Serial.println(average);

  // Wait for 1 second
  delay(1000);
}
