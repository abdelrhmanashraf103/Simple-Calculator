/*
 * calculator.c
 *
 * Created: 14/02/2022 10:11:23 �
 * Author : Abdelrahman Ashraf
 */ 

#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_
#include "../../MCAL/DIO/DIO.h"


#define NOTPRESSED 0xff


/*
	Function Name        : keypad_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the keypad.
*/
void keypad_vInit(void);

/*
	Function Name        : keypad_u8check_press
	Function Returns     : uint8
	Function Arguments   : void
	Function Description : Returns the pressed key or return NOT_PRESSED if no keys are pressed.
*/
uint8 keypad_u8check_press(void);

#endif /* KEYPAD_DRIVER_H_ */