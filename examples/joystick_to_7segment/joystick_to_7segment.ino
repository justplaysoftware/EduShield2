#include <edushield2_7segment.h>

EduShield2_7segment es2;

void setup() {
  pinMode(A0, INPUT); // up/down
  pinMode(A1, INPUT); // left/right  
  es2.showLeadingZero = true;
}

void loop() {
  es2.displayDigits(
      map(analogRead(A0), 0, 1023, 0, 10), 
      map(analogRead(A1), 0, 1023, 0, 10));
 
}
