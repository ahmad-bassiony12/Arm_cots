#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* Choose your system clk */
#define Enable_HSI 0 
#define Enable_HSE 0 
#define Enable_PLL 1
#define PLL_CLK_Source HSE
#define PLL_Multiplication_Factor PLL_input_clock_x16	
#endif  /* CONFIG_H_ */