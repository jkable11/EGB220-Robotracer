#include "program.h"

int main(){

	while(1){
		motor(90);
		_delay_ms(500);
	}

	return 0;
}

void motor(int cycle){
	DDRB |=(1<<7);
	DDRD |=(1<<7);
	TCCR0A |= (1<<7)|(1<<6)|(1<<5)|(1<<5)|1;
	OCR0A = 255*(100-cycle)/100;
	OCR0B = 255*(100-cycle)/100;
	TCCR0B |= (1<<2);
	TIMSK0 |=1;
}
