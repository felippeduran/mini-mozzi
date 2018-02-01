#include <MozziGuts.h>
#include <Oscil.h>
#include <LowPassFilter.h>
#include <ADSR.h>

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

ADSR<CONTROL_RATE, AUDIO_RATE> envelope;

int8_t currentNote = 99;

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

  // envelope.setADLevels(255, 255);
  envelope.setLevels(255, 255, 255, 255);
  envelope.setTimes(2000, 2000, 32768, 0);

  Serial.begin(9600);
}

void updateControl() {
  keyboard.resetStateChanges();
  updateParameters();
  updateState();

  for (int i = 0; i < keyboard.stateChangesSize; i++) {
    int8_t noteIndex = keyboard.stateChanges[i];
    KeyState state = keyboard.keyboardState[noteIndex];
    int8_t note = keyboard.getSequentialKeyNumber(noteIndex);

    if (state == PRESSED && note < currentNote) {
      currentNote = note;
      oscil1.setNote(currentNote);
      oscil2.setNote(currentNote);
      oscil3.setNote(currentNote);

      oscil1.updateFrequency();
      envelope.noteOn();
    }

    if (state == RELEASED && note == currentNote) {
      currentNote = 50;
      envelope.noteOff();
    }
  }

  envelope.update();
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
  if (controlPanel.buttonStates[7] == PRESSED) oscil1.waveform = (oscil1.waveform + 1) % Oscillator::Waveform::WaveCount;
  if (controlPanel.buttonStates[6] == PRESSED) oscil2.waveform = (oscil2.waveform + 1) % Oscillator::Waveform::WaveCount;
  if (controlPanel.buttonStates[5] == PRESSED) oscil3.waveform = (oscil3.waveform + 1) % Oscillator::Waveform::WaveCount;
  if (controlPanel.buttonStates[4] == PRESSED) oscil1.range = (oscil1.range + 1) % Oscillator::Range::RangeCount;
  if (controlPanel.buttonStates[3] == PRESSED) oscil2.range = (oscil2.range + 1) % Oscillator::Range::RangeCount;
  if (controlPanel.buttonStates[2] == PRESSED) oscil3.range = (oscil3.range + 1) % Oscillator::Range::RangeCount;
  oscil1.enabled = controlPanel.switchStates[6];
  oscil2.enabled = controlPanel.switchStates[5];
  oscil3.enabled = controlPanel.switchStates[4];
  oscil1.gain = controlPanel.potStates[13] >> 3;
  oscil2.gain = controlPanel.potStates[12] >> 3;
  oscil3.gain = controlPanel.potStates[11] >> 3;
  // oscil1.detune = controlPanel.potStates[13] >> 3;
  oscil2.detune = controlPanel.potStates[15];
  oscil3.detune = controlPanel.potStates[14];
  oscil2.updateFrequency();
  oscil3.updateFrequency();

  envelope.setSustainLevel(controlPanel.potStates[3] >> 3);
  envelope.setReleaseLevel(controlPanel.potStates[3] >> 3);
  // envelope.setDecayLevel(controlPanel.potStates[3] >> 3);
  envelope.setAttackTime(controlPanel.potStates[8]);
  envelope.setDecayTime(controlPanel.potStates[5]);
}

int updateAudio() {
  int16_t signal = (int16_t)oscil1.next() + (int16_t)oscil2.next() + (int16_t)oscil3.next();
  int oscillatorsEnabled = oscil1.enabled + oscil2.enabled + oscil3.enabled;
  if (oscillatorsEnabled == 2) signal = signal >> 1;
  if (oscillatorsEnabled == 3) signal = signal / 3;

  signal = (signal * envelope.next()) >> 8;

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
