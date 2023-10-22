/******************* Layer : HAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : HCAL *********************/
/****************** Date : 17/8/2023 ******************/
/****************** COmponent : LCD ******************/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendString(char *Copy_pcString);
void CLCD_voidInit(void);
void CLCD_voidSendNum(u32 num);
void CLCD_voidSetPosition(u8 Copy_u8X,u8 Copy_u8Y);
void CLCD_voidDrawSpecialChar(u8 *Copy_Pu8Pattern, u8 Copy_u8Loc,u8 Copy_u8x,u8 Copy_u8y);



#endif
