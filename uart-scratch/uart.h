#ifndef __UART_H
#define __UART_H

// #include <stdint.h>
#include "gpio.h"	
#include "stdio.h"

// Addresses
#define USART1_BASE		(PERIPH_BASE + 0x00013800U)
#define USART2_BASE		(PERIPH_BASE + 0x00004400U)
#define USART3_BASE		(PERIPH_BASE + 0x00004800U)

// Configuration definitions
#define UART_TX_EN	(1<<3)
#define UART_RX_EN	(1<<3)
#define UART_EN			(1<<0)
#define UART_TXE		(1<<7)	// Transmit data register empty	
#define UART_TC			(1<<6)	// Transmission complete
#define UART_RXNE		(1<<5)	// Read data register not empty

#define __IO volatile


typedef struct {
	__IO uint32_t CR1;
	__IO uint32_t CR2;
	__IO uint32_t CR3;
	__IO uint32_t BRR;
	__IO uint32_t GTPR;
	__IO uint32_t RTOR;
	__IO uint32_t RQR;
	__IO uint32_t ISR;
	__IO uint32_t ICR;
	__IO uint32_t RDR;
	__IO uint32_t TDR;
}USART_TypeDef;


#define USART1 	((USART_TypeDef*)USART1_BASE)
#define USART2 	((USART_TypeDef*)USART2_BASE)
#define USART3 	((USART_TypeDef*)USART3_BASE)

void USART2_Init(void);
void test_setup(void);

#endif