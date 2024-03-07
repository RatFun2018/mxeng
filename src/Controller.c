//Example ATmega2560 Project
//File: ATmega2560Project.c
//An example file for second year mechatronics project

//include this .c file's header file
#include "Controller.h"

//static function prototypes, functions only called in this file

int main(void) {
  DDRA = 0xFF;//put PORTA into output mode
  PORTA = 0; 
  while(1)  {
	PORTA += 1;
	_delay_ms(100);
  }
  return(1);
}//end main