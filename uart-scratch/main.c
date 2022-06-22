
#include "uart.h"
#include "stdio.h"

int main(void){
	
	USART2_Init();
		
	printf("Hello there from main() :) ");
	
	int n;
	char str[80];
	while(1){
		printf("please enter a number:");
		scanf("%d", &n);
		printf("The number entered is: %d\r\n", n);
		printf("please enter a string:");
		gets(str);
		printf("The string entered is: ");
		puts(str);
		printf("\r\n");
	}

}
