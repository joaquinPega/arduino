#include <IRremote.h>

#define PIN_IR 3
#define PIN_DETECT 2
#define PIN_STATUS 13

IRsend irsend;
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_DETECT, INPUT);
  pinMode(PIN_STATUS, OUTPUT);
  irsend.enableIROut(38);
  irsend.mark(0);
}

void loop() {
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT));
  Serial.println(PIN_STATUS);
  Serial.println(PIN_DETECT);
  delay(250);
}
