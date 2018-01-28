#include "Oscillator.h"

int8_t Oscillator::next() {
	// int8_t saw = aSaw.next();
	// int8_t square = aSquare.next();
	// int8_t sin = aSin.next();
	// int8_t triangle = aTriangle.next();

	unsigned long phaseFractional = aSaw.getPhaseFractional();
	int8_t saw = aSaw.next();

	int8_t wave = waveformMask[waveform];
	int8_t signal = 0;
	// if (enabled) signal = (wave & waveformMask[0]) * saw + ((wave & waveformMask[1]) >> 1) * square + ((wave & waveformMask[2]) >> 2) * sin + ((wave & waveformMask[3]) >> 3) * triangle;

	if (enabled) {
    switch (waveform) {
      case Saw:
				signal = saw;
				break;
      case Square:
				// aSquare.setPhaseFractional(phaseFractional);
				signal = aSquare.next();
				break;
      case Sine:
				// aSin.setPhaseFractional(phaseFractional);
				signal = aSin.next();
				break;
      case Triangle:
				// aTriangle.setPhaseFractional(phaseFractional);
				signal = aTriangle.next();
				break;
    }
  }

	return ((int16_t)gain * signal) >> 7;
}