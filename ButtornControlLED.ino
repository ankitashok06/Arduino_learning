const int buttonPin = 4;
const int ledPin = 2;

void setup() {
    Serial.begin(115200);

    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {

    int buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Button pressed");
    }
    else {
        digitalWrite(ledPin, LOW);
        Serial.println("Button released");
    }
}