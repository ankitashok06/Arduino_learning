
const int ledPin = 13;
const int pushButton = 10;
void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
    int buttonState = digitalRead(pushButton);
    if(buttonState == LOW){
	digitalWrite(ledPin,HIGH);
    Serial.println("LED ON");
    }
    else{
    Serial.println("LED OFF");
	digitalWrite(ledPin,LOW);
    }
    delay(1000);
    
}