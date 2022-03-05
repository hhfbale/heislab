#pragma once
#include "elevio.h"



static int g_doorOpen;
int getDoorOpen(void);
int getCurrentFloor(void);
int getObstructed(void);
int getStop(void);

void indicateFloor(void);
void initElevator(void);
void embark(void);
void closeDoor(void);
void stopper(void);
