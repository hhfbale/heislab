#include "elevator.h"
#include "elevio.h"
#include <stdlib.h>
#include "tid.h"
#include "FSM.h"

int getEmergency(void){
    return emergency;
}
void setEmergency(int value){
    emergency = value;
}


int getLastFloor(void){
    return g_lastFloor;
}

void setLastFloor(void){
    if(getCurrentFloor()!= -1){
        g_lastFloor = getCurrentFloor();
    } 
}

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
void setDoor(int value){
    elevio_doorOpenLamp(value);
    g_doorOpen = value;
}

//testet
void initElevator(void){
    setDoor(0);
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
    setDoor(1);
}





//testet
void stopper(void){
    elevio_motorDirection(DIRN_STOP);
    flushQueue();
    while(getStop()){
        elevio_stopLamp(1);
        if(getCurrentFloor()!=-1){
            setDoor(1);
        }
    }
    elevio_stopLamp(0);

}

