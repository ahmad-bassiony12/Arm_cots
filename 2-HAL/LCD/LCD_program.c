

#include "STD_TYPES.h"
#include "Bit_MATH.h"
#include "Software_Delay.h"

#include "GPIO_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/* Set RS pin to low for command */
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_u8_PIN_LOW);

	/* Set RW pin to low for write*/
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, GPIO_u8_PIN_LOW);

	/* Send the command to the data pins*/
	GPIO_u8SetChannelValue(LCD_DATA_PORT, LCD_DATA_STARTING_PIN, Copy_u8Command);

	/* Send Enable pulse */
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_u8_PIN_HIGH);
	_delay_ms(Enable_Wait);
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_u8_PIN_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS pin to high for Data */
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_u8_PIN_HIGH);

	 /* Set RW pin to low for write*/
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, GPIO_u8_PIN_LOW);

	/* Send the command to the data pins*/
	GPIO_u8SetChannelValue(LCD_DATA_PORT, LCD_DATA_STARTING_PIN, Copy_u8Data);

	/* Send Enable pulse */
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_u8_PIN_HIGH);
	_delay_ms(Enable_Wait);
	GPIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_u8_PIN_LOW);
}

void LCD_voidInit(void)
{
	/* Wait for more than 30ms */
	_delay_ms(Starting_Wait);

	/* Function Set Command : 2 Lines and 5*7 Font size */
	LCD_voidSendCommand(_2Lines_5Mul7);

	/* Display ON/OFF Command : Display Enable, Cursor Disable and No Blinking Cursor*/
	LCD_voidSendCommand(LCD_Display);

	/* Display Clear Command */
	LCD_voidSendCommand(CLR_SCREEN);

	/* Set Cursor Start Position */
	LCD_voidSendCommand(Start_Position);
}

void LCD_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	/* For the second line display add 0x40 to the Address */
	u8 Local_u8Address = (Copy_u8XPosition * 0x40) + (Copy_u8YPosition);

	/* Set bit 7 for DDRAM Address Command then send the Command */
	LCD_voidSendCommand(Local_u8Address + 128);
}

