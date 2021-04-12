// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonState = 0; 
void buttonPush() {
  lcd.print("Exception");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Digital pin 2 maps to interrupt 0
  attachInterrupt(7/*PIN_BUTTON*/, buttonPush, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(7);
   if (buttonState == HIGH) {
    // turn LED on:
    lcd.clear();
    lcd.print("apreto");
  } else {
    // turn LED off:
    lcd.clear();
    lcd.print("No apreto");
  }
}
