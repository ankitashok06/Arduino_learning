
// Store 5 sensor values
int sensorData[5] = {100, 110, 120, 130, 10};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum = sum + sensorData[i];
  }
  float average = (float)sum / 5;
  
  Serial.println(average);
  
  delay(1000);
}
