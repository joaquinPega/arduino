
#define ROW_1 10
#define ROW_2 11
#define ROW_3 12
#define ROW_4 13
#define ROW_5 A0
#define ROW_6 A1
#define ROW_7 A2
#define ROW_8 A3

#define COL_1 2
#define COL_2 3
#define COL_3 4
#define COL_4 5
#define COL_5 6
#define COL_6 7
#define COL_7 8
#define COL_8 9
// 2-dimensional array of column pin numbers:
const int cols[8] = {
  2, 3, 4, 5, 6, 7, 8, 9
};
const int rows[8] = {
  10, 11, 12, 13, A0, A1, A2, A3
};

unsigned long previousMillis = 0;

const long interval = 120;

int counter=0;

String star1[] = {"00111100", "01111110", "11111100", "11111000", "11111100", "01111110", "00111100", "00000000"};
String star2[] = {"01000000", "00100011", "00010011", "00000011", "00111111", "00011110", "00001100", "00011110"};
String star3[] = {"01100110", "11100111", "11111111", "01011010", "00111100", "00111100", "01011010", "10000001"};
String star4[] = {"00000000", "01100011", "00111110", "01111111", "01011101", "01111111", "01100011", "00111110"};
String star5[] = {"00011000", "01011000", "10010000", "11111110", "00111001", "00111000", "00101000", "01101100"};
void setup() {
  for (byte i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);

}

void loop() {
  if(counter < 50){
    displayImage(star1);   
  }else if(counter<100){
    displayImage(star2);
  }else if(counter<150){
    displayImage(star3);
  }else if(counter<200){
    displayImage(star4);
  }else if(counter<250){
    displayImage(star5);
  }else{
    counter=0;
  }
 counter++;
}

void displayImage(String image[]) {
  for (int row = 0 ; row < 8; row++) {
    for (int col = 0 ; col < 8; col++) {
      if (image[row][col] == '1') {
        digitalWrite(rows[row], HIGH);
      }
      for (byte i = 0; i < 8; i++) {
        if ((col == i) ) {
          digitalWrite(cols[i], LOW);
        } else {
          digitalWrite(cols[i], HIGH);
        }

      }
      delayMicroseconds(100);
      digitalWrite(rows[row], LOW);
      digitalWrite(cols[col], HIGH);
      delayMicroseconds(100);
    }
  }

}
