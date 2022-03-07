/**
 * @file tid.h
 * @author herman (hhbale@stud.ntnu.no)
 * @brief Utlevert kode, funksjoner som innhenter og sender informasjon til fysisk heis.
 * @date 2022-03-06
 */
#pragma once
#include <time.h>

/**
 * @brief Nullstiller startverdien som brukes i funksjonen stopCounter() for å telle sekunder.
 * 
 */
void startCounter(void);
/**
 * @brief Returnerer 1 hvis det er gått 3 sekunder siden den ble kalt.
 * 
 * @return Verdi
 */
int stopCounter(void);
/**
 * @brief Funksjonen som teller til tre sekunder. fungerer som en forsinkelse.
 * 
 */
void timer(void);