// Source for Edu-Shield 2 7-Segment Display libraries
//
// JustPlay Software, Apr 2018
// v1.0.1 Apr 2018 - fixed setRGBColor( String )
// v1.0.6 Jan 2019 - bug fixes through 1.0.5, 1.0.6 fixed revA up/down reversal

#include "Arduino.h"
#include "edushield2_7segment.h"

EduShield2_7segment::EduShield2_7segment()
{
  _pinClock = _JP_CLOCK_PIN;
  _pinLatch = _JP_LATCH_PIN;
  _pinData = _JP_DATA_PIN;

  pinMode(_pinClock, OUTPUT);
  pinMode(_pinLatch, OUTPUT);
  pinMode(_pinData, OUTPUT);

  pinMode(_JP_BUTTON_1, INPUT);	// Button 1
  pinMode(_JP_BUTTON_2, INPUT);	// Button 2
  showLeftDec = 0;
  showRightDec = 0;
  showLeadingZero = _JP_SHOW_LEADING_ZERO;

  keypadType = _JP_KEYPAD_4x4;
  pinMode(_JP_KEYPAD_PIN, INPUT);
  
  // joystick
  joystickSensitivity = 1023;	// full sensitivity
  pinMode(_JP_JOYSTICK_UP_DOWN, INPUT);
  pinMode(_JP_JOYSTICK_LEFT_RIGHT, INPUT);
  
  }

  void EduShield2_7segment::begin()
  {
	  if (revA == true) 
	  {
	    _JP_UD_MIN = 0;
	    _JP_UD_MAX = 1023;
	    _JP_LR_MIN = 1023;
	    _JP_LR_MAX = 0;	
	    _JP_KEYPAD_PIN= 16;
	    _JP_GREEN_LED = 3;
	    _JP_BLUE_LED = 5;
	  } else {
	    _JP_UD_MIN = 0;
	    _JP_UD_MAX = 1023;
	    _JP_LR_MIN = 0;
	    _JP_LR_MAX = 1023;	
	    _JP_KEYPAD_PIN= 17;
	    _JP_GREEN_LED = 3;
	    _JP_BLUE_LED = 5;
	  }
	  pinMode( _JP_GREEN_LED, OUTPUT);
	  pinMode( _JP_BLUE_LED, OUTPUT);
  	  pinMode( _JP_RED_LED, OUTPUT);

  }

  void EduShield2_7segment::setRGB(int r, int g, int b)
  {
    	analogWrite(_JP_RED_LED, r);
	analogWrite(_JP_GREEN_LED, g);
	analogWrite(_JP_BLUE_LED, b);
	
  }

  /*
  void EduShield2_7segment::setRGBColor(long color)
  {
	  // split off the bit
	  int b = (color >> 16) & 0xFF;
	  int g = (color >> 8) & 0xFF;
	  int r = color & 0xFF;
	  
	  setRGB(r, g, b);
	  
  } */
  
  void EduShield2_7segment::setRGBColor(String color)
  {
	  int r=0;
	  int g=0;
	  int b=0;
	  
	  if ((color == "OFF" ) || (color == "BLACK"))  {
			r = 0;
			b = 0;
			g = 0;
	  } else if (color == "WHITE") {
			r = 255;
			g = 255;
			b = 255;
	  }	else if (color == "RED") {
			r = 255;
			b = 0;
			g = 0;
	  } else if (color == "GREEN") {
			r = 0;
			b = 0;
			g = 128;
	  } else if (color == "BLUE") {
			r = 0;
			b = 255;
			g = 0;
	  } else if (color == "YELLOW") {
			r = 255;
			b = 0;
			g = 255;
	  } else if ( color =="CYAN") {
			r = 0;
			b = 255;
			g = 255;
	  } else if ( color == "MAGENTA") {
			r = 255;
			b = 255;
			g = 0;
	  } else if ( color == "SILVER") {
			r = 192;
			b = 192;
			g = 192;
	  } else if (color == "GRAY") {
			r = 128;
			b = 128;
			g = 128;
	  } else if (color == "OLIVE") {
			r = 128;
			b = 0;
			g = 128;
	} else if ( color ==  "LIME") {
			r = 0;
			b = 0;
			g = 255;
	} else if ( color ==  "PURPLE") {
			r = 128;
			b = 128;
			g = 0;
	} else if ( color ==  "TEAL") {
			r = 0;
			b = 128;
			g = 128;
	} else if ( color ==  "NAVY") {
			r = 0;
			b = 128;
			g = 0;
	} else if ( color ==  "BROWN") {
			r = 139;
			b = 19;
			g = 69;
	} else if ( color ==  "ORANGE") {
			r = 255;
			b = 0;
			g = 165;
	} else if ( color ==  "GOLD") {
			r = 255;
			b = 0;
			g = 215;
	} else if ( color ==  "PINK") {
			r = 255;
			b = 203;
			g = 192;
	} else {
			r = 0;
			b = 0;
			g = 0;
	  }
	  
	  setRGB( r, g, b);	  
  }
  
  
int EduShield2_7segment::edushield2Translate(int n)
{
  int ret = 0;

  switch (n) {
    case 256:
      ret = 0;
      break;
    case 128:
      ret = 0;
    case 0:
      ret = 63;
      break;
    case 1:
      ret = 6;
      break;
    case 2:
      ret = 91;
      break;
    case 3:
      ret = 79;
      break;
    case 4:
      ret = 102;
      break;
    case 5:
      ret = 109;
      break;
    case 6:
      ret = 124;
      break;
    case 7:
      ret = 7;
      break;
    case 8:
      ret = 127;
      break;
    case 9:
      ret = 103;
      break;
    default:
      break;
  }

  return ret;
}

//case _JP_7SEG_A  119
//case _JP_7SEG_B  255
//case _JP_7SEG_C  57
//case _JP_7SEG_D  95
//case _JP_7SEG_E  121
//case _JP_7SEG_F  113
//case _JP_7SEG_H  118
//case _JP_7SEG_L  56
//case _JP_7SEG_P  115
//case _JP_7SEG_Y  110

void EduShield2_7segment::displayLeftDigit(int num) {
  displayDigits(num, 256);
}


void EduShield2_7segment::displayRightDigit(int num) {
  displayDigits(256, num);
}

void EduShield2_7segment::display_both(int num) {
  int t = (int) (num / 10);

  // special case if num == 256
  if (num == 256) {
    displayDigits(256, 256);
  } else {
    // so now t is the tens
    displayDigits(t, (num - (t * 10)));
  }

}

void EduShield2_7segment::showLeftDecimal(bool show) {
  if (show) showLeftDec = 128;
  else showLeftDec = 0;
}

void EduShield2_7segment::showRightDecimal(bool show) {
  if (show) showRightDec = 128;
  else showRightDec = 0;
}

void EduShield2_7segment::displayDigits(int left, int right) {
  // translate the digits when you display
  digitalWrite(_pinLatch, HIGH);
  shiftOut( _pinData, _pinClock, MSBFIRST, edushield2Translate(right) + showRightDec);
  if ((!showLeadingZero) && (left == 256)) {
    shiftOut( _pinData, _pinClock, MSBFIRST, showLeftDec);
  } else if ((!showLeadingZero) && (left == 0) ) {
    shiftOut( _pinData, _pinClock, MSBFIRST, showLeftDec);
  } else {
    shiftOut( _pinData, _pinClock, MSBFIRST, edushield2Translate(left) + showLeftDec);
  }
  digitalWrite(_pinLatch, LOW);
  delay(10);
  digitalWrite(_pinLatch, HIGH);
  delay(10);
  digitalWrite(_pinLatch, LOW);
}

/*
keypad membranes
  The Edu-Shield uses a resistor ladder with one analog value to read in order to save
  pins.  A 4x4 keypad would need 8 pins, but we use only one.
  The downside is that every keypad gives slightly different values, so we can 
  adjust the sensitivity 
  The default keypad is the 4x4 
  */
void EduShield2_7segment::setKeypadType(int keypad_type) {
	if ((keypad_type < 0) || (keypad_type > 2)) {
		keypadType = _JP_KEYPAD_4x4;
	} else {
		keypadType = keypad_type;
	}
}

char EduShield2_7segment::getKey() 
{
	char ret = '\0';
	
	// this is based on an analogRead of A7
	// in general, with a 4x4 keypad connected, the top row is in the 600s, 2nd row in 4-500s, 3rd row in 2-300s and bottom row ins 100s
	int a7 = analogRead(A7);
	
	if (a7 > 850) {
		// pressed the letter A7
		ret = 'A';
	} else if (( a7 > 760) && (a7 < 785)) {
		// pressed 3
		ret = '3';
	} else if (( a7 > 670) && (a7 < 700)) {
		// pressed 2
		ret = '2';
	} else if (( a7 > 604) && (a7 < 630)) {
		// pressed 1
		ret = '1';
	} else if (( a7 > 580) && (a7 < 605)) {
		ret = 'B';
	} else if (( a7 > 520) && (a7 < 540)) {
		ret = '6';
	} else if (( a7 > 460) && (a7 < 490)) {
		ret = '5';
	} else if (( a7 > 420) && (a7 < 445)) {
		ret = '4';
	} else if (( a7 > 375) && (a7 < 400)) {
		ret = 'C';
	} else if (( a7 > 338) && (a7 < 355)) {
		ret = '9';
	} else if (( a7 > 300) && (a7 < 325)) {
		ret = '8';
	} else if (( a7 > 265) && (a7 < 300)) {
		ret = '7';
	} else if (( a7 > 198) && (a7 < 215)) {
		ret = 'D';
	} else if (( a7 > 175) && (a7 < 190)) {
		ret = '#';
	} else if ((a7 > 155) && (a7 < 171)) {
		ret = '0';
	} else if (( a7 > 138) && (a7 < 153)) {
		ret = '*';
	}
	
	return ret;
}

int EduShield2_7segment::getKeyReading() {
	return analogRead(A7);
}

bool EduShield2_7segment::isButton1Pressed() {
	return digitalRead(_JP_BUTTON_1);
}

bool EduShield2_7segment::isButton2Pressed() {
	return digitalRead(_JP_BUTTON_2);
}

void EduShield2_7segment::readJoystick() {
	joyUD = map( analogRead(_JP_JOYSTICK_UP_DOWN), _JP_UD_MIN, _JP_UD_MAX, 0, joystickSensitivity );
	joyLR = map( analogRead(_JP_JOYSTICK_LEFT_RIGHT), _JP_LR_MIN, _JP_LR_MAX, 0, joystickSensitivity);
	
}

int EduShield2_7segment::readJoystickUD() {
	return map( analogRead(_JP_JOYSTICK_UP_DOWN), _JP_UD_MIN, _JP_UD_MAX, 0, joystickSensitivity );
	
}

int EduShield2_7segment::readJoystickLR() {
	return map( analogRead(_JP_JOYSTICK_LEFT_RIGHT), _JP_LR_MIN, _JP_LR_MAX, 0, joystickSensitivity);
	
}

bool EduShield2_7segment::joystickUp() {
	int old_sensitivity = joystickSensitivity;
	bool ret = false;
	
	joystickSensitivity = 5;
	
	
	if (readJoystickUD() > 2) ret = true;
	else ret = false;

	joystickSensitivity = old_sensitivity;

	return ret;
}

bool EduShield2_7segment::joystickDown() {
	int old_sensitivity = joystickSensitivity;
	bool ret = false;
	
	joystickSensitivity = 5;
		
	if (readJoystickUD() < 2) ret = true;
	else ret = false;
	
	joystickSensitivity = old_sensitivity;

	return ret;
}

bool EduShield2_7segment::joystickLeft() {
	int old_sensitivity = joystickSensitivity;
	
	joystickSensitivity = 5;
	readJoystick();
	joystickSensitivity = old_sensitivity;
	
	if (joyLR < 2) return true;
	return false;
}

bool EduShield2_7segment::joystickRight() {
	int old_sensitivity = joystickSensitivity;
	
	joystickSensitivity = 5;
	readJoystick();
	joystickSensitivity = old_sensitivity;
	
	if (joyLR > 2) return true;
	return false;
}

int EduShield2_7segment::joystickUpValue() {
	readJoystick();
	
	return joyUD;
}

int EduShield2_7segment::joystickDownValue() {
	readJoystick();
	
	return joyUD;
}

int EduShield2_7segment::joystickLeftValue() {
	readJoystick();
	
	return joyLR;
}

int EduShield2_7segment::joystickRightValue() {
	readJoystick();
	
	return joyLR;
}

void EduShield2_7segment::setJoystickSensitivity(int s) {

	joystickSensitivity = s;
}
