#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"



// This application is to control the number showed in seven seg using three push bottoms
// a bottom to increase the num by one
// another bottom to decrease the num by one
// last bottom to reset the showed value (make it 0)


void main (void)
{

	// PORT A is input (for the three push bottoms)
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_IN);
	//Initially high
	DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTA_REG,PIN1,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTA_REG,PIN2,PIN_VAL_HIGH);

	// PORT D is connected to Seven Seg
	DIO_voidSetPortDir(PORTD_REG,PORT_DIR_OUT);

	// Seven seg integer numbers representation (0 to 9)
	u8 SSD_arr[10] = {  0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111};


	while (1)
	{
		static u8 i=0;
		//show 0 in seven seg
		DIO_voidSetPortVal(PORTD_REG,SSD_arr[i]);

		// first bottom is pressed (increase value by one)
	if (DIO_u8GetPinVal(PORTA_REG,PIN0)==PIN_VAL_LOW){
		_delay_ms(500);
		DIO_voidSetPortVal(PORTD_REG,SSD_arr[i]);
		i++;
		DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);
		// when i reaches 10, reset i to 0
		if (i==10)
			i=0;
	}

	// second bottom is pressed (decreased value by one)
	else if (DIO_u8GetPinVal(PORTA_REG,PIN1)==PIN_VAL_LOW){
		_delay_ms(500);

		// when i =0, do nothing
		if (i==0)
			DIO_voidSetPortVal(PORTD_REG,SSD_arr[i]);
		else {
		DIO_voidSetPortVal(PORTD_REG,SSD_arr[i-1]);
		i--;
		}
		DIO_voidSetPinVal(PORTA_REG,PIN1,PIN_VAL_HIGH);

	}

	// third bottom reset the num to 0
	else if (DIO_u8GetPinVal(PORTA_REG,PIN2)==PIN_VAL_LOW)
	{
	i=0;
	DIO_voidSetPortVal(PORTD_REG,SSD_arr[i]);
	DIO_voidSetPinVal(PORTA_REG,PIN2,PIN_VAL_HIGH);
	}

	}
}


