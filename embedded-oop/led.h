#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"
#include <stm32f3xx.h>

/*
	User LED (Green) is connected to PB13
*/

#define LED_PORT 				GPIOB
#define LED_PORT_CLOCK	(1U<<18) // RCC_AHBENR - IOPB = bit18

#define LED_GREEN_PIN 		(1U<<13)	// User LED = PB13

#define LED_GREEN_MODE_BIT (1U<<26)

typedef enum {
		RED = 0,
		GREEN,
		YELLOW,
		BLUE
} LedColors_Type;

typedef enum {
	OFF = 0,
	ON
} LedState_Type;

typedef struct {
	LedColors_Type color;
	LedState_Type state;
	uint32_t last_update;
}Led_Type;

void Led_ctor(Led_Type* const me, LedColors_Type _color, LedState_Type _state);
void Led_setState(Led_Type* const me, LedState_Type _state);
LedState_Type Led_getState(Led_Type* const me);
void Led_toggle(Led_Type* me);
	


#endif