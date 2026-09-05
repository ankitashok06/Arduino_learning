const int potPin = A4;
const int ledPin = 9;
void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(potPin, INPUT);
}

void loop() {
    int potValue = analogRead(potPin);
    int pwm = map(potValue, 0, 1023, 0, 255); // mapping values 
    Serial.println(pwm);
    analogWrite(ledPin, pwm);
   
    delay(20);
}