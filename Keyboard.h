#ifndef Keyboard_h
#define Keyboard_h

#include <Arduino.h>
#include <DigitalIO.h>
#include "KeyState.h"

#define KEYS 50
#define COL_PINS 5
#define ROWS 10

class Keyboard {
public:
	KeyState keyboardState[KEYS];

	void setup();
	void updateRow(int row);
	
private:
	DigitalPin<6> column0;
	DigitalPin<5> column1;
	DigitalPin<4> column2;
	DigitalPin<3> column3;
	DigitalPin<2> column4;
};

#endif /* Keyboard_h */