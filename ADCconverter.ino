// ADC0809 interfacing with Arduino Uno

// DO-D7 -> Arduino D2-D9

const int dataPins [8] = { 2, 3, 4, 5, 6, 7, 8, 9 };

const int A_PIN =10;
const int B_PIN = 11;
const int C_PIN = 12;

const int ALE_PIN = A0;
const int START_PIN= A1;
const int EOC_PIN = A2;
const int OE_PIN = A3;

void setup() {
  Serial.begin(9600);

for (int i=0; i<8; i++){
  pinMode(dataPins[i], INPUT);
}
pinMode(A_PIN, OUTPUT);
pinMode(B_PIN, OUTPUT);
pinMode(C_PIN, OUTPUT);

pinMode(ALE_PIN, OUTPUT);
pinMode(START_PIN, OUTPUT);
pinMode(EOC_PIN, INPUT);
pinMode(OE_PIN, OUTPUT);

digitalWrite(ALE_PIN, LOW);
digitalWrite(START_PIN, LOW);
digitalWrite(OE_PIN, LOW);

Serial.println("ADC0809 Interface");
}


byte readADC0809() {

// Select channel INO
digitalWrite(A_PIN, HIGH);
digitalWrite(B_PIN, LOW);
digitalWrite(C_PIN, LOW);

// Latch channel address

digitalWrite(ALE_PIN, HIGH);
delayMicroseconds(1);
digitalWrite(ALE_PIN, LOW);

// Start conversion
digitalWrite (START_PIN, HIGH);
delayMicroseconds(1);
digitalWrite(START_PIN, LOW);

// Wait for conversion to complete
// EOC polarity should be verified for the particular ADC0809 circuit.

while (digitalRead(EOC_PIN) == LOW) {
// Wait
}

// Enable ADC output
digitalWrite(OE_PIN, HIGH);
delayMicroseconds(1);

byte value = 0;

for (int i=0; i<8; i++){
  if (digitalRead(dataPins[i])){
    value |= (1 << i);
  }
}
digitalWrite(OE_PIN, LOW);
return value;

}
void loop() {

byte adcValue = readADC0809();

float voltage = (adcValue * 5.0) / 255.0;

Serial.print("ADC Value = ");
Serial.print(adcValue);
Serial.print(" Voltage = ");
Serial.print(voltage, 3);
Serial.println(" V");

delay(500);
}