#include "gpio.h"


void GpioInit()
{
 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
 GPIO_PORTF_AHB_DIR_R   = 0x11111111U;
 GPIO_PORTF_AHB_AFSEL_R = 0x11111111U;
 GPIO_PORTF_AHB_DEN_R		= 0x11111111U;
	
	//GPIO_PORTF_DATA_R |= 0x02;
	
	
}
