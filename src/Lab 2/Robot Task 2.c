
#include "../Robot.h"

float strength = 1.0;
int midPoint;

int main(void) {
	DDRA = 0xFF;
	PORTA = 0;
	
	adc_init();
	
	
	while(1) {
		
		
		uint16_t thermistorInput = adc_read(0);
		uint16_t analogInput = adc_read(1);
		uint16_t buttonInput = adc_read(2);
		
		if (buttonInput < 6) {
			midPoint = thermistorInput;
		}
		
		float calibrationStr = ((float)analogInput / 1023) - 0.5;
		strength *= pow(1.01, calibrationStr);
		
		float temp = ((float)((int)thermistorInput - midPoint) / 1023.0) * strength + 0.5;
		
		int amnt = 8 * temp;
		
		PORTA = 0;
		for (int i = 0; i < 8; i ++) {

			if (i >= amnt) {break;}
			PORTA |= (1 << i);

		}

		_delay_ms(16);
		
		
	}
	
	return(1);
	
}