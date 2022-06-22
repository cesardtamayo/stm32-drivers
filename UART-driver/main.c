
#include "uart.h"
#include "stdio.h"
/*
 * 	LED - PB13 - AHB
 *
 *
 * 	Set bit18 in RCC_AHBENR to enable Port B
 *	Set bit26 in GPIOB_MODER to configure output mode on port 13
 *	Set bit13 in GPIOB_ODR for HIGH output on LED
 *
 * */


int main(void){

	USART2_Init();
		
	printf("Hello there from main() :) ");

	while(1){
		test_setup();	
	}
	
	

}
