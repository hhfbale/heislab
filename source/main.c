#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/tid.h"
#include "driver/elevio.h"
#include "driver/queue.h"
#include "driver/FSM.h"
#include "driver/elevator.h"





int main(){
    elevio_init();
    initQueue();
    initElevator();

    
    FiniteStateMachine();

    return 0;
}
