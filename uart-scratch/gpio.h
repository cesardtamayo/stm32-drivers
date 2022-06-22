#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>

#define PERIPH_BASE 									 0x40000000U
#define AHB1_BASE 			(PERIPH_BASE + 0x00020000U)
#define RCC_BASE 				(AHB1_BASE + 	 0x00001000U)
#define AHB2_BASE 			(PERIPH_BASE + 0x08000000U)
#define GPIOA_BASE 			(AHB2_BASE + 	 0x00000000U)
#define GPIOB_BASE 			(AHB2_BASE + 	 0x00000400U)
#define GPIOC_BASE 			(AHB2_BASE + 	 0x00000800U)
#define GPIOD_BASE 			(AHB2_BASE + 	 0x00000C00U)
#define GPIOF_BASE 			(AHB2_BASE + 	 0x00001400U)

#define __IO 						volatile 	
	
typedef struct{
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFRL;
	__IO uint32_t AFRH;
	__IO uint32_t BRR;
}GPIO_TypeDef;

typedef struct{
	__IO uint32_t CR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t APB1RSTR;
	__IO uint32_t AHBENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t APB1ENR;
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t AHBRSTR;
	__IO uint32_t CFGR2;
	__IO uint32_t CFGR3;
}RCC_TypeDef;

#define RCC 	((RCC_TypeDef *)RCC_BASE)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)

/* RCC_AHBENR gpio pins */
#define GPIOA_EN 1<<17
#define GPIOB_EN 1<<18
#define GPIOC_EN 1<<19
#define GPIOD_EN 1<<20
#define GPIOF_EN 1<<22

#endif
