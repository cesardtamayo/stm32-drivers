#include "uart.h"

/*
Registers Leyend:
RCC:					Reset and Clock Control
RCC_APB1ENR: 	RCC APB1 Enable Register
RCC_AHBENR: 	RCC AHB Enable Register
GPIOx_AFRL:		GPIOx Alternate Function Register Low
GPIOx_AFRH:		GPIOx Alternate Function Register High
USARTx_ISR: 	USART interrupt and status register
USARTx_BRR: 	USART Baud Rate Register
USARTx_CRx: 	USART Control Register
USARTx_TDR:		USART Transmit Data Register
USARTx_RDR: 	USART Receive Data Register

*/


void USART2_Init(void){
	RCC->APB1ENR |= (1<<17); 		/* enabling clock access to USART2 (bit 17) */
	RCC->AHBENR |= (1<<17);			/* enabling clock access to Port A (bit 17) */
 		
	GPIOA->MODER |=  0x00A0;		/* Alternate Function Mode(10) for Port 2 and 3 */		
	GPIOA->AFRL |= 0x7700;		
	
	/* Configure UART: */
	USART2->BRR = 0x0341;			/* Baud rate = 9600 @ 8MHz */
	USART2->CR1 = 0x000C;			/* Transmitter and Receiver Enabled, 8 bit data */
	/* USART2->CR2 = 0x000;			 1 Stop bit (default) */ 	
	USART2->CR1 |= 0x0001;			/* USART Enable */
}

int USART2_write(int ch){
	/* checking TXE (Transmit Data Register) empty */
	while(!(USART2->ISR & 0x0080)){} 
			
	USART2->TDR = (ch & 0xFF);
			
	return ch;
}

int USART2_read(void){
	/* Checking RXNE (Read Data Register) empty */
	while(!(USART2->ISR & 0x0020)){} 
		
	return USART2->RDR;
}

int fgetc(FILE *f){
	int c;
	
	c = USART2_read();
	
	if (c == '\r'){
		USART2_write(c);
		c = '\n';		
	}
	
	USART2_write(c);
	
	return c;
}

int fputc(int c, FILE *f){
	return USART2_write(c);
}

int n;
char str[80];

void test_setup(void){
	printf("please enter a number:");
	scanf("%d", &n);
	printf("The number entered is: %d\r\n", n);
	printf("please enter a string:");
	gets(str);
	printf("The string entered is: ");
	puts(str);
	printf("\r\n");
}	
/*
1. Enable clock access to UART2
2. Enable clock access to portA
3. Enable pins for alternate functions pa2, pa3
4. Configure type of alternate function
5. Configure UART
*/

// struct __FILE { int handle; };
FILE __stdin = {0};
FILE __stdout = {1};
FILE __stderr = {2};

	
	
