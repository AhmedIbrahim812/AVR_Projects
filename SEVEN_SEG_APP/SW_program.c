#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_config.h"
#include "SW_private.h"



void SW_voidInit(SW_t my_switch)
{
	DIO_voidSetPinDir(my_switch.port_con,my_switch.pin_con,PIN_DIR_IN);
	if (my_switch.state==PULL_UP)
	{
		DIO_voidSetPinVal(my_switch.port_con,my_switch.pin_con,PIN_VAL_HIGH);

	}
	
}

u8 SW_u8GetPressed(SW_t my_switch)
{
	u8 Local_u8Reading=0;
	
	DIO_u8GetPinVal(my_switch.port_con,my_switch.pin_con);
	
	return Local_u8Reading;
}



