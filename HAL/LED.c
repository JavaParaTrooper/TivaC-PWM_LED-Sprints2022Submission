#include "LED.h"
#include "gpio.h"
void LED_Blink(){
		GPIO_PORTF_DATA_R ^= 0x2U;
}

