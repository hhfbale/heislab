#pragma once

//#include "elevator.h"
#include "elevio.h"

static int g_queue[N_BUTTONS][N_FLOORS];

static int g_endDest = 5;
int getEndDest(void);

void initQueue(void);
void printQueue(void);


void addToQueue(int b, int f);
void removeFromQueue(int b);
void flushQueue(void);
int checkFlush(void);
void updateQueue(void);
void checkFloorUP(void);
void checkFloorDOWN(void);
void setEndDest(void);
