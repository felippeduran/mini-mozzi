#include <MozziGuts.h>
#include <Oscil.h>
#include <LowPassFilter.h>

#include <DigitalIO.h>
#include "Keyboard.h"
#include "ControlPanel.h"
#include "Oscillator.h"

DigitalPin<13> clock4017;
DigitalPin<12> reset4017;

Keyboard keyboard;
ControlPanel controlPanel;

Oscillator oscil1;
Oscillator oscil2;
Oscillator oscil3;

LowPassFilter lpf;

void setup() {
  clock4017.mode(OUTPUT);
  reset4017.mode(OUTPUT);

  controlPanel.setup();
  keyboard.setup();

  reset4017.write(HIGH);
  reset4017.write(LOW);

  startMozzi();

  oscil1.aSin.setFreq(440);
  oscil1.aSquare.setFreq(440);
  oscil1.aSaw.setFreq(440);
  oscil1.aTriangle.setFreq(440);

  oscil2.aSin.setFreq(220);
  oscil2.aSquare.setFreq(220);
  oscil2.aSaw.setFreq(220);
  oscil2.aTriangle.setFreq(220);

  oscil3.aSin.setFreq(653);
  oscil3.aSquare.setFreq(653);
  oscil3.aSaw.setFreq(653);
  oscil3.aTriangle.setFreq(653);
}

void updateControl() {
  updateParameters();
  updateState();
}

void updateParameters() {
  for (int i = 0; i < ROWS; i++) {
    keyboard.updateRow(i);

    clock4017.write(HIGH);
    clock4017.write(LOW);
  }

  for (int i = 0; i < MUX_CHANNELS; i++) {
    controlPanel.updateRow(i);
  }
}

void updateState() {
  if (controlPanel.buttonStates[7] == PRESSED) oscil1.waveform = (oscil1.waveform + 1) % Oscillator::Waveform::Count;
  if (controlPanel.buttonStates[6] == PRESSED) oscil2.waveform = (oscil2.waveform + 1) % Oscillator::Waveform::Count;
  if (controlPanel.buttonStates[5] == PRESSED) oscil3.waveform = (oscil3.waveform + 1) % Oscillator::Waveform::Count;
  oscil1.enabled = controlPanel.switchStates[6];
  oscil2.enabled = controlPanel.switchStates[5];
  oscil3.enabled = controlPanel.switchStates[4];
  oscil1.gain = controlPanel.potStates[13] >> 3;
  oscil2.gain = controlPanel.potStates[12] >> 3;
  oscil3.gain = controlPanel.potStates[11] >> 3;
}

int updateAudio() {
  int16_t signal = (int16_t)oscil1.next() + (int16_t)oscil2.next() + (int16_t)oscil3.next();
  int oscillatorsEnabled = oscil1.enabled + oscil2.enabled + oscil3.enabled;
  if (oscillatorsEnabled == 2) signal = signal >> 1;
  if (oscillatorsEnabled == 3) signal = signal / 3;

  return signal << 6;

  //   int8_t modulation = ((int16_t)(255 - mix) * aSquare.next() + (int16_t)mix * aSaw.next()) >> 8;
  // return modulation << 6;


  // int8_t asig = lpf.next(modulation >> 1);
  // return asig << 6;
  // return (int8_t)((int16_t)(asig * lfo.next()) >> 8) << 6;
}

void loop() {
  audioHook();
}
