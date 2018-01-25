#ifndef KeyState_h
#define KeyState_h

typedef enum { IDLE, PRESSED, HOLD, RELEASED } KeyState;

KeyState getNextState(bool pressed, KeyState key);

#endif /* KeyState_h */