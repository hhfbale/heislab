#include "FSM.h"
#include "elevator.h"
#include "elevio.h"
#include "tid.h"
#include "queue.h"

STATE getState(void){
    return g_state;
}

void setState(STATE s){
    g_state = s;
}

STATE getLastMovingDir(void){
    return lastMovingDir;
}
void setLastMovingDir(STATE s){
    lastMovingDir = s;
}


void FiniteStateMachine(void){

    updateEndDest(); 
    
   
    while(1){
        updateQueue();
        indicateFloor();
        setLastFloor();


        if(getStop() && getObstructed()){
            flushQueue();
            break;
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

                if(getEndDest() != 4 && getEmergency()){
                    initElevator();
                    setEmergency(0);
                    break;
                }

                if(getEndDest() == getCurrentFloor()){
                    updateEndDest();
                    embark();
                    break;
                }

                if(getEndDest() == 4){
                    updateEndDest();
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
                timer();
                if(getObstructed() || getStop()){
                    break;
                }
                if(getEndDest() == getCurrentFloor()){
                    updateEndDest();
                }
                setDoor(0);
                setState(STAT);
                break;

            case DOWN:
                setLastMovingDir(DOWN);
                if(getStop()){
                    setState(STAT);
                    stopper();
                    setEmergency(1);
                    break;
                }
                if(getCurrentFloor() != -1){
                    checkFloorDOWN();
                    break;
                }
                break;

            case UP:
                setLastMovingDir(UP);
                if(getStop()){
                    setState(STAT);
                    stopper();
                    setEmergency(1);
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
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }
}
