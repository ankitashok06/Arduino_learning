void setup() {
  Serial.begin(9600);

}

void loop() {
  int a = 20;
  int b = 6;
  int add = a+b;
  int diff = a-b;
  int prod = a*b;
  int div = a/b;
  int rem = a%b;

  Serial.print("Addition: ");
  Serial.println(add);
  delay(2000);
  Serial.print("Subtraction: ");
  Serial.println(diff);
  delay(2000);
  Serial.print("Multiplication: ");
  Serial.println(prod);
  delay(2000);
  Serial.print("Division: ");
  Serial.println(div);
  delay(2000);
  Serial.println("Remainder: ");
  Serial.print(rem);
  delay(2000);
}
