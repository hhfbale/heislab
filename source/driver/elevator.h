#pragma once
#include "elevio.h"

static int emergency = 0;
int getEmergency(void);
void setEmergency(int e);

static int g_lastFloor;
static int g_doorOpen;
int getLastFloor(void);
void setLastFloor(void);
int getDoorOpen(void);
int getCurrentFloor(void);
int getObstructed(void);
int getStop(void);

void indicateFloor(void);
void initElevator(void);
void embark(void);
void setDoor(int value);
void stopper(void);
