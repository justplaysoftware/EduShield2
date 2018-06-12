// Edu-Shield 2 Library
// v1.0.5 by JustPlay Software, June 2018
//
// this file defines constants for
// the 7-segment display
#ifndef _JUSTPLAY_7SEG_H
#define _JUSTPLAY_7SEG_H

#include "Arduino.h"

// if you have Rev A of the Edu-Shield board, then
// before you call EduShield2_7segment.begin() you
// must set EduShield2_7segment.revA = true;
// then call begin()

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
#define _JP_PR_MAX_READINGS 300

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
	bool revA = false;
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
	void pulseRate_Observe();
	void pulseRate_Startup(int pulsePin, int delayTime, bool displayLed, bool displayVals, bool beep);
	int pulseRate_getBPM();
	
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
	int _JP_UD_MIN=1023;
        int _JP_UD_MAX=0;
        int _JP_LR_MIN = 1023;
        int _JP_LR_MAX = 0;
        int _JP_KEYPAD_PIN=17;
        int _JP_GREEN_LED=3;
        int _JP_BLUE_LED=5;
	// this is to support the pulse rate sensor
	int pr_pulsePin = A5;
	int pr_fadePin = 5;
	int pr_beats = 0;
	long pr_start = 0;
	long pr_last = 0;
	int pr_maxPulse = 600;
	int pr_ave = 0;
	int pr_minPulse = 0;
	int pr_threshold = 500;
	int pr_val = 0;
	bool pr_useSerial = true;
	bool pr_sawBeat = false;
	long pr_timemillis = 0;
	int pr_vals[_JP_PR_MAX_READINGS];
	int pr_reading = 0;
	int pr_delayTime = 0;
	bool pr_displayLed = true;
	bool pr_displayVals = true;
	bool pr_beep = false;
	int pr_bpm = 0;
	int calcAve();
	void printVals(int test);
};


#endif
