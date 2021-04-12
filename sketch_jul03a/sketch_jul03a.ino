/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};
byte fuckYou[8] = {
  B00000,
  B00100,
  B00100,
  B00100,
  B11111,
  B11111,
  B01110,
};

byte hand[8] = {
  B00100,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111,
  B01110,
};

byte scisor[8] = {
  B10001,
  B01010,
  B00100,
  B01110,
  B11111,
  B11111,
  B01110,
};

void setup() {
  lcd.createChar(0, fuckYou);
  lcd.createChar(1, smiley);
  lcd.createChar(2, hand);
  lcd.createChar(3, scisor);
  lcd.begin(16, 2);  
  lcd.write(byte(0));
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(3,0);
  lcd.write(byte(3));
}

void loop() {}
