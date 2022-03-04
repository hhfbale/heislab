#include "FSM.h"
#include "elevator.h"
#include "elevio.h"
#include "timer.h"
#include "queue.h"

STATE getState(void){
    return g_state;
}

void setState(STATE s){
    g_state = s;
}


void FiniteStateMachine(void){

    setEndDest();

    while(1){
        updateQueue();

        if(getCurrentFloor() != -1){
            elevio_floorIndicator(getCurrentFloor());
        }

        switch (getState()){
            case STAT:
                if(getStop()){
                    stopper();
                    break;
                }
                if(getDoorOpen()){
                    setState(OPEN);
                    break;
                }
                if(getEndDest() == 4){
                    break;
                }
                if(getEndDest() < getCurrentFloor()){
                    elevio_motorDirection(DIRN_DOWN);
                    setState(DOWN);
                    break;
                }
                if(getEndDest() > getCurrentFloor()){
                    elevio_motorDirection(DIRN_UP);
                    setState(UP);
                    break;
                }
                break;

            case OPEN:
                if(getTimerFinished()){
                    closeDoor();
                    setState(STAT);
                    break;
                }
                if(getObstructed() || getStop()){
                    timer();
                    setState(OPEN);
                    break;
                }
                break;

            case DOWN:
                if(getStop()){
                    setState(STAT);
                    stopper();
                    break;
                }
                if(getCurrentFloor() != -1){
                    checkFloorDOWN();
                    break;
                }
                break;

            case UP:
                if(getStop()){
                    setState(STAT);
                    stopper();
                    break;
                }
                if(getCurrentFloor() != -1){
                    checkFloorUP();
                    break;
                }
                break;

            default:
                setState(STAT);
                break;
        }
    }
}
