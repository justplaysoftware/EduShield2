#include <edushield2_7segment.h>

EduShield2_7segment es2;

void setup() {
  // put your setup code here, to run once:
  es2.showLeadingZero=false;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<100; i++) {
    es2.display_both(i);
    delay(50);
  }
}
