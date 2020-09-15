#include "stm32f4xx.h"

//#define DEBUG_ENABLE

void delay_s(uint32_t i)
{
	i *= 1000000;
	for(uint32_t j = 0; j <= i; j++);
}
void init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER = 0x400;
	GPIOA->OTYPER = 0;
	GPIOA->OSPEEDR = 0;
}
int main(void)
{
	init();
	while(1)
	{
		GPIOA->ODR = 0x20;
#ifndef DEBUG_ENABLE
		delay_s(5);
#endif		
		GPIOA->ODR = 0;
#ifndef DEBUG_ENABLE
		delay_s(5);
#endif	
	}
}	