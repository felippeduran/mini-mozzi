#include "KeyState.h"

KeyState getNextState(bool pressed, KeyState currentState)
{
    KeyState nextState = currentState;
    switch (currentState)
    {
    case IDLE:
        if (pressed)
            nextState = PRESSED;
        break;

    case PRESSED:
        if (pressed)
            nextState = HOLD;
        else
            nextState = RELEASED;
        break;

    case HOLD:
        if (!pressed)
            nextState = RELEASED;
        break;

    case RELEASED:
        if (pressed)
            nextState = PRESSED;
        else
            nextState = IDLE;
        break;
    }
    return nextState;
}