#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"

#include "DIO_interface.h"

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

void SSD_voidSendNum(SSD_t s1,u8 Copy_u8num)
{
	if (s1.activestate== COMMON_CATHODE){
		DIO_voidSetPortVal(s1.dataport,SSD_arr[Copy_u8num]);
	}
	else if (s1.activestate== COMMON_ANODE){
		DIO_voidSetPortVal(s1.dataport,~(SSD_arr[Copy_u8num]));

	}
}

void SSD_voidEnable(SSD_t s1)
{
	if (s1.activestate==COMMON_CATHODE)
	{
		DIO_voidSetPinVal(s1.ctrlport,s1.ctrlpin,PIN_VAL_LOW);
	}
	else if (s1.activestate==COMMON_ANODE)
	{
		DIO_voidSetPinVal(s1.ctrlport,s1.ctrlpin,PIN_VAL_HIGH);
	}
}
	void SSD_voidDisable(SSD_t s1)
	{
		if (s1.activestate==COMMON_CATHODE)
		{
			DIO_voidSetPinVal(s1.ctrlport,s1.ctrlpin,PIN_VAL_HIGH);
		}
		else if (s1.activestate==COMMON_ANODE)
		{
			DIO_voidSetPinVal(s1.ctrlport,s1.ctrlpin,PIN_VAL_LOW);
		}
	}




