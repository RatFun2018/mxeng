//Example ATmega2560 Project
//File: ATmega2560Project.c
//An example file for second year mechatronics project

//include this .c file's header file
#include "../Robot.h"
#include <math.h>

//static function prototypes, functions only called in this file

float strength = 1.0;
int midPoint;

int main(void) {
  DDRA = 0xFF;//put PORTA into output mode
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
	
	int amnt = 8 * temp;		//amount of leds
	
	PORTA = 0;
	for (int i = 0; i < 8; i ++) {
		
		if (i >= amnt) {break;}
		PORTA |= (1 << i);
		
	}
	
	_delay_ms(16);
   
   
  }
  return(1);
}//end main 