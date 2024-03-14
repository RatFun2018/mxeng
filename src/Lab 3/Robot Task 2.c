#include "Robot.h"
#include "../lib/Interrupt.h"

#define DEBOUNCE_DELAY 100

void ButtonPressed();

uint32_t previousButtonTime = 0;


int main(void) {
	
	milliseconds_init();
	
	DDRA = 0xFF;
	AttachInterrupt(INT0, RISING, &ButtonPressed);
	
	while (1) {}
	return 1;
	
}


void ButtonPressed() {
	
	uint32_t currentButtonTime = milliseconds_now();
	if (currentButtonTime - previousButtonTime < DEBOUNCE_DELAY) {return;}
	previousButtonTime = currentButtonTime;
	
	if (PORTA == 0) {
		PORTA = 1;
	}
	else {
		PORTA = 0;
	}
	
}
