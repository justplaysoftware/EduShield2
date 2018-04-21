#include <edushield2_7segment.h>

int count = 0;
EduShield2_7segment es2;

void setup() {
  // put your setup code here, to run once:
  es2.showLeadingZero=true;
  es2.displayDigits(0, 1);
  delay(1000);
  es2.showLeftDecimal(true);
  es2.display_both(random(0, 100));
  delay(1000);
  es2.showRightDecimal(true);
  es2.display_both(random(0, 100));
  delay(1000);
  es2.showLeftDecimal(false);
  es2.display_both(random(0, 100));
  delay(1000);
  es2.showRightDecimal(false);
  es2.display_both(random(0, 100));
  delay(1000);
  // call 256 to turn the display off
  // if you send a 0 it displays the digit 0
  es2.display_both(256);
  es2.showLeadingZero=false;
  delay(1000);    
}

void loop() {
  // put your main code here, to run repeatedly:
  es2.showLeadingZero = true;
  es2.displayDigits(count, count);
  delay(1000);
  es2.displayLeftDigit(count);
  delay(1000);
  es2.displayRightDigit(count);
  delay(1000);
  es2.showLeadingZero = false;
  es2.display_both(random(0, 100));
  delay(1000);

  count++;
  if (count>9) count=0;
}
