#include "Oscillator.h"
#include "mozzi_midi.h"

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

	return ((uint16_t)gain * signal) >> 8;
}

void Oscillator::updateFrequency() {
	int8_t midiNote = note + rangeModifier[range];
	Q16n16 majorSixthFreq = Q16n16_mtof(Q8n0_to_Q16n16(midiNote + 9));
	Q16n16 majorSixthLowFreq = Q16n16_mtof(Q8n0_to_Q16n16(midiNote - 3));
	Q16n16 freq = majorSixthLowFreq + detune * ((majorSixthFreq - majorSixthLowFreq) / (uint16_t)1023);
	aSaw.setFreq_Q16n16(freq);
	aSquare.setFreq_Q16n16(freq);
	aSin.setFreq_Q16n16(freq);
	aTriangle.setFreq_Q16n16(freq);
}

void Oscillator::setNote(int8_t note) {
	this->note = note;
}