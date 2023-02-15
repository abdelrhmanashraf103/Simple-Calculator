/*
 * main.c
 *
 * Created: 14/02/2022 10:11:23 م
 * Author : Abdelrahman Ashraf
 */ 

#include <avr/io.h>
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/dio_configuration.h"
#include "HAL/KEYPAD/keypad_driver.h"
#include "HAL/LCD/LCD.h"



int main(void)
{
	LCD_vInit();
	LCD_vSend_string("welcome to your");
	LCD_movecursor(2,1);
	LCD_vSend_string("SimpleCalculator");
	_delay_ms(1000);
	LCD_clearscreen();
	
	label:LCD_vInit();
	keypad_vInit();
	
	uint8 arr[7]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED};
	uint16 result;
	uint8 counter;
	
    while (1) 
    {
		
		
		
		do //enter the first digit of the first number
		{
			arr[counter]=keypad_u8check_press();
		} while (arr[counter]==NOTPRESSED);
		
		if (arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-' || arr[counter]=='/'||arr[counter]=='*')
		{
			LCD_clearscreen();
			goto label;
		}
		else
		{
			LCD_vSend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		
		
		do  //enter the second digit of the first number
		{
			arr[counter]=keypad_u8check_press();
		} while (arr[counter]==NOTPRESSED);
		
		if (arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-' || arr[counter]=='/'||arr[counter]=='*')
		{
			LCD_clearscreen();
			goto label;
		}
		else
		{
			LCD_vSend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		
		do  //enter the operator
		{
			arr[counter]=keypad_u8check_press();
		} while (arr[counter]==NOTPRESSED);
		
		if (arr[counter]=='A'||arr[counter]=='=')
		{
			LCD_clearscreen();
			goto label;
		}
		else
		{
			LCD_vSend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		
		do  //enter the first digit of the second number
		{
			arr[counter]=keypad_u8check_press();
		} while (arr[counter]==NOTPRESSED);
		
		if (arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-' || arr[counter]=='/'||arr[counter]=='*')
		{
			LCD_clearscreen();
			goto label;
		}
		else
		{
			LCD_vSend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		
		do  //enter the second digit of the second number
		{
			arr[counter]=keypad_u8check_press();
		} while (arr[counter]==NOTPRESSED);
		
		if (arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-' || arr[counter]=='/'||arr[counter]=='*')
		{
			LCD_clearscreen();
			goto label;
		}
		else
		{
			LCD_vSend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		
		do  //enter the equal operator
		{
			arr[counter]=keypad_u8check_press();
		} while (arr[counter]==NOTPRESSED);
		
		if (arr[counter]=='=')
		{
			LCD_vSend_char(arr[counter]);
			
			switch(arr[counter-3])
			{
				case '+':
				result=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
				if(result>=100&&result<1000)
				{
					LCD_vSend_char((result/100)+48);
					LCD_vSend_char(((result/10)%10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if (result>=10&&result<100)
				{
					LCD_vSend_char((result/10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if(result<10)
				{
					LCD_vSend_char(result+48);
				}
				break;
				case '-' :
				result=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(result>=100&&result<1000)
				{
					LCD_vSend_char((result/100)+48);
					LCD_vSend_char(((result/10)%10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if (result>=10&&result<100)
				{
					LCD_vSend_char((result/10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if(result<10)
				{
					LCD_vSend_char(result+48);
				}
				break;
				case '*':
				result=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(result>=1000&&result<10000)
				{
					LCD_vSend_char((result/1000)+48);
					LCD_vSend_char(((result/100)%10)+48);
					LCD_vSend_char(((result/10)%10)+48);
					LCD_vSend_char((result%10)+48);
					
				}
				else if(result>=100&&result<1000)
				{
					LCD_vSend_char((result/100)+48);
					LCD_vSend_char(((result/10)%10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if (result>=10&&result<100)
				{
					LCD_vSend_char((result/10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if(result<10)
				{
					LCD_vSend_char(result+48);
				}
				break;
				case '/':
				result=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(result>=100&&result<1000)
				{
					LCD_vSend_char((result/100)+48);
					LCD_vSend_char(((result/10)%10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if (result>=10&&result<100)
				{
					LCD_vSend_char((result/10)+48);
					LCD_vSend_char((result%10)+48);
				}
				else if(result<10)
				{
					LCD_vSend_char(result+48);
				}
				break;
				default : break;
				
				
			}
		}
		else
		{
			LCD_clearscreen();
			goto label;
		}
		_delay_ms(100);
		
    }
}

