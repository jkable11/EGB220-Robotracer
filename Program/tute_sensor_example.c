#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

volatile float MS_L = 1;
volatile signed char sensor_out = 0;

ISR(TIMER0_OVF_vect){
	if(MS_L > 0){
		OCR0A = (unsigned char)((1-MS_L)*255);
		OCR0B = 255;
	}
	else if(MS_L < 0){
		OCR0B = (unsigned char)((1+MS_L)*255);
		ORC0A = 255;
	}
	else{
		OCR0A = 255;
		OCR0B = 255;
	}
}

ISR(ADC_vect){
	sensor_out = ADCH-128;
	//OCR0A = ADCH;
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
	float inc = 0.01;
	while(1){
		MS_L = (float)sensor_out/128;
	}
	return 0;
}



