#pragma once

typedef enum{
    STAT    = 0,
    OPEN    = 1,
    DOWN    = 2,
    UP      = 3
} STATE;

static STATE g_state = STAT;
STATE getState(void);
void setState(STATE s);


void FiniteStateMachine(void);
