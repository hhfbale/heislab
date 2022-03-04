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

//testet
void initElevator(void){

    for(int b=0;b<N_BUTTONS;b++){
        for(int f=0;f<N_FLOORS;f++){
            elevio_buttonLamp(f,b,0);
        }
    }
    g_doorOpen = 0;
    elevio_motorDirection(DIRN_DOWN);
    while(getCurrentFloor() == -1){
        continue;
    }
    elevio_motorDirection(DIRN_STOP);
}

//testet
void embark(void){
    elevio_motorDirection(DIRN_STOP);
    setState(STAT);
    elevio_doorOpenLamp(1);
    g_doorOpen = 1;
    timer();
    closeDoor();
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

