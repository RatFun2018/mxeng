#include "ATMEGA2560.h"
#include "Interrupt.h"

#define DEBOUNCE_DELAY 100

uint32_t previousButtonTime = 0;

void ButtonPressed();

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