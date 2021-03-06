/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */
   
#include <Servo.h>

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin=9;       // Led pin at Arduino pin 9

//Variables
int value;          // Store value from photoresistor (0-1023)


Servo myservo;  // create servo object to control a servo

void setup(){
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
 pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 Serial.begin(9600);
}


void loop(){
  value = analogRead(pResistor);
  Serial.println(value);
  //You can change value "25"
  if (value > 125){
    myservo.write(0);
    digitalWrite(ledPin, LOW); //Turn led on
  }
  else{
    myservo.write(90);
    
    digitalWrite(ledPin, HIGH); //Turn led on
    delay(10000);
  }

  delay(250); //Small delay
}
