#include <DigitalIO.h>
#include "Keyboard.h"
#include "ControlPanel.h"

DigitalPin<13> clock4017;
DigitalPin<12> reset4017;

Keyboard keyboard;
ControlPanel controlPanel;

void setup() {
    clock4017.mode(OUTPUT);
    reset4017.mode(OUTPUT);

    controlPanel.setup();
    keyboard.setup();

    reset4017.write(HIGH);
    reset4017.write(LOW);

    Serial.begin(230400);
}

void loop() {
    delay(100);

    Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < ROWS; i++) {
        keyboard.updateRow(i);
        Serial.print("Row ");
        Serial.print(i);
        Serial.print(": ");

        Serial.print(keyboard.keyboardState[i * COL_PINS]);
        Serial.print(", ");
        Serial.print(keyboard.keyboardState[i * COL_PINS + 1]);
        Serial.print(", ");
        Serial.print(keyboard.keyboardState[i * COL_PINS + 2]);
        Serial.print(", ");
        Serial.print(keyboard.keyboardState[i * COL_PINS + 3]);
        Serial.print(", ");
        Serial.println(keyboard.keyboardState[i * COL_PINS + 4]);

        clock4017.write(HIGH);
        clock4017.write(LOW);
    }

    for (int i = 0; i < 8; i++) {
        controlPanel.updateRow(i);

        Serial.print("Analog ");
        Serial.print(i);
        Serial.print(": ");

        Serial.print(HIGH & i);
        Serial.print(", ");
        Serial.print(HIGH & i >> 1);
        Serial.print(", ");
        Serial.print(HIGH & i >> 2);
        Serial.print(". Analog: ");
        Serial.print(controlPanel.potStates[i]);
        Serial.print(", ");
        Serial.print(controlPanel.potStates[MUX_CHANNELS + i]);

        Serial.print(". Digital: ");
        Serial.print(controlPanel.buttonStates[i]);
        Serial.print(", ");
        Serial.println(controlPanel.switchStates[i]);
    }
}
