#include "tid.h"
#include "queue.h"
#include "elevator.h"
#include <stdio.h>


static int m_startTime = -1;


void startCounter(void){
    m_startTime = time(NULL);
}

int stopCounter(void){
    const int stopTime = 3;
    int timeFinished = ((time(NULL) - m_startTime) > stopTime);
    if(m_startTime == -1){
        return 0;
    }
    else{return timeFinished;}
}

void timer(void){
    indicateFloor();
    startCounter();
    do{
        updateQueue();
        if(getStop()){
            stopper();
        }

    } while(stopCounter() == 0);
}