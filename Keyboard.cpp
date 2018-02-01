#include "Keyboard.h"

void Keyboard::setup() {
	column0.mode(INPUT);
	column1.mode(INPUT);
	column2.mode(INPUT);
	column3.mode(INPUT);
	column4.mode(INPUT);
}

void Keyboard::resetStateChanges() {
	stateChangesSize = 0;
}

void Keyboard::updateRow(int row) {
	updateKey(row, 0, column0.read());
	updateKey(row, 1, column1.read());
	updateKey(row, 2, column2.read());
	updateKey(row, 3, column3.read());
	updateKey(row, 4, column4.read());
}

void Keyboard::updateKey(int row, int column, bool input) {
	KeyState oldState = keyboardState[row * COL_PINS + column];
	KeyState newState = getNextState(input, keyboardState[row * COL_PINS + column]);
	keyboardState[row * COL_PINS + column] = newState;
	if (oldState != newState) stateChanges[stateChangesSize++] = row * COL_PINS + column;
}

int8_t Keyboard::getSequentialKeyNumber(int keyIndex) {
	// (keyIndex % COL_PINS) * ROWS + keyIndex / COL_PINS;
	// A % B = A - B * (A / B)
	return ROWS * keyIndex - (COL_PINS * ROWS - 1) * (keyIndex / COL_PINS);
}