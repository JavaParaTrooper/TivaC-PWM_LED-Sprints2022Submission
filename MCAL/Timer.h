/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Timer.h>
 *       Module:  -
 *
 *  Description:  <Define SysTick Timer Registers,Declerations of: Initilization function of Timer,SysTick_Handler ISR Function, SysTickReset - Reset the timer and load it with new value>     
 *  
 *********************************************************************************************************************/


#ifndef SysTim
#define SysTim

#include "Libs/TivaRegisters.h"
#include <stdint.h>

#define STRELOAD              (*((volatile uint32_t *)0xE000E014)) /* Value to load into the SysTick Current Value (STCURRENT) register  ---(NVIC_ST_RELOAD_R)
																				when the counter reaches 0 */

#define STCTRL              (*((volatile uint32_t *)0xE000E010))    //NVIC_ST_CTRL_R
extern uint32_t On,Off;

void SysTickInit(uint32_t,uint32_t);
void SysTick_Handler(void);
void SysTickReset(void);


#endif

/**********************************************************************************************************************
 *  END OF FILE: Timer.h
 *********************************************************************************************************************/


