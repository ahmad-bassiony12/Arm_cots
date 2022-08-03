/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HCAL " STM32F401 "        ************/
/************ Version : 1.00                      ************/
/************ SWC     : Character LCD             ************/
/*************************************************************/
/*************************************************************/


#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_


/*
	Choose Port for both Data pins and Control pins:
	Options:
		1) GPIO_PORTA
		2) GPIO_PORTB
		3) GPIO_PORTC
*/
#define LCD_DATA_PORT             GPIO_PORTA
#define LCD_CONTROL_PORT          GPIO_PORTC




#define LCD_DATA_STARTING_PIN     GPIO_u8_Pin0
#define LCD_RS_PIN                GPIO_u8_Pin13
#define LCD_RW_PIN                GPIO_u8_Pin14
#define LCD_E_PIN                 GPIO_u8_Pin15


/*
	Display Options:
		1) Display_OFF_Cursor_OFF
		2) Display_ON_Cursor_OFF
		3) Display_ON_Cursor_ON
		4) Display_ON_Cursor_Blinking
*/
#define LCD_Display              Display_ON_Cursor_OFF




#endif /* _LCD_CONFIG_H_ */
