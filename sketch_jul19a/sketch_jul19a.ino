/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  Serial.println("90");
  myservo.write(90);     
  delay(1500);                       // waits 15ms for the servo to reach the position
  Serial.println("0");
  myservo.write(0);
  delay(1500);    
}
