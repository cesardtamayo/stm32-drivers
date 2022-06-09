
#include <stdint.h>

#define PERIPH_BASE 		0x40000000U
#define AHB1_BASE 			PERIPH_BASE + 0x20000U
#define RCC_BASE 				AHB1_BASE + 0x3800U
#define GPIOA_BASE 			AHB1_BASE + 0x00U

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

#define RCC 	(RCC_TypeDef *)RCC_BASE
#define GPIOA (GPIO_TypeDef *)GPIOA_BASE
#define GPIOB (GPIO_TypeDef *)GPIOB_BASE


