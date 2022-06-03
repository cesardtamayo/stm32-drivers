#include "led.h"


void Led_ctor(Led_Type* const me, LedColors_Type _color, LedState_Type _state){
	me->color = _color;
	me->state = _state;
	printf("Led initialized with color %d and state %d\r\n", _color, _state);
	
	// Hardware Init:
	RCC->AHBENR |= LED_PORT_CLOCK;
	
	switch(_color){
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;			
			break;
		default:
			printf("Color %d not handled in Led_ctor(). Check code and try again.", _color);
	}
	
	Led_setState(me, _state);
	
}

void Led_setState(Led_Type* const me, LedState_Type _state){
	me->state = _state;
	printf("The %d led is set to %d\n\r", me->color, me->state);
	
	switch(me->color){
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
			if (me->state == ON){
					LED_PORT->ODR |= LED_GREEN_PIN;
			}else{
				LED_PORT->ODR &= ~LED_GREEN_PIN;
			}
			break;
		default:
			printf("Color %d not handled in Led_ctor(). Check code and try again.", me->color);
	}
	
}

LedState_Type Led_getState(Led_Type* const me){
	return me->state;
}
	
void Led_toggle(Led_Type* me){
	if (me->state == ON){		
		Led_setState(me, OFF);
	}else{
		Led_setState(me, ON);
	}
}