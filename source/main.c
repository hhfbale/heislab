#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/timer.h"
#include "driver/elevio.h"
#include "driver/queue.h"
#include "driver/FSM.h"
#include "driver/elevator.h"





int main(){
    elevio_init();

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    //elevio_motorDirection(DIRN_UP);
    initQueue();
    initElevator();

    elevio_motorDirection(DIRN_DOWN);

    while(1){ 
 
        if(getCurrentFloor() == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(getCurrentFloor() == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }

/*
        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
    */      
        if(elevio_stopButton()){
            stopper();
            break;
        }
      
       nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    
    }
    printQueue();
    return 0;
}
