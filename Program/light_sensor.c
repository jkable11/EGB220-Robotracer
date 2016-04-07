#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#define F_CPU 16000000
#define H_THRESH 30
#define L_THRESH 40

volatile signed char sensor_out = 0;
volatile signed char baseline = 0;
volatile int active = 0;

ISR (TIMER0_OVF_vect){
	
}

ISR(ADC_vect){
	if (!active) { //assign baseline upon first ADC entry
		baseline = ADCH;
		active = 1;
	}
	sensor_out = ADCH; //probably will be between 0 and 255
	if (sensor_out >= baseline + H_THRESH){
		OCR0A = 0;
	}
	else if (sensor_out <= baseline - L_THRESH) {
		OCR0A = 255;
	}
}

void init(){
	DDRB |=(1<<7);
	DDRD |=(1<<7);
	TCCR0A |= (1<<7)|(1<<6)|(1<<5)|(1<<5)|1;
	OCR0A = 255;
	OCR0B = 255;
	TCCR0B |= (1<<2);
	TIMSK0 |=1;

	ADMUX |=(1<<6)|(1<<7)|(1<<5);
	ADCSRA |=(1<<7)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|1;
	ADCSRA|=(1<<6);
	ADCSRB=0;
}

int main(){
	sei();
	init();
	while(1){
		
	}
	return 1;
}



