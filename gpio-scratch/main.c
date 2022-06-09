
#include <stdint.h>
#include "gpio_lib.h"
// #include "stm32f3xx.h"

int main(void){
	
	GPIO_InitTypeDef myGpioInit;
		
	myGpioInit.Mode = GPIO_MODE_OUTPUT;
	myGpioInit.Pin = GPIO_PIN_13;
	myGpioInit.Pull = GPIO_NO_PULL;
	
	__LIB_RCC_GPIOB_CLK_ENABLE();
	
	LIB_GPIO_Init(GPIOB, &myGpioInit);
	while(1){
		for (int i=0; i<900000; i++){}
			LIB_GPIO_TogglePin(GPIOB, myGpioInit.Pin);
	}
	
	
	/* ORIGINAL LOGIC: 
	
		RCC->AHBENR |= GPIOB_EN | GPIOA_EN ; 	
		GPIOB->MODER |= (1<<26); // pin13 output
		GPIOA->MODER |= (1<<10); // pin5 output
		
		while(1){
			for (int i=0; i<90000; i++){}
			GPIOB->ODR ^= (1<<13);
			GPIOA->ODR ^= (1<<5);
		}		
	*/
		
}




