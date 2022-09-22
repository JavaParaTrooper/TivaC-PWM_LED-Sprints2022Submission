#include "gpio.h"
#include "Timer.h"
#include "IntCtrl.h"
#include "LED.h"

void SysTick_Handler()
{
	LED_Blink();
  SysTickReset();
}


int main()
{
	GpioInit();
	SysTickInit(1000000,10010000);
	IntCtrlInit();
	
}

