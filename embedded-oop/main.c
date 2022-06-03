#include "led.h"

int main(void){
	
	USART2_Init();
	printf("Hello there from main :) \n\r");
	Led_Type led1;	
	Led_ctor(&led1, GREEN, ON);		
		
	while(1){
		for (int i=0; i<900000; i++){}
		Led_toggle(&led1);
	}
}