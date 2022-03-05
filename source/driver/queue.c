#include "queue.h"
#include "FSM.h"
#include "elevator.h"
#include "tid.h"


//testet
void initQueue(void){
    for(int b=0;b<N_BUTTONS;b++){
        for(int f=0;f<N_FLOORS;f++){
            *(*(g_queue+b)+f)=0;
            elevio_buttonLamp(f,b,0);
        }
    }
    setEndDest(4);
}

//testet
void printQueue(void){
    for(int b=0;b<N_BUTTONS;b++){
        for(int f=0;f<N_FLOORS;f++){
            printf("%i  ",*(*(g_queue+b)+f));
        }
        printf("\n");
    }
}

//testet
void flushQueue(void){
    initQueue();
}

//testet
int checkFlush(void){
    for(int b=0;b<N_BUTTONS;b++){
        for(int f=0;f<N_FLOORS;f++){
            if(*(*(g_queue+b)+f) == 1){
                return 0;
            }
        }
    }
    return 1;
}

//testet
void addToQueue(int b, int f){
    int addFloor=-1;
    int *p_addFloor=&addFloor;

    *p_addFloor = elevio_callButton(f,b);
    if(*p_addFloor== 1){
        *(*(g_queue+b)+f)=1;
        elevio_buttonLamp(f,b,*p_addFloor);     
    }
                       
}

//testet, mangler å teste med input bra current floor, og state, og sette på lys
void removeFromQueue(int b){
  
    if(getState() == OPEN){
        *(*(g_queue+b)+getCurrentFloor()) = 0;
        elevio_buttonLamp(getCurrentFloor(),b,0);               
    }
}


//testet
void updateQueue(void){
    for(int b=0;b<N_BUTTONS;b++){
        for(int f=0;f<N_FLOORS;f++){
            addToQueue(b,f);                     
        }
        removeFromQueue(b); 
    }                 
}


void checkFloorUP(void){          
    if(*(*(g_queue+BUTTON_HALL_UP)+getCurrentFloor())==1){
        embark();
    }
    
    if(getEndDest() == getCurrentFloor()){
        setState(STAT);
        //updateEndDest();
    }
    
      
    if(*(*(g_queue+BUTTON_CAB)+getCurrentFloor())==1){
        embark();
    }  
}

void checkFloorDOWN(void){
    if(*(*(g_queue+BUTTON_HALL_DOWN)+getCurrentFloor())==1){
        embark();
    }
    
    if(getEndDest() == getCurrentFloor()){
        setState(STAT);
    }
    
    if(*(*(g_queue+BUTTON_CAB)+getCurrentFloor())==1){
        embark();
    }
    
}

int getEndDest(void){
    return g_endDest;
}

//testet
void updateEndDest(void){
    const int prioOne = 2;
    const int prioTwo = 1;
    const int prioThree = 0;
    
    int flushed = checkFlush();
    if(flushed == 1){
        setEndDest(4);
    }
    else{
        for(int f=0;f<N_FLOORS;f++){
            if(*(*(g_queue+prioThree)+f)== 1){
                g_endDest = f;
            }
            if(*(*(g_queue+prioTwo)+f)== 1){
                g_endDest = f;
            }
            if(*(*(g_queue+prioOne)+f) == 1){
                g_endDest = f;
                break;
            }
        }
    }
}

void setEndDest(int f){
    g_endDest = f;
}
