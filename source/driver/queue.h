/**
 * @file queue.h
 * @author herman (hhbale@stud.ntnu.no)
 * @brief Inneholder funksjoner og variabler knyttet til køsystemet og prioriteringer.
 * @date 2022-03-06
 */
#pragma once

#include "elevator.h"
#include "elevio.h"

/**
 * @brief Køsystemet er en 3x4 matrise.
 * 
 */
static int g_queue[N_BUTTONS][N_FLOORS];

/**
 * @brief Endedestinasjonen til heisen.
 * 
 */
static int g_endDest;
/**
 * @brief Returnerer endedestinasjonen som er satt.
 * 
 * @return Endedestinasjonen 
 */
int getEndDest(void);

/**
 * @brief Initialiserer køen - setter alle elementetne til 0.
 * 
 */
void initQueue(void);
/**
 * @brief Printer køen.
 * 
 */
void printQueue(void);


/**
 * @brief Legger etasjer til køen gitt knappetype og etasje.
 * 
 * @param b Knappetype
 * @param f Etasje
 */
void addToQueue(int b, int f);
/**
 * @brief Fjerner etasjer fra køen gitt knappetyppe.
 * 
 * @param b Knappetype
 */
void removeFromQueue(int b);
/**
 * @brief Nullstiller køen.
 * 
 */
void flushQueue(void);
/**
 * @brief Sjekker om køen er nullstilt.
 * 
 * @return Verdi
 */
int checkFlush(void);
/**
 * @brief Oppdaterer køen - legger til og fjerner etasjer.
 * 
 */
void updateQueue(void);
/**
 * @brief Sjekker etasjer som eventuelt skal stoppes i når man kjører opp.
 * 
 */
void checkFloorUP(void);
/**
 * @brief Sjekker etasjer som eventuelt skal stoppes i når man kjører ned.
 * 
 */
void checkFloorDOWN(void);
/**
 * @brief Oppdaterer endedestinasjonen - tar hensyn til knappeprioritet.
 * 
 */
void updateEndDest(void);
/**
 * @brief Setter endedestinasjonen gitt etasje.
 * 
 * @param f Etasje
 */
void setEndDest(int f);
