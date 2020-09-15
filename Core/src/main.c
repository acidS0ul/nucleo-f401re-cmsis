#include "main.h"

#define LED2_ON		GPIOA->ODR = 0x20
#define LED2_OFF	GPIOA->ODR = 0

void InitGPIO(void)
{
	// LED2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	GPIOA->OTYPER  = 0;
	GPIOA->OSPEEDR = 0;
	// BUTTON1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

int main(void)
{
	SystemInit();
	InitGPIO();

	while(1)
	{
		if(!READ_BIT(GPIOC->IDR,GPIO_IDR_ID13))
		{
			LED2_ON;
		}
		LED2_OFF;
	}
}
