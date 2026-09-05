```cpp
#include <Servo.h>

// Create a Servo object
Servo myServo;

// Servo signal pin
int servoPin = 9;

void setup() {
  // Attach the servo to pin 9
  myServo.attach(servoPin);
}

void loop() {

  // Move servo to 0 degrees
  myServo.write(0);
  delay(1000);

  // Move servo to 90 degrees
  myServo.write(90);
  delay(1000);

  // Move servo to 180 degrees
  myServo.write(180);
  delay(1000);
}
```
