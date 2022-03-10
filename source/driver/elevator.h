/**
 * @file elevator.h
 * @author hermano (hhbale@stud.ntnu.no)
 * @brief Inneholder funksjoner som er direkte fysisk koblet til heisen.
 * @date 2022-03-06
 */
#pragma once
#include "elevio.h"

/**
 * @brief Variabel som forteller om det er foretatt et nødstopp.
 * 
 */
static int g_emergency = 0;
/**
 * @brief Returnerer verdien til emergency-variablen.
 * 
 * @return Verdi 
 */
int getEmergency(void);
/**
 * @brief Setter verdien til emergency-variablen.
 * 
 * @param e Verdi
 */
void setEmergency(int value);

/**
 * @brief Variabel som indikerer hvilken etasje heisen var i sist.
 * 
 */
static int g_lastFloor;
/**
 * @brief Variabel som indikerer hvorvidt døren er åpen.
 * 
 */
static int g_doorOpen;

/**
 * @brief Returnerer verdien til g_lastFloor-variablen.
 * 
 * @return Verdi 
 */
int getLastFloor(void);
/**
 * @brief Setter verdien til g_lastFloor-variablen.
 * 
 */
void setLastFloor(void);

/**
 * @brief Returnerer verdien til g_doorOpen-variablen.
 * 
 * @return Verdi 
 */
int getDoorOpen(void);
/**
 * @brief Returnerer etasjen heisen befinner seg i ved gitt tidspunkt.
 * 
 * @return Etasje
 */
int getCurrentFloor(void);

/**
 * @brief Returnerer verdien til obstruksjonsbryteren.
 * 
 * @return Verdi
 */
int getObstructed(void);
/**
 * @brief Returnerer verdien til stoppknappen.
 * 
 * @return Verdi 
 */
int getStop(void);

/**
 * @brief Får etasjeindikatorerne til å lyse etter kravene.
 * 
 */
void indicateFloor(void);
/**
 * @brief Initialiserer heisen - setter den i en definert etasje.
 * 
 */
void initElevator(void);
/**
 * @brief Simulerer en person som skal av eller på heisen ved en etasje.
 * 
 */
void embark(void);
/**
 * @brief Setter verdien til lyset som inikerer om døren er åpen eller lukket.
 * 
 * @param value Verdi
 */
void setDoor(int value);
/**
 * @brief Definerer hvordan heisen skal respondere ved et nødstopp.
 * 
 */
void stopper(void);
/**
 * @brief Håndterer stopp mellom etasjer.
 * 
 * @param dirn Retning
 */
void emergencyHandler(MotorDirection dirn);