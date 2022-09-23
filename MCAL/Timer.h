
#ifndef SysTim
#define SysTim

#include "Libs/TivaRegisters.h"
#include <stdint.h>

#define STRELOAD              (*((volatile uint32_t *)0xE000E014)) /* Value to load into the SysTick Current Value (STCURRENT) register 
																																			when the counter reaches 0 */

#define STCTRL              (*((volatile uint32_t *)0xE000E010))
extern uint32_t On,Off;

void SysTickInit(uint32_t,uint32_t);
void SysTick_Handler(void);
void SysTickReset(void);


#endif
