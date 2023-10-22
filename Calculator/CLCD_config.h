/******************* Layer : HAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : HCAL *********************/
/****************** Date : 17/8/2023 ******************/
/****************** COmponent : LCD ******************/


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*
 * PIN OPTIONS:
 * 1- PORTA_REG
 * 2- PORTB_REG
 * 3- PORTC_REG
 * 4- PORTD_REG
 */


/*
 * PORT OPTIONS:
 * 1- PIN0
 * 2- PIN1
 * 3-PIN
 * .
 * .
 * .
 * 8- PIN7
 *
 *
 */
#define CLCD_DATA_PORT     PORTA_REG

#define CLCD_CTRL_PORT     PORTB_REG
#define RS PIN0
#define RW PIN1
#define EN PIN2



#endif
