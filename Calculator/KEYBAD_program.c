#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "KEYBAD_private.h"
#include "KEYBAD_config.h"
#include "KEYBAD_interface.h"


 u8 KPD_u8GetPressedKey(void){
	 u8 Local_u8Col, Local_u8Row, Local_u8Reading, Local_u8Key;

	 u8 KPD_u8Values[MAX_ROW][MAX_COL]=KPD_VALUES;
	 for(Local_u8Col=COL_INIT;Local_u8Col<COL_FIN;Local_u8Col++)
	 {
		 DIO_voidSetPinVal(KPD_PORT,Local_u8Col,PIN_VAL_LOW);

		 for(Local_u8Row=ROW_INIT;Local_u8Row<ROW_FIN;Local_u8Row++)
		 {
			 Local_u8Reading = DIO_u8GetPinVal(KPD_PORT,Local_u8Row+4);

			 if(Local_u8Reading==PIN_VAL_LOW)
			 {
				 Local_u8Key = KPD_u8Values[Local_u8Row][Local_u8Col];
				 _delay_ms(10);
				 while(DIO_u8GetPinVal(KPD_PORT,Local_u8Row+4)==PIN_VAL_LOW){}
			 }

		 }
		 DIO_voidSetPinVal(KPD_PORT,Local_u8Col,PIN_VAL_HIGH);
	 }
	 return Local_u8Key;
 }
