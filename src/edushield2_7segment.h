// Edu-Shield 2 Library
// v1.0.1 by JustPlay Software, Apr 2018
//
// this file defines constants for
// the 7-segment display
#ifndef _JUSTPLAY_7SEG_H
#define _JUSTPLAY_7SEG_H

#include "Arduino.h"

// only uncomment this if you have an Edu-Shield 2 Rev A (see back)
//#define _JP_EDUSHIELD2_REVA

// Edu-Shield 2 constants that are different between Rev A and Rev B
// the first rev A of the EduShield 2 had the joysticks reversed
// at the top, uncomment #define _JP_EDUSHIELD2_REVA 
#ifdef _JP_EDUSHIELD2_REVA
  #define _JP_UD_MIN  1023
  #define _JP_UD_MAX  0
  #define _JP_LR_MIN  1023
  #define _JP_LR_MAX  0
  #define _JP_KEYPAD_PIN	A3
  #define _JP_GREEN_LED	3
  #define _JP_BLUE_LED	5
#else
  #define _JP_UD_MIN  0
  #define _JP_UD_MAX  1023
  #define _JP_LR_MIN  0
  #define _JP_LR_MAX  1023	
  #define _JP_KEYPAD_PIN	A7
  #define _JP_GREEN_LED	3
  #define _JP_BLUE_LED	5
#endif

//  YOU SHOULD NOT NEED TO CUSTOMIZE ANYTHING BELOW HERE

// you can customize this but you shouldn't need to
#define _JP_SHOW_LEADING_ZERO false
#define _JP_CLOCK_PIN 11
#define _JP_LATCH_PIN 8
#define _JP_DATA_PIN 6
#define _JP_BUTTON_1 2
#define _JP_BUTTON_2 12
#define _JP_RED_LED 10
#define _JP_JOYSTICK_UP_DOWN A0
#define _JP_JOYSTICK_LEFT_RIGHT A1


// here are the numbers
#define _JP_7SEG_0  63
#define _JP_7SEG_1  6
#define _JP_7SEG_2  91
#define _JP_7SEG_3  79
#define _JP_7SEG_4  102
#define _JP_7SEG_5  109
#define _JP_7SEG_6  124
#define _JP_7SEG_7  7
#define _JP_7SEG_8  127
#define _JP_7SEG_9  103
// #define _JP_7SEG_DP for the DP, add 128 to the number

#define _JP_7SEG_A  119
#define _JP_7SEG_B  255
#define _JP_7SEG_C  57
#define _JP_7SEG_D  95
#define _JP_7SEG_E  121
#define _JP_7SEG_F  113
#define _JP_7SEG_H  118
#define _JP_7SEG_L  56
#define _JP_7SEG_P  115
#define _JP_7SEG_Y  110

#define _JP_KEYPAD_4x4	0
#define _JP_KEYPAD_3x4	1
#define _JP_KEYPAD_1x4	2


class EduShield2_7segment
{
  public:
    EduShield2_7segment();
        void begin();
        void displayLeftDigit(int num);
        void displayRightDigit(int num);
        void displayDigits(int left, int right);
        void display_both(int num);
        bool showLeadingZero;
        void showLeftDecimal(bool show);
        void showRightDecimal(bool show);
        void setKeypadType(int keypad_type);
	char getKey();
	int  getKeyReading();
	bool isButton1Pressed();
	bool isButton2Pressed();
	bool joystickUp();
	bool joystickDown();
	bool joystickLeft();
	bool joystickRight();
	int  joystickUpValue();
	int  joystickDownValue();
	int  joystickLeftValue();
	int  joystickRightValue();
	void setJoystickSensitivity(int sensitivity);
	void setRGB(int red, int green, int blue);
	void setRGBColor(String color);
	
  private:
    int _pinClock;
    int _pinData;
    int _pinLatch;
	int joystickSensitivity;
    int edushield2Translate(int num);
    int showLeftDec;
    int showRightDec;
	int keypadType;
	void readJoystick();
	int joyLR;
	int joyUD;
	int readJoystickUD();
	int readJoystickLR();
	
};


#endif
