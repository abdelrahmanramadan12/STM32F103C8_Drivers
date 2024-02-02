/*
 * Systick_Interface.h
 *
 *  Created on: Feb 1, 2024
 *      Author: abdel
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_


#define ms_TO_us      1000u


#define SysTick_CTRL_ENABLE_Pos 0

#define SysTick_CTRL_TICKINT_Pos 1


#define SysTick_CTRL_CLKSOURCE_Pos 2



#define SysTick_CTRL_COUNTFLAG_Pos 16

#define STK_AHB_CLK					0
#define STK_AHB_CLK_DIV_BY_8		1

#define STK_CLK		STK_AHB_CLK_DIV_BY_8


#define SysTick_LOAD_RELOAD_Pos 0

void SysTick_Init(uint32 Copy_u32Ticks);


void SysTick_voidBusyWait_ms(uint32 Copyu32NumOfTicks);



#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
