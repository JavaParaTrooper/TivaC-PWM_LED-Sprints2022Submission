#include "Timer.h"
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

void SysTickReset()
{
		if(state==1) 
		{
			STRELOAD=Off;
			state=0;
		}
	else if(state==0) 
	{
		STRELOAD =On;
		state=1;
	}
	
	STCTRL |= 0x3u;
}
