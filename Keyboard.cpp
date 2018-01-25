#include "Keyboard.h"

void Keyboard::setup() {
	column0.mode(INPUT);
	column1.mode(INPUT);
	column2.mode(INPUT);
	column3.mode(INPUT);
	column4.mode(INPUT);
}

void Keyboard::updateRow(int row) {
	keyboardState[row * COL_PINS] = getNextState(column0.read(), keyboardState[row * COL_PINS]);
	keyboardState[row * COL_PINS + 1] = getNextState(column1.read(), keyboardState[row * COL_PINS + 1]);
	keyboardState[row * COL_PINS + 2] = getNextState(column2.read(), keyboardState[row * COL_PINS + 2]);
	keyboardState[row * COL_PINS + 3] = getNextState(column3.read(), keyboardState[row * COL_PINS + 3]);
	keyboardState[row * COL_PINS + 4] = getNextState(column4.read(), keyboardState[row * COL_PINS + 4]);
}