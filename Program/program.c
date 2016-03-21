#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC |= (1<<7)|(1<<6);

	while(1){
		PORTC ^= (1<<7)|(1<<6);
		_delay_ms(1000);
	}

	return 0;
}
