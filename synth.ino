#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/saw2048_int8.h>
#include <tables/square_no_alias_2048_int8.h>
#include <tables/sin2048_int8.h>
#include <LowPassFilter.h>

Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw(SAW2048_DATA);
Oscil<SQUARE_NO_ALIAS_2048_NUM_CELLS, AUDIO_RATE> aSquare(SQUARE_NO_ALIAS_2048_DATA);
Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> lfo(SIN2048_DATA);

LowPassFilter lpf;
uint8_t mix;

void setup() {
  // put your setup code here, to run once:
  startMozzi();
  aSaw.setFreq(110);
  aSquare.setFreq(659);
  lfo.setFreq(5);
  // Serial.begin(9600);
}

void updateControl() {
  uint8_t resonance = mozziAnalogRead(0) / 4;
  uint8_t cutoff = mozziAnalogRead(1) / 4;
  mix = mozziAnalogRead(2) / 4;

  lpf.setResonance(resonance);
  lpf.setCutoffFreq(cutoff);
}

int updateAudio() {
  int8_t modulation = ((int16_t)(255 - mix) * aSquare.next() + (int16_t)mix * aSaw.next()) >> 9;
  int8_t asig = lpf.next(modulation >> 1);
  return (int8_t)((int16_t)(asig * lfo.next()) >> 8);
}

void loop() {
  audioHook();
}
