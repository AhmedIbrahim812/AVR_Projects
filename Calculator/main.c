// Author : Ahmed Ibrahim
// Project : Simple Calculator (full configured calculator)

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KEYBAD_interface.h"
#include "util/delay.h"


int main(void)
{
	//Direction for port A and B for lcd connection
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTB_REG,PORT_DIR_OUT);
	//Direction for port C for key pad connection rows are inputs
	// columns are outputs
	DIO_voidSetPortDir(PORTC_REG,0b00001111);
	// initial port C is high
	DIO_voidSetPortVal(PORTC_REG,PORT_VAL_HIGH);


	// Initial the LCD
	CLCD_voidInit();

	// Initialize needed variables
	u8 operator;
	u8 arr[10];
	u8 num1=0,num2=0;
	u8 i=0,j=0;
	f32 result;
	f32 div;
	while(1)
	{
		// get the value of pressed key
		u8 pressed_key=KPD_u8GetPressedKey();

		//below if condition is for operations ( / , * , - , + )
		// 4 is divide, 8 is multiply, 12 is subtract, 16 is addition
		if(pressed_key==4 || pressed_key==8 || pressed_key==12 ||pressed_key==16)
		{
			// getting the value for first number
			for(j=0;j<i;j++)
			{
				num1 += arr[j];
			}
			// zeroing our itirator
			i=0;
			// save the operator
			operator=pressed_key;

			// Switch to display the operator on LCD
			switch(pressed_key)
			{
			case 4 : CLCD_voidSendString(" / ");_delay_ms(1);break;
			case 8 : CLCD_voidSendString(" * ");_delay_ms(1);break;
			case 12: CLCD_voidSendString(" - ");_delay_ms(1);break;
			case 16: CLCD_voidSendString(" + ");_delay_ms(1);break;
			}
		}

		// 13 is reset key , it clears all displayed data on lcd, and zeroing all variables
		else if(pressed_key==13)
		{
			CLCD_voidInit();
			num1=0;
			num2=0;
			result=0.0;
			div=0.0;
		}

		// 15 is equal key
		else if (pressed_key==15)
		{
			// Send "=" to lcd
			CLCD_voidSendString(" = ");

			// get the value of second number
			for(j=0;j<i;j++)
			{
				num2 += arr[j];
			}
			//zeroing the itirator
			i=0;

			// switch to calculate the result
			switch(operator)
			{

			//division
			case 4 :
				//division value
				result=(float)num1/num2;
				// get the value after decimal point
				div=(result - (int)result)*100;
				//send the integer value
				CLCD_voidSendNum(result);
				// send the decimal point
				CLCD_voidSendString(".");
				// send the friction value
				CLCD_voidSendNum(div);
				_delay_ms(1);
				break;

				//multiply
			case 8 :
				result=num1*num2;
				CLCD_voidSendNum(result);
				_delay_ms(1);
				break;

				//Subtract
			case 12:
				// positive answer
				if(num1>num2)
				{
					result=num1-num2;
					CLCD_voidSendNum(result);
					_delay_ms(1);
					break;
				}
				// negative answer
				else
				{
					result=num2-num1;
					CLCD_voidSendString("-");
					CLCD_voidSendNum(result);
					_delay_ms(1);
					break;
				}

				//Add
			case 16:
				result=num1+num2;
				CLCD_voidSendNum(result);
				_delay_ms(1);
				break;

			}
			// zeroing all numbers after calculating the result
			result=0.0;
			div=0.0;
			num1=0;
			num2=0;
		}

		// any other key will be a number
		else if (pressed_key == 1 || pressed_key ==2 || pressed_key ==3 || pressed_key ==5 || pressed_key ==6 || pressed_key ==7 ||pressed_key ==9 ||pressed_key ==10 || pressed_key ==11 || pressed_key ==14)
		{
			switch(pressed_key)
			{
			case 1 : arr[i]=7; CLCD_voidSendNum(7);_delay_ms(1);break;
			case 2 : arr[i]=8;CLCD_voidSendNum(8);_delay_ms(1);break;
			case 3 : arr[i]=9;CLCD_voidSendNum(9);_delay_ms(1);break;
			case 5 : arr[i]=4;CLCD_voidSendNum(4);_delay_ms(1);break;
			case 6 : arr[i]=5;CLCD_voidSendNum(5);_delay_ms(1);break;
			case 7 : arr[i]=6; CLCD_voidSendNum(6);_delay_ms(1);break;
			case 9 : arr[i]=1;CLCD_voidSendNum(1);_delay_ms(1);break;
			case 10: arr[i]=2;CLCD_voidSendNum(2);_delay_ms(1);break;
			case 11: arr[i]=3;CLCD_voidSendNum(3);_delay_ms(1);break;
			case 14: arr[i]=0;CLCD_voidSendNum(0);_delay_ms(1);break;
			}

			//in case user entered a number more than one digit
			for(j=0;j<i;j++)
			{
				arr[j] *= 10;
			}
			i++;
		}




	}




	return 0;
}



