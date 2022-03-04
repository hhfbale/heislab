#include "timer.h"



void timer(void){

    time_t start, end;
    double elapsed;

    time(&start);
    do{
        time(&end);
        elapsed = difftime(end, start);

    } while(elapsed < 3.5);
    g_timerFinished = 1;
    //printf("%f", elapsed);

}


int getTimerFinished(void){
    return g_timerFinished;
}