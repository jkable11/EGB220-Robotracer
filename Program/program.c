#include "program.h"

int main(){
	DDRE |= (1<<6);
	DDRC &=0;

	PORTC |= (1<<7);
	//PORTE |=(1<<6);

	while(1){
		if(!((~PINC)&(1<<7))){
			PORTE ^= (1<<6);
		}
		_delay_ms(500);
	}

	return 0;
}
