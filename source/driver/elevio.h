/**
 * @file elevio.h
 * @author herman (hhbale@stud.ntnu.no)
 * @brief Utlevert kode, funksjoner som innhenter og sender informasjon til fysisk heis.
 * @date 2022-03-06
 * 
 */
#pragma once

#define N_FLOORS 4

typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;


#define N_BUTTONS 3

typedef enum { 
    BUTTON_HALL_UP      = 0,
    BUTTON_HALL_DOWN    = 1,
    BUTTON_CAB          = 2
} ButtonType;

/**
 * @brief Initialiseringsfunksjo, kobler til serveren.
 * 
 */
void elevio_init(void);

/**
 * @brief Setter motorpådraget til heisen.
 * 
 * @param dirn Retning
 */
void elevio_motorDirection(MotorDirection dirn);
/**
 * @brief Setter lyset på knappene gitt etasje, knappetype og verdi (0/1).
 * 
 * @param floor Etajse
 * @param button Knappetype
 * @param value Verdi
 */
void elevio_buttonLamp(int floor, ButtonType button, int value);
/**
 * @brief Setter lyset på etasjeindikatoren gitt etasje.
 * 
 * @param floor Etasje
 */
void elevio_floorIndicator(int floor);
/**
 * @brief Setter lyset som indikerer om døren er åpen eller ikke, gitt verdi (0/1).
 * 
 * @param value Verdi
 */
void elevio_doorOpenLamp(int value);
/**
 * @brief Setter lyset på stoppknappen gitt verdi (0/1).
 * 
 * @param value Verdi
 */
void elevio_stopLamp(int value);

/**
 * @brief Returnerer høy/lav til en knapp, gitt knappetype og etasje.
 * 
 * @param floor Etasje
 * @param button Knappetype
 * @return Verdi
 */
int elevio_callButton(int floor, ButtonType button);
/**
 * @brief Returnerer etasjen heisen befinner seg i ved gitt tidspunkt, gir -1 hvis mellom etasjer.
 * 
 * @return Etasje
 */
int elevio_floorSensor(void);
/**
 * @brief Returnerer verdien til stoppknappen, 1 hvis den er trykket inn, 0 ellers.
 * 
 * @return Verdi
 */
int elevio_stopButton(void);
/**
 * @brief Returnerer verdien som indikerer obstruksjon.
 * 
 * @return Verdi
 */
int elevio_obstruction(void);

