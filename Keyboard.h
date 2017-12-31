#include <Arduino.h>
#include <DigitalIO.h>

#define KEYS 50
#define COL_PINS 5
#define ROWS 10

class Keyboard {
public:
	typedef enum{ IDLE, PRESSED, HOLD, RELEASED } KeyState;
	
	KeyState keyboardState[KEYS];

	void setup();
	void updateRow(int row);
	
private:
	DigitalPin<6> column0;
	DigitalPin<5> column1;
	DigitalPin<4> column2;
	DigitalPin<3> column3;
	DigitalPin<2> column4;

	KeyState getNextState(int pressed, KeyState key);
};