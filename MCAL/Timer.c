/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Timer.c>
 *       Module:  -
 *
 *  Description:  <Timer conversion from ticks to mS, load init Timer Register with main value to start from, initialize Timer Control Registers / Flip State Function between on period and off period >     
 *  
 *********************************************************************************************************************/

#include "Timer.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


uint32_t On,Off;
static uint16_t state;

void SysTickInit(uint32_t OnPeriod , uint32_t OffPeriod)
{
	
	/* 160,000 tick = 1 miliSec ----0.0000625 ms = tick  */
		On=OnPeriod *160000 ;
	Off=OffPeriod *160000  ;
	STRELOAD = On; //Load Timer with init value to count from
  
	STCTRL |= 0x3u; /* Turn On Systick on System Clock, Turn on Interrupt,   */
	STRELOAD = Off;
	state=1;
}  


/**********************************************************************************************************************
 *  Flip State variable to indicate if On Period will be used or Off Period
 *********************************************************************************************************************/
void SysTickReset()
{
		if(state==1)  //If it was ON Period, Do Off Period
		{
			STRELOAD=Off;
			state=0;
		}
	else if(state==0)  // If it was Off Period Do On Period
	{
		STRELOAD =On;
		state=1;
	}
	
	STCTRL |= 0x3u; //Reset Control Register
}

/**********************************************************************************************************************
 *  END OF FILE: Timer.h
 *********************************************************************************************************************/

