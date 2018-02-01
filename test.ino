// #include <DigitalIO.h>
// #include "Keyboard.h"
// #include "ControlPanel.h"

// DigitalPin<13> clock4017;
// DigitalPin<12> reset4017;

// Keyboard keyboard;
// ControlPanel controlPanel;

// int8_t currentNote = 50;

// void setup() {
//     clock4017.mode(OUTPUT);
//     reset4017.mode(OUTPUT);

//     controlPanel.setup();
//     keyboard.setup();

//     reset4017.write(HIGH);
//     reset4017.write(LOW);

//     Serial.begin(230400);
// }

// void loop() {
//     delay(100);
//     keyboard.resetStateChanges();
//     // Serial.print("\n\n\n\n\n\n\n\n\n");
//     for (int i = 0; i < ROWS; i++) {
//         keyboard.updateRow(i);
//         // Serial.print("Row ");
//         // Serial.print(i);
//         // Serial.print(": ");

//         // Serial.print(keyboard.keyboardState[i * COL_PINS]);
//         // Serial.print(", ");
//         // Serial.print(keyboard.keyboardState[i * COL_PINS + 1]);
//         // Serial.print(", ");
//         // Serial.print(keyboard.keyboardState[i * COL_PINS + 2]);
//         // Serial.print(", ");
//         // Serial.print(keyboard.keyboardState[i * COL_PINS + 3]);
//         // Serial.print(", ");
//         // Serial.println(keyboard.keyboardState[i * COL_PINS + 4]);

//         clock4017.write(HIGH);
//         clock4017.write(LOW);
//     }

//     for (int i = 0; i < 8; i++) {
//         controlPanel.updateRow(i);

//         // Serial.print("Analog ");
//         // Serial.print(i);
//         // Serial.print(": ");

//         // Serial.print(HIGH & i);
//         // Serial.print(", ");
//         // Serial.print(HIGH & i >> 1);
//         // Serial.print(", ");
//         // Serial.print(HIGH & i >> 2);
//         // Serial.print(". Analog: ");
//         // Serial.print(controlPanel.potStates[i]);
//         // Serial.print(", ");
//         // Serial.print(controlPanel.potStates[MUX_CHANNELS + i]);

//         // Serial.print(". Digital: ");
//         // Serial.print(controlPanel.buttonStates[i]);
//         // Serial.print(", ");
//         // Serial.println(controlPanel.switchStates[i]);
//     }

//     // for (int i = 0; i < keyboard.stateChangesSize; i++) {
//     //     if (i == 0) Serial.print("[");
//     //     Serial.print(keyboard.getSequentialKeyNumber(keyboard.stateChanges[i]));
//     //     if (i < keyboard.stateChangesSize - 1) Serial.print(", ");
//     //     else Serial.println("]");
//     // }

//     for (int i = 0; i < keyboard.stateChangesSize; i++) {
// 		int8_t noteIndex = keyboard.stateChanges[i];
// 		KeyState state = keyboard.keyboardState[noteIndex];
//         int8_t note = keyboard.getSequentialKeyNumber(noteIndex);

//         if (state == PRESSED && note < currentNote) {
// 			currentNote = note;
// 			Serial.print("Note ");
//             Serial.print(currentNote);
//             Serial.println(" ON");
//         }

// 		if (state == RELEASED && note == currentNote) {
//             Serial.print("Note ");
//             Serial.print(currentNote);
//             Serial.println(" OFF");
//             currentNote = 50;
//         }
// 	}
// }