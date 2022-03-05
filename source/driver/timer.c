#include "timer.h"
#include "queue.h"
#include "elevator.h"
#include <stdio.h>


static int startTime = -1;


void startCounter(void){
    startTime = time(NULL);
}

int stopCounter(void){
    int stopTime = 3;
    int timeFinished = ((time(NULL) - startTime) > stopTime);
    if(startTime == -1){
        return 0;
    }
    else{return timeFinished;}
}

void timer(void){

    startCounter();
    indicateFloor();
    do{
        updateQueue();
        if(getStop()){
            stopper();
        }

    } while(stopCounter() == 0);

}