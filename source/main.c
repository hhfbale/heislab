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
    initQueue();
    initElevator();
    printf("hh");
    
    FiniteStateMachine();

    return 0;
}
