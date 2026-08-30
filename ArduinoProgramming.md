# Arduino Programming — Study Documentation

## Beginner Foundations → Intermediate Embedded Programming

**Progress:** Topics 1–11 completed
**Focus:** C/C++ programming fundamentals for Arduino/ESP32
**Learning approach:** First principles → theory → examples → robotics/embedded applications

---

# Table of Contents

1. Variables
2. Data Types & Memory
3. Constants
4. Operators
5. Conditions — `if`, `else if`, `else`
6. Type Casting & Type Conversion
7. Basic Input/Output
8. `switch-case`
9. Ternary Operator `?:`
10. `for` Loop
11. `while`, `do-while`, `break`, `continue`

---

# 1. Variables

## What I learned

A **variable** is a named place used by a program to store a value.

Instead of working directly with a value such as `150`, we give it a meaningful name.

### Example

```cpp
int motorSpeed = 150;
```

Here:

```text
int        → data type
motorSpeed → variable name
150        → stored value
```

The value of a variable can change:

```cpp
int speed = 100;

speed = 150;
```

Now:

```text
speed → 150
```

### Most important things to remember

* Variables store information.
* A variable has a name, type, and value.
* `=` means assignment.
* A variable's value can normally be changed.
* Good variable names make code easier to understand.

### Example

```cpp
int distance = 50;

distance = 30;
```

The variable `distance` first contains `50` and later contains `30`.

---

# 2. Data Types & Memory

## What I learned

A **data type** tells the program what kind of data a variable represents and affects its representation, size, and range on the target platform.

Important basic types:

```text
int   → whole numbers
float → decimal numbers
char  → one character
bool  → true/false
```

### Example

```cpp
int motorSpeed = 200;
float temperature = 27.5;
char command = 'F';
bool robotRunning = true;
```

## Bits and Bytes

A bit can contain:

```text
0 or 1
```

A byte contains:

```text
8 bits
```

Therefore:

$$
N\text{ bits} \rightarrow 2^N\text{ possible combinations}
$$

For example:

```text
8 bits → 256 combinations
0–255 for unsigned values
```

For a typical 16-bit signed `int`:

```text
-32,768 to 32,767
```

However, data type sizes can differ between microcontroller platforms.

### Overflow

When a value becomes too large for the available representation, overflow can occur.

For example, an 8-bit unsigned value can represent:

```text
0 → 255
```

So conceptually:

```text
255 + 1 → 0
```

### Most important things to remember

* Everything in a digital microcontroller is ultimately represented using bits.
* `1 byte = 8 bits`.
* More bits → more possible combinations.
* Data type size affects range and memory usage.
* Data type sizes can differ between boards such as Arduino Uno and ESP32.
* Overflow occurs when a value cannot be represented in the chosen type.

### Example

```cpp
unsigned char count = 255;
```

An 8-bit unsigned value has a maximum of 255.

---

# 3. Constants

## What I learned

A **constant** is a value that should not be modified during program execution.

Use the `const` keyword:

```cpp
const int ledPin = 2;
```

This tells the program that `ledPin` should not be modified.

### Variable vs Constant

```cpp
int motorSpeed = 100;
const int maxSpeed = 255;
```

`motorSpeed` can change:

```cpp
motorSpeed = 150;
```

but `maxSpeed` should not be reassigned.

### Why constants are useful

They are especially useful for fixed hardware configuration:

```cpp
const int motorPWM = 5;
const int motorDirection = 4;
```

### Most important things to remember

* Variable → value can change.
* `const` → value should not be modified.
* Constants improve safety and readability.
* Hardware configuration values are often good candidates for `const`.

### Example

```cpp
const int ledPin = 2;

pinMode(ledPin, OUTPUT);
```

Instead of repeatedly writing `2`, the program uses the meaningful name `ledPin`.

---

# 4. Operators

## What I learned

An **operator** tells the program to perform an operation on one or more values.

### Arithmetic Operators

```text
+   addition
-   subtraction
*   multiplication
/   division
%   remainder
```

### Assignment

```text
=   assignment
```

### Comparison

```text
==  equal
!=  not equal
>   greater than
<   less than
>=  greater than or equal
<=  less than or equal
```

### Logical

```text
&&  AND
||  OR
!   NOT
```

### Increment / Decrement

```text
++  increase by 1
--  decrease by 1
```

### Compound assignment

```text
+=
-=
*=
/=
```

### Bitwise introduction

```text
&   AND
|   OR
^   XOR
~   NOT
<<  left shift
>>  right shift
```

### Most important things to remember

* `=` means assignment.
* `==` means comparison.
* `%` gives the remainder.
* `&&`, `||`, and `!` are logical operators.
* `&`, `|`, `^` etc. are bitwise operators.
* `++` increases a value by 1.
* `--` decreases a value by 1.
* Integer division can discard the fractional part.

### Example

```cpp
int speed = 100;

speed = speed + 20;
```

Now:

```text
speed = 120
```

Another example:

```cpp
int a = 17;
int b = 5;

int x = a / b;   // 3
int y = a % b;   // 2
```

---

# 5. Conditions — `if`, `else if`, `else`

## What I learned

A **condition** is a question whose result can be true or false.

Example:

```cpp
distance < 20
```

If:

```text
distance = 15
```

then:

```text
15 < 20 → true
```

The `if` statement allows the program to make decisions.

### Basic structure

```cpp
if (condition) {
    // execute when true
}
```

### `if-else`

```cpp
if (condition) {
    // true
}
else {
    // false
}
```

### `else if`

Used when there are multiple conditions.

```cpp
if (distance < 10) {
    // very close
}
else if (distance < 30) {
    // close
}
else {
    // far
}
```

### Nested `if`

One `if` can be inside another.

### Most important things to remember

* A condition evaluates to true or false.
* `if` executes code when its condition is true.
* `else` handles the false case.
* `else if` handles additional conditions.
* Conditions can use logical operators.
* The order of conditions matters.
* Do not confuse `=` with `==`.

### Robotics example

```cpp
if (distance < 20) {
    Serial.println("STOP");
}
else {
    Serial.println("MOVE");
}
```

Mental model:

```text
Sensor
  ↓
Value
  ↓
Condition
  ↓
Decision
  ↓
Action
```

---

# 6. Type Casting & Type Conversion

## What I learned

**Type casting** means explicitly converting a value from one data type to another.

### Example

```cpp
int x = 10;
float y = (float)x;
```

Conceptually:

```text
int 10
 ↓
float 10.0
```

## Why casting matters

Consider:

```cpp
int a = 7;
int b = 2;

float result = a / b;
```

Because both values are integers:

```text
7 / 2 → 3
```

Then it becomes:

```text
3.0
```

But:

```cpp
float result = (float)a / b;
```

causes floating-point arithmetic:

```text
7.0 / 2 → 3.5
```

### Important distinction

```cpp
float result = a / b;
```

versus:

```cpp
float result = (float)a / b;
```

In the first case, integer division occurs **before** the result is stored in the float.

In the second case, the conversion occurs **before the division**.

### Float → int

```cpp
float temperature = 27.8;
int temp = (int)temperature;
```

The fractional part is lost:

```text
27.8 → 27
```

### Important lesson

```text
Casting ≠ rounding
```

### Most important things to remember

* Type casting converts a value to another type.
* Implicit conversion can happen automatically.
* Explicit casting is requested by the programmer.
* Casting can prevent unwanted integer division.
* Converting `float → int` can lose fractional information.
* Always ask: **"What information could be lost?"**

### Robotics example

```cpp
int adcValue = 2048;

float voltage = (float)adcValue * 3.3 / 4095.0;
```

The cast helps ensure the calculation is performed with floating-point precision.

---

# 7. Basic Input / Output

## What I learned

The fundamental embedded-system model is:

```text
INPUT
  ↓
PROCESSING
  ↓
OUTPUT
```

### Input

Information entering the system:

```text
button
sensor
encoder
PC
another microcontroller
```

### Output

Information or control leaving the system:

```text
LED
motor
servo
buzzer
display
PC
```

---

## Digital Input

Arduino provides:

```cpp
digitalRead(pin);
```

Example:

```cpp
int buttonState = digitalRead(buttonPin);
```

Conceptually:

```text
Button
 ↓
GPIO
 ↓
digitalRead()
 ↓
buttonState
```

---

## Digital Output

Arduino provides:

```cpp
digitalWrite(pin, HIGH);
digitalWrite(pin, LOW);
```

Conceptually:

```text
Program
 ↓
digitalWrite()
 ↓
GPIO
 ↓
LED / other hardware
```

---

## Serial Output

Initialize Serial:

```cpp
Serial.begin(115200);
```

Print:

```cpp
Serial.print("Speed = ");
Serial.println(speed);
```

Difference:

```text
print()   → stays on current line
println() → moves to next line
```

---

## Serial Input

Incoming serial data can be checked using:

```cpp
Serial.available()
```

and read using:

```cpp
Serial.read()
```

### Important distinction

```text
digitalRead() → reads a GPIO pin

Serial.read() → reads serial communication data
```

### Most important things to remember

* Embedded systems interact with the real world through I/O.
* Digital GPIO works with electrical HIGH/LOW states.
* Serial communication is different from GPIO.
* Serial Monitor is useful for communication and debugging.
* Hardware signals are ultimately electrical signals interpreted by the microcontroller.

### Example

```text
Button → ESP32 → LED
```

```cpp
int buttonState = digitalRead(buttonPin);

if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
}
```

---

# 8. `switch-case`

## What I learned

`switch-case` is useful when one variable can have several **discrete possible values**.

Think:

```text
if-else
→ "Is this condition true?"

switch-case
→ "Which value do I have?"
```

### Basic structure

```cpp
switch (command) {

    case 'F':
        // forward
        break;

    case 'B':
        // backward
        break;

    default:
        // invalid
}
```

### `break`

`break` exits the switch.

Without `break`, execution can continue into later cases. This is called **fall-through**.

### `default`

Handles values that do not match any case.

### `switch` vs `if-else`

Use:

```text
switch-case → exact discrete values
if-else     → ranges, conditions, complex logic
```

### Robotics example

```cpp
char command = 'L';

switch (command) {

    case 'F':
        Serial.println("FORWARD");
        break;

    case 'B':
        Serial.println("BACKWARD");
        break;

    case 'L':
        Serial.println("LEFT");
        break;

    case 'R':
        Serial.println("RIGHT");
        break;

    case 'S':
        Serial.println("STOP");
        break;

    default:
        Serial.println("INVALID");
}
```

### Most important things to remember

* `switch` compares one expression against discrete case values.
* `break` normally prevents fall-through.
* `default` handles unmatched values.
* `switch` is not ideal for ranges such as `distance < 20`.
* `switch` is very useful for robot commands and operating modes.

---

# 9. Ternary Operator `?:`

## What I learned

The ternary operator is a compact way to choose between **two values** based on a condition.

### Syntax

```cpp
condition ? value_if_true : value_if_false;
```

### Example

```cpp
int speed = 100;

int status = (speed > 0) ? 1 : 0;
```

Meaning:

```text
If speed > 0
    status = 1
otherwise
    status = 0
```

### Robotics example

```cpp
int distance = 15;

int motorSpeed = (distance < 20) ? 0 : 150;
```

Since:

```text
15 < 20 → true
```

therefore:

```text
motorSpeed = 0
```

### Most important things to remember

* Ternary has three parts.
* It is useful for simple two-way value selection.
* It returns a value.
* It is not always better than `if-else`.
* Avoid complicated nested ternary expressions.

### Mental model

```text
condition?
   ↓
YES → choose A
NO  → choose B
```

---

# 10. `for` Loop

## What I learned

A loop allows code to execute repeatedly.

A `for` loop is particularly useful when there is a clear:

```text
starting point
continuation condition
update
```

### Syntax

```cpp
for (initialization; condition; update) {
    // repeated code
}
```

Example:

```cpp
for (int i = 0; i < 5; i++) {
    Serial.println(i);
}
```

Output:

```text
0
1
2
3
4
```

### The three parts

```text
int i = 0
    ↓
initialization

i < 5
    ↓
condition

i++
    ↓
update
```

### Other patterns

Counting by 2:

```cpp
for (int i = 0; i <= 10; i += 2) {
    Serial.println(i);
}
```

Counting backwards:

```cpp
for (int i = 5; i >= 1; i--) {
    Serial.println(i);
}
```

### Most important things to remember

* Initialization happens once.
* The condition is checked before each iteration.
* The body executes when the condition is true.
* The update occurs after the body.
* `i < 5` and `i <= 5` are different.
* Incorrect updates can create infinite loops.
* `for` loops are useful for counter-based repetition.

### Mental model

```text
INITIALIZE
    ↓
CHECK
    ↓
TRUE?
 ↓      ↓
YES     NO
 ↓       ↓
BODY    EXIT
 ↓
UPDATE
 ↓
CHECK AGAIN
```

---

# 11. `while`, `do-while`, `break`, `continue`

## `while`

### What I learned

A `while` loop means:

> **Keep executing while the condition is true.**

### Syntax

```cpp
while (condition) {
    // repeat
}
```

Example:

```cpp
int i = 0;

while (i < 5) {
    Serial.println(i);
    i++;
}
```

### Important concept

`while` checks the condition **before** running the body.

Therefore:

```cpp
int i = 10;

while (i < 5) {
    Serial.println(i);
}
```

executes **zero times**.

---

# `do-while`

A `do-while` loop executes the body **at least once** before checking the condition.

### Syntax

```cpp
do {
    // execute
} while (condition);
```

Example:

```cpp
int i = 10;

do {
    Serial.println(i);
} while (i < 5);
```

It prints:

```text
10
```

because the body executes before the condition is checked.

### Core difference

```text
while
→ check first, then execute

do-while
→ execute first, then check
```

---

# `break`

`break` immediately exits the current loop.

Example:

```cpp
for (int i = 0; i < 10; i++) {

    if (i == 5) {
        break;
    }

    Serial.println(i);
}
```

Output:

```text
0
1
2
3
4
```

### Mental model

```text
break
 ↓
EXIT LOOP NOW
```

---

# `continue`

`continue` skips the remainder of the current iteration and moves toward the next iteration.

Example:

```cpp
for (int i = 0; i < 5; i++) {

    if (i == 2) {
        continue;
    }

    Serial.println(i);
}
```

Output:

```text
0
1
3
4
```

### Mental model

```text
continue
 ↓
SKIP THIS ITERATION
 ↓
NEXT ITERATION
```

---

# `break` vs `continue`

```text
break
→ stop the entire loop

continue
→ skip only the current iteration
```

---

# Important Infinite Loop Example

Consider:

```cpp
int i = 0;

while (i < 10) {

    if (i == 5) {
        continue;
    }

    Serial.println(i);
    i++;
}
```

When:

```text
i = 5
```

the program executes:

```cpp
continue;
```

So:

```cpp
i++;
```

is skipped.

Therefore `i` stays at 5 forever:

```text
5 < 10 → true
continue
5 < 10 → true
continue
5 < 10 → true
...
```

This creates an infinite loop.

### Most important things to remember

* `while` checks first.
* `do-while` executes first.
* `break` exits the loop.
* `continue` skips the current iteration.
* Always think about what will eventually make a loop condition false.
* Be especially careful with `continue` in `while` loops.

---

# Key Concepts Learned Today

## 1. Variable → Data

```text
Variable = named storage for information
```

## 2. Data Type → Representation

```text
int / float / char / bool
```

## 3. Constant → Fixed configuration

```cpp
const int ledPin = 2;
```

## 4. Operator → Perform an operation

```text
+ - * / % == > < && || !
```

## 5. Condition → Make a decision

```cpp
if (distance < 20)
```

## 6. Type Casting → Convert types

```cpp
(float)value
```

## 7. I/O → Connect program with the outside world

```text
INPUT → PROCESS → OUTPUT
```

## 8. `switch-case` → Select based on exact values

```text
F / B / L / R / S
```

## 9. Ternary → Simple two-way value selection

```cpp
condition ? A : B
```

## 10. Loops → Repeat code

```text
for
while
do-while
```

## 11. Loop control

```text
break    → exit
continue → skip current iteration
```

---

# Most Important Mental Models

### Programming flow

```text
INPUT
  ↓
STORE
  ↓
PROCESS
  ↓
COMPARE
  ↓
DECIDE
  ↓
OUTPUT
```

### Robotics flow

```text
SENSOR
  ↓
VARIABLE
  ↓
CALCULATION
  ↓
CONDITION
  ↓
DECISION
  ↓
MOTOR / ACTUATOR
```

### Loop flow

```text
START
 ↓
CHECK
 ↓
TRUE?
 ↓
EXECUTE
 ↓
UPDATE
 ↓
CHECK AGAIN
```

### Embedded programming mindset

Always ask:

```text
1. What data do I have?
2. What type should represent it?
3. Where is it stored?
4. What operation do I need?
5. What condition must be checked?
6. What should happen next?
7. What happens if the condition is false?
8. Will the loop eventually stop?
9. Can any information be lost?
10. How does this connect to the hardware?
```

---

# Today's Main Achievement

You have moved from simply writing individual Arduino statements toward understanding the **logic behind a program**.

The foundation you've built is:

```text
Variables
   ↓
Data Types
   ↓
Constants
   ↓
Operators
   ↓
Conditions
   ↓
Type Conversion
   ↓
Input / Output
   ↓
Decision Structures
   ↓
Loops
```

This foundation will be used directly in the next stage:

```text
Functions
↓
Arrays
↓
Strings
↓
Arduino Program Structure
↓
GPIO
↓
ADC
↓
PWM
↓
Sensors
↓
Motors
↓
Timing
↓
Interrupts
↓
Communication
↓
Intermediate Embedded Programming
```

**Current status: Topics 1–11 ✅ Complete**

**Next topic: Functions**
