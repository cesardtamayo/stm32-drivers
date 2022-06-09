#include "gpio_lib.h"

#define GPIO_NUM 					16U
#define GPIO_MODER_MODE0	0x3U<<0
#define GPIO_MODE					0x03U
#define GPIO_PUPDR_PUPDR0 0x3U<<0

void LIB_GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitTypeDef * GPIO_Init){

		uint32_t position;
		uint32_t temp = 0x0U;
		uint32_t ioposition = 0x00U;
		uint32_t iocurrent = 0x00U;
	
		for (position = 0; position < GPIO_NUM; position++){
			ioposition = 0x01U << position;			// 0x000001000 where 1 is on the Pin value
			iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;
			
			if (iocurrent == ioposition){
				// Setting mode:
				temp = GPIOx->MODER;
				temp &= ~(GPIO_MODER_MODE0 << (position * 2U)); // disabling frist ...?
				temp |= (GPIO_Init->Mode & GPIO_MODE) << (position * 2U);
				GPIOx->MODER = temp;
				
				// Setting PullUp/PullDown register value:			
				temp = GPIOx->PUPDR;
				temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
				temp |= (GPIO_Init->Pull & GPIO_MODE) << (position * 2U);
				GPIOx->PUPDR = temp;
			}
		}
	
}

GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIO_PinState state = GPIO_PIN_RESET;
	
	if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET ){
		state = GPIO_PIN_SET;
	}else{
		state = GPIO_PIN_RESET;
	}
	return state;
}

void LIB_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
		if (PinState == GPIO_PIN_SET){
			GPIOx->BSRR |= GPIO_Pin;
		}else{
			GPIOx->BSRR &= ~(uint32_t)GPIO_Pin << 16;
		}
}

void LIB_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIOx->ODR ^= GPIO_Pin;		
}

void __LIB_RCC_GPIOA_CLK_ENABLE(void){
	RCC->AHBENR |= GPIOA_EN;
}

void __LIB_RCC_GPIOB_CLK_ENABLE(void){
	RCC->AHBENR |= GPIOB_EN;
}

void __LIB_RCC_GPIOC_CLK_ENABLE(void){
	RCC->AHBENR |= GPIOC_EN;
}

void __LIB_RCC_GPIOD_CLK_ENABLE(void){
	RCC->AHBENR |= GPIOD_EN;
}

void __LIB_RCC_GPIOF_CLK_ENABLE(void){
	RCC->AHBENR |= GPIOF_EN;
}