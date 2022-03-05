#include "elevator.h"
#include "elevio.h"
#include <stdlib.h>
#include "timer.h"
#include "FSM.h"


int getCurrentFloor(void){
    return elevio_floorSensor();
}

int getDoorOpen(void){
    return g_doorOpen;
}

int getStop(void){
    return elevio_stopButton();
}

int getObstructed(void){
    return elevio_obstruction();
}

void indicateFloor(void){
    if(getCurrentFloor() != -1){
        elevio_floorIndicator(getCurrentFloor());
    }
}

//testet
void initElevator(void){
    closeDoor();
    elevio_motorDirection(DIRN_DOWN);
    while(getCurrentFloor() == -1){
        continue;
    }
    elevio_motorDirection(DIRN_STOP);
    setState(STAT);
}

//testet
void embark(void){
    elevio_motorDirection(DIRN_STOP);
    setState(STAT);

    g_doorOpen = 1;
    elevio_doorOpenLamp(1);
}


//testet
void closeDoor(void){
    elevio_doorOpenLamp(0);
    g_doorOpen = 0;
}


//testet
void stopper(void){
    elevio_motorDirection(DIRN_STOP);
    flushQueue();
    while(getStop()){
        elevio_stopLamp(1);
    }
    elevio_stopLamp(0);
}

