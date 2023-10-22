#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"






void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	//Set RS->0 , Set RW ->0  for send command
	DIO_voidSetPinVal(CLCD_CTRL_PORT,RS,PIN_VAL_LOW);
	DIO_voidSetPinVal(CLCD_CTRL_PORT,RW,PIN_VAL_LOW);
     DIO_voidSetPortVal(CLCD_DATA_PORT,Copy_u8Command);

  // SET ENable PULSE
     DIO_voidSetPinVal(CLCD_CTRL_PORT,EN,PIN_VAL_HIGH);
  _delay_ms(1);
  DIO_voidSetPinVal(CLCD_CTRL_PORT,EN,PIN_VAL_LOW);

}



void CLCD_voidSendData(u8 Copy_u8Data)
{
  //Set RS->1 , Set RW ->0  for send command
  DIO_voidSetPinVal(CLCD_CTRL_PORT,RS,PIN_VAL_HIGH);
  DIO_voidSetPinVal(CLCD_CTRL_PORT,RW,PIN_VAL_LOW);
  DIO_voidSetPortVal(CLCD_DATA_PORT,Copy_u8Data);

  // SET ENable PULSE
  DIO_voidSetPinVal(CLCD_CTRL_PORT,EN,PIN_VAL_HIGH);
  _delay_ms(1);
  DIO_voidSetPinVal(CLCD_CTRL_PORT,EN,PIN_VAL_LOW);

}


void CLCD_voidInit(void)
{
_delay_ms(40);
CLCD_voidSendCommand(0b00111000);
_delay_ms(1);
CLCD_voidSendCommand(0b00001100);
_delay_ms(1);
CLCD_voidSendCommand(0b00000001);
_delay_ms(2);


}

void CLCD_voidSendString(char *Copy_pcString){
	for (u8 i=0;Copy_pcString[i]!='\0';i++)
	{
		CLCD_voidSendData(Copy_pcString[i]);

	}


	/*u8 Local_u8Iterator=0;
	 * while (Copy_pcString[Local_u8Iterator]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Iterator]);
		Local_u8Iterator++;
	}*/
}



void CLCD_voidSendNum(u32 num)
{
	u8 Local_u8arr[10];
	u8 i=0;
	u8 j=0;
	if (num==0)
	{
		CLCD_voidSendData('0');    //send the asci of zero
	}
	else
	{
		while (num)
		{
			Local_u8arr[i]= num%10 +'0';
			num/=10;
			i++;
		}
		for (j=i;j>0;j--)
		{
			CLCD_voidSendData(Local_u8arr[j-1]);

		}
	}
}


void CLCD_voidSetPosition(u8 Copy_u8X,u8 Copy_u8Y){
	u8 Local_u8_position=0;
	if (Copy_u8X==0){
		Local_u8_position= Copy_u8Y;

	}
	else if (Copy_u8X==1){
		Local_u8_position= Copy_u8Y+0x40;
	}
	CLCD_voidSendCommand(Local_u8_position+128);
}

void CLCD_voidDrawSpecialChar(u8 *Copy_Pu8Pattern, u8 Copy_u8Loc,u8 Copy_u8x,u8 Copy_u8y)
{
	//the special character will be array of 8 components, 5 bits each ( in other words, 8 bits each but the grid can afford only 5 )
	u8 Local_u8Iterator=0;
	//in which grid we will display your special character
	u8 Local_u8Cgram_Add= Copy_u8Loc * 8;
	CLCD_voidSendCommand(Local_u8Cgram_Add+64);  //from data sheet, the sixth bit must be 1, so we add 64 -> (100000)

	for (;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_Pu8Pattern[Local_u8Iterator]);
	}
	CLCD_voidSetPosition(Copy_u8x,Copy_u8y);

}



