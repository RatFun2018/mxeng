#include "ATMEGA2560.h"
#include "Interrupt.h"

void (*int0Fun)();
void (*int1Fun)();
void (*int2Fun)();
void (*int3Fun)();

void AttachInterrupt(int interruptPin, int triggerMode, void (*funPtr)()) {
	
	
	cli();
	DDRD &= ~(1<<interruptPin); //INT0 input mode
	DDRD = 0;
	PORTD |= (1<<interruptPin); // enable internal pullup resistor
	
	switch (triggerMode) {
		
		case LOW:
		
		EICRA &= ~(1<<(0<<(2 * interruptPin)));
		EICRA &= ~(1<<(1<<(2 * interruptPin)));
		
		break;
		
		case FALLING:
		
		EICRA &= ~(1<<(0<<(2 * interruptPin)));
		EICRA |= (1<<(1<<(2 * interruptPin)));
		
		break;
		
		case RISING:
		
		EICRA |= (1<<(0<<(2 * interruptPin)));
		EICRA |= (1<<(1<<(2 * interruptPin)));
		
		break;
		
		case CHANGE:
		
		EICRA |= (1<<(0<<(2 * interruptPin)));
		EICRA &= ~(1<<(1<<(2 * interruptPin)));
		
		break;
		
	}
	
	EIMSK |= (1<<interruptPin);
	sei();
	
	switch (interruptPin) {
		
		case INT0:
		int0Fun = funPtr;
		break;
		
		case INT1:
		int1Fun = funPtr;
		break;
		
		case INT2:
		int2Fun = funPtr;
		break;
		
		case INT3:
		int3Fun = funPtr;
		break;
		
	}
	
}


ISR (INT0_vect) {
	int0Fun();
}
ISR (INT1_vect) {
	int1Fun();
}
ISR (INT2_vect) {
	int2Fun();
}
ISR (INT3_vect) {
	int3Fun();
}