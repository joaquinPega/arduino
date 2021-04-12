/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */
// Include the Arduino Stepper.h library:
#include <Stepper.h>
// Define number of steps per rotation:
#define STEPS 100

const int stepsPerRevolution = 2048;
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
int val = 0;
int previous = 0;
void setup() {
  // Set the speed to 5 rpm:
  myStepper.setSpeed(15);
  
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
}
void loop() {
  // get the sensor value
  int val = analogRead(A2);
  int newVal= val - previous;

  // move a number of steps equal to the change in the
  // sensor reading
  myStepper.step(newVal);
  Serial.println(newVal);

  // remember the previous value of the sensor
  previous = val;
  delay(100);
}
