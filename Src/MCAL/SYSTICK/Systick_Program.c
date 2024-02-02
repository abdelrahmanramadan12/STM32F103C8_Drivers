/*
 * Systick_Program.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Abdelrahman Ramadan
 */

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"
#include "../../Library/Stm32f103C8T6.h"

#include "Systick_Interface.h"



void SysTick_Init(uint32 Copy_u32Ticks)
{
	/*Disable SysTick counter */
	CLEAR_BIT(SysTick->CTRL ,SysTick_CTRL_ENABLE_Pos);
	/*Set reload REG */
	SysTick->LOAD=Copy_u32Ticks;
	/*Reset The sysTick counter value */
	SysTick->VAL=1;
	/*select the clock */
#if (STK_CLK==STK_AHB_CLK_DIV_BY_8)
	SET_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Pos);
#elif (STK_CLK==STK_AHB_CLK)
	CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_CLKSOURCE_Pos);
#else
#error "Invalid clock source"
#endif

	/*Disable SysTick IRQ*/
	CLEAR_BIT(SysTick->CTRL,SysTick_CTRL_TICKINT_Pos);

}



void SysTick_voidBusyWait_ms(uint32 Copyu32NumOfTicks)
{
	SysTick->LOAD=Copyu32NumOfTicks*ms_TO_us;
	/*Enable SysTick counter */
	SET_BIT(SysTick->CTRL ,SysTick_CTRL_ENABLE_Pos);
	while (GET_BIT(SysTick->CTRL ,SysTick_CTRL_COUNTFLAG_Pos)==0);
	/*Disable SysTick counter */
	CLEAR_BIT(SysTick->CTRL ,SysTick_CTRL_ENABLE_Pos);
	/*ReSet reload REG */
	SysTick->LOAD=0;
    /*Reset The sysTick counter value */
	SysTick->VAL=1;
}
