
//Define pines
#define PIN_D0 13
#define PIN_A0 A0
#define PIN_LED 9
bool state;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_A0, INPUT);
  digitalWrite(PIN_LED, LOW);
  Serial.begin(9600);
  state = false;
}

void loop() {
  int analog = analogRead(PIN_A0);
  Serial.print("Analog Read: ");
  Serial.println(analog);
  if ( analog > 200 ) //Si está activada la salida D0
  {
    state = ! state ;                       // cambiamos el estado del LED
    digitalWrite(PIN_LED, state) ;            // escribimos el nuevo valor
    delay (200);
  }
}
