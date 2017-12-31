#include <DigitalIO.h>
#include "Keyboard.h"

DigitalPin<13> clock4017;
DigitalPin<12> reset4017;

DigitalPin<11> muxA;
DigitalPin<8> muxB;
DigitalPin<7> muxC;

Keyboard keyboard;

// void setup() {
//     clock4017.mode(OUTPUT);
//     reset4017.mode(OUTPUT);

//     muxA.mode(OUTPUT);
//     muxB.mode(OUTPUT);
//     muxC.mode(OUTPUT);

//     keyboard.setup();

//     reset4017.write(HIGH);
//     reset4017.write(LOW);

//     Serial.begin(115200);
// }

// void loop() {
//     delay(100);

//     Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//     for (int i = 0; i < ROWS; i++) {
//         keyboard.updateRow(i);
//         Serial.print("Row ");
//         Serial.print(i);
//         Serial.print(": ");

//         Serial.print(keyboard.keyboardState[i * COL_PINS]);
//         Serial.print(", ");
//         Serial.print(keyboard.keyboardState[i * COL_PINS + 1]);
//         Serial.print(", ");
//         Serial.print(keyboard.keyboardState[i * COL_PINS + 2]);
//         Serial.print(", ");
//         Serial.print(keyboard.keyboardState[i * COL_PINS + 3]);
//         Serial.print(", ");
//         Serial.println(keyboard.keyboardState[i * COL_PINS + 4]);

//         clock4017.write(HIGH);
//         clock4017.write(LOW);
//     }

//     for (int i = 0; i < 8; i++) {
//         Serial.print("Analog ");
//         Serial.print(i);
//         Serial.print(": ");

//         Serial.print(HIGH & i);
//         Serial.print(", ");
//         Serial.print(HIGH & i >> 1);
//         Serial.print(", ");
//         Serial.print(HIGH & i >> 2);
//         Serial.print(". Value: ");
//         Serial.println((int)analogRead(0));

//         muxA.write(HIGH & i);
//         muxB.write(HIGH & i >> 1);
//         muxC.write(HIGH & i >> 2);
//     }
// }
