/**
 * @file FSM.h
 * @author herman (hhbale@stud.ntnu.no)
 * @brief Utlevert kode, funksjoner som innhenter og sender informasjon til fysisk heis.
 * @date 2022-03-06
 */
#pragma once

typedef enum{
    STAT    = 0,
    OPEN    = 1,
    DOWN    = 2,
    UP      = 3
} STATE;

/**
 * @brief Variabel for bevegelsestilstanden heisen var i sist.
 * 
 */
static STATE lastMovingDir;
/**
 * @brief Returnerer retningen heisen sist kjørte.
 * 
 * @return Retning
 */
STATE getLastMovingDir(void);
/**
 * @brief Setter verdien til variablen lastMovingDir.
 * 
 * @param s Retining
 */
void setLastMovingDir(STATE s);

/**
 * @brief Variabel for tilstanden til heisen.
 * 
 */
static STATE g_state = STAT;
/**
 * @brief Returnerer tilstanden heisen er i.
 * 
 * @return Tilstand 
 */
STATE getState(void);
/**
 * @brief Setter verdien til tilstanden.
 * 
 * @param s Tilstand
 */
void setState(STATE s);

/**
 * @brief Selve tilstandmaskinen. Switch-case som stadig kjører i en whileløkke, hvor casene er tilstandene til heisen.
 * 
 */
void FiniteStateMachine(void);
