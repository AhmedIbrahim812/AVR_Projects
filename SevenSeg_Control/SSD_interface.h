/******************* Layer : HCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : HCAL *********************/
/****************** Date : 17/8/2023 ******************/
/****************** COmponent : LED ******************/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define COMMON_ANODE  1
#define COMMON_CATHODE  0


typedef struct {
	u8 dataport;
	u8 ctrlport;
	u8 ctrlpin;
	u8 activestate;
}SSD_t;


void SSD_voidSendNum(SSD_t s1,u8 Copy_u8num);
void SSD_voidEnable(SSD_t s1);
void SSD_voidDisable(SSD_t s1);




#endif
