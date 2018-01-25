#ifndef ControlPanel_h
#define ControlPanel_h

#include <Arduino.h>
#include <DigitalIO.h>
#include "KeyState.h"

#define BUTTONS 8
#define SWITCHES 8
#define POTS 16
#define ANALOG 2
#define MUX_CHANNELS 8

static int analogPins[ANALOG] = {
    0,
    1
};

class ControlPanel
{
  public:
    typedef enum{ OFF, ON } SwitchState;

    KeyState buttonStates[BUTTONS];
    SwitchState switchStates[SWITCHES];
    int potStates[POTS];

    DigitalPin<16> buttons;

    void setup();
	void updateRow(int row);
	
private:
	DigitalPin<11> muxA;
    DigitalPin<8> muxB;
    DigitalPin<7> muxC;

    DigitalPin<17> switches;
};

#endif /* ControlPanel_h */