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

	KeyState stateChanges[KEYS];
	int stateChangesSize;

	void setup();
	void resetStateChanges();
	void updateRow(int row);

	int8_t getSequentialKeyNumber(int keyIndex);
	
private:
	DigitalPin<6> column0;
	DigitalPin<5> column1;
	DigitalPin<4> column2;
	DigitalPin<3> column3;
	DigitalPin<2> column4;

	void updateKey(int row, int column, bool input);
};

#endif /* Keyboard_h */