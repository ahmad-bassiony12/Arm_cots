/***************************************************************/
/******************       Author : Ahmad Bassiony *************/
/***********************   Layer : MCAL   **********************/
/************************  Version : 1.00  *********************/
/************************** SWC : RCC  ************************/
/***************************************************************/



#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define		RCC_AHB1		0
#define		RCC_AHB2		1
#define		RCC_APB1		2
#define		RCC_APB2		3

void 	RCC_voidSysClockInit(void);

void	RCC_voidEnablePerClk(u8 Bus,u8 Per);
void	RCC_voidDisablePerClk(u8 Bus,u8 Per);
void 	RCC_EnablePLL(uint8 PLL_CLKSource, uint8 PLL_Value);
#endif
