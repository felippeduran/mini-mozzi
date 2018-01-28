#ifndef Oscillator_h
#define Oscillator_h

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/saw2048_int8.h>
#include <tables/square_no_alias_2048_int8.h>
#include <tables/sin2048_int8.h>
#include <tables/triangle2048_int8.h>

struct Oscillator {
    Oscillator() : waveform(Saw) {};

    typedef enum { Saw, Square, Sine, Triangle, Count } Waveform;
    int8_t waveformMask[Waveform::Count] = { 1, 2, 4, 8 };

    int8_t next();

    Waveform waveform;
    bool enabled;
    int8_t gain;
    Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> aSin = Oscil<SIN2048_NUM_CELLS, AUDIO_RATE>(SIN2048_DATA);
    Oscil<SQUARE_NO_ALIAS_2048_NUM_CELLS, AUDIO_RATE> aSquare = Oscil<SQUARE_NO_ALIAS_2048_NUM_CELLS, AUDIO_RATE>(SQUARE_NO_ALIAS_2048_DATA);
    Oscil<SAW2048_NUM_CELLS, AUDIO_RATE> aSaw = Oscil<SAW2048_NUM_CELLS, AUDIO_RATE>(SAW2048_DATA);
    Oscil<TRIANGLE2048_NUM_CELLS, AUDIO_RATE> aTriangle = Oscil<TRIANGLE2048_NUM_CELLS, AUDIO_RATE>(TRIANGLE2048_DATA);
};

#endif /* Oscillator_h */