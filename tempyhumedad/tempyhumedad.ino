
#include "DHT.h"
// include the library code:
#include <LiquidCrystal.h>

#include <math.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
#define DHTPIN 7
// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  dht.begin();
  Serial.begin(9600);
}
void loop() {
  float h = dht.readHumidity();
  if (!isnan(h)) {
    lcd.setCursor(0, 0);
    lcd.print("Humedad: ");
    lcd.print(h);
  } else {
    Serial.println("Error humedad");
  }
  float t = dht.readTemperature();
  if (!isnan(t)) {
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);

    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, round(t));
  } else {
    Serial.println("Error Temperatura");
  }
}
