#include "ControlPanel.h"

void ControlPanel::setup() {
    muxA.mode(OUTPUT);
    muxB.mode(OUTPUT);
    muxC.mode(OUTPUT);

    buttons.mode(INPUT);
    switches.mode(INPUT);

    muxA.write(LOW);
    muxB.write(LOW);
    muxC.write(LOW);
}

void ControlPanel::updateRow(int row) {
    muxA.write(HIGH & row);
    muxB.write(HIGH & row >> 1);
    muxC.write(HIGH & row >> 2);

    for (int i = 0; i < ANALOG; i++) {
        potStates[i * MUX_CHANNELS + row] = analogRead(i);
    }

    switchStates[row] = (SwitchState)switches.read();
    buttonStates[row] = getNextState(buttons.read(), buttonStates[row]);
}