const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 Serial.begin(9600);
}
void loop() {
 // Generate Trigger Pulse
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 
 digitalWrite(trigPin, LOW);
 
  // Measure echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  //Calculating Distance in cm 
  distance = duration / 58.0;

  //Display result

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);

}
