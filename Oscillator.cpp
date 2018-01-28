#include "Oscillator.h"

int8_t Oscillator::next() {
	int8_t signal = 0;

	if (enabled) {
    switch (waveform) {
      case Saw:
				signal = aSaw.next();
				break;
      case Square:
				signal = aSquare.next();
				break;
      case Sine:
				signal = aSin.next();
				break;
      case Triangle:
				signal = aTriangle.next();
				break;
    }
  }

	return ((int16_t)gain * signal) >> 7;
}