/*
 *      @file RCC_Program.c
 *
 *      @brief This source file contains the implementation of
 *      the RCC functions
 *
 *      @author Abdelrahman Ramadan
 *
 *      @date Dec 22, 2023
 */

#include "../../Library/Stm32f103C8T6.h"
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"

#include "RCC_Cfg.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"


/*
 * Set the clock status for a specific clock source
 *
 * Parameters:
 *   - clk: Clock source  CLK_HSI,
                          CLK_HSE,
                          CLK_PLL
 *   - status: Status to set for the clock source
 *                        DISABLE
 *                        ENABLE
 *
 * Returns:
 *   - 8-bit unsigned integer indicating success or failure
 */
uint8_t MRCC_setClockSts(clk_t clk   , Status_t  status)
{
	uint32 timeout_count=0;
/********************************* HSE Enable Or Disable *******************/
	switch (clk) {
		case CLK_HSE:
			 if (status==ENABLE)
			 {
              SET_BIT(RCC->CR,RCC_CR_HSEON 	);
              while ((GET_BIT(RCC->CR,RCC_CR_HSERDY)==0) && timeout_count<TIMEOUT)
              {
            	  timeout_count++;
              }

					  if (timeout_count>=TIMEOUT)
					  {
						  return STD_TYPES_NOK;
					  }

			 }
			 else if (status==DISABLE)
			 {
			    CLEAR_BIT(RCC->CR,RCC_CR_HSEON );
		     }
			 else
			 {
				 return STD_TYPES_NOK;
			 }

			break;
/********************************* HSI Enable Or Disable *******************/
		case CLK_HSI:
			 if (status==ENABLE)
			 {
             SET_BIT(RCC->CR,RCC_CR_HSION 	);
             while ((GET_BIT(RCC->CR,RCC_CR_HSIRDY)==0) && timeout_count<TIMEOUT)
             {
           	  timeout_count++;
             }
                        if (timeout_count>=TIMEOUT)
           				 {
           					 return STD_TYPES_NOK;
           		     	  }


			 }
			 else if (status==DISABLE)
			 {
			   CLEAR_BIT(RCC->CR,RCC_CR_HSION );
			 }
			 else
			 {
                return STD_TYPES_NOK;
			 }
			break;
/********************************* PLL Enable Or Disable *******************/
		case CLK_PLL:
			 if (status==ENABLE)
			 {
            SET_BIT(RCC->CR,RCC_CR_PLLON 	);
            while ((GET_BIT(RCC->CR,RCC_CR_PLLRDY)==0) && timeout_count<TIMEOUT)
            {
          	  timeout_count++;
            }
                       if (timeout_count>=TIMEOUT)
          				 {
          					 return STD_TYPES_NOK;
          		     	  }


			 }
			 else if (status==DISABLE)
			 {
			   CLEAR_BIT(RCC->CR,RCC_CR_PLLON );
			 }
			 else
			 {
               return STD_TYPES_NOK;
			 }

			break;
		default: return STD_TYPES_NOK;



	}
	return STD_TYPES_OK;
}

/*
 * Set the system clock source
 *
 * Parameters:
 *   - clk: Clock source to set as the system clock
 *                        CLK_HSI,
                          CLK_HSE,
                          CLK_PLL
 *
 * Returns:
 *   - 8-bit unsigned integer indicating success or failure
 */

uint8_t MRCC_setSystemClk(clk_t clk )
{
   switch (clk) {
	case CLK_HSI:
		CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW1);
		CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW2);
		break;
	case CLK_HSE:
		SET_BIT(RCC->CFGR,RCC_CFGR_SW1);
		CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW2);
		break;
	case CLK_PLL:
		CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW1);
		SET_BIT(RCC->CFGR,RCC_CFGR_SW2);
		break;
	default:return STD_TYPES_NOK;
}

  return STD_TYPES_OK;
}


/*
 * Configure the High-Speed External (HSE) clock
 *
 * Parameters:
 *   - HSE_Presc: HSE prescaler configuration
 *                    HSE_Dvi_1,
                      HSE_Dvi_2
 *
 * Returns:
 *   - 8-bit unsigned integer indicating success or failure
 */
uint8_t MRCC_HSE_Config(HSE_Presc_t  HSE_Presc)
{
   switch (HSE_Presc)
   {
	case  HSE_Dvi_1:
		RCC->CFGR &=(~RCC_CFGR_PLLXTPRE_MASK );
		break;

	case  HSE_Dvi_2:
			RCC->CFGR |=(RCC_CFGR_PLLXTPRE_MASK);
			break;
	default:return STD_TYPES_NOK;


   }
   return STD_TYPES_OK;
}

/*
 * Configure the Phase-Locked Loop (PLL)
 *
 * Parameters:
 *   - Src_t: PLL source configuration
 *                   PLLSrc_HSI,
                     PLLSrc_HSE
 *   - Mull_t: PLL multiplication factor configuration
 *             PLLMUL_2,PLLMUL_3 ,PLLMUL_4,PLLMUL_5,PLLMUL_6,PLLMUL_7,PLLMUL_8,PLLMUL_9,
               PLLMUL_10,PLLMUL_11,PLLMUL_12,PLLMUL_13,PLLMUL_14,PLLMUL_15,PLLMUL_16
 *
 * Returns:
 *   - 8-bit unsigned integer indicating success or failure
 */
uint8_t MRCC_PLL_Config(PLLSrc_t  Src_t,PLLMUL_t Mull_t)
{
	if (Src_t==PLLSrc_HSI)
	{
		RCC->CFGR &=(~RCC_CFGR_PLLSRC_MASK );
	}
	else if (Src_t==PLLSrc_HSE)
	{
		RCC->CFGR |=(RCC_CFGR_PLLSRC_MASK);
	}
	else
	{
		return STD_TYPES_NOK;
	}

    RCC->CFGR &=(~RCC_CFGR_PLLMUL_MASK );
    RCC->CFGR |=(Mull_t);

	return STD_TYPES_OK;

}

/*
 * Enable the clock for a specific AHB peripheral
 *
 * Parameters:
 *   - Peripheral: AHB peripheral to enable clock for
 *          _DMA1     ,
			_DMA2     ,
			_SRAM     ,
			_FLITF    ,
			_CRC      ,
			_FSMC     ,
			_SDIO
 */
void MRCC_AHB_EnablePeripheralClk(AHB_Peripheral_t Peripheral )
{
	SET_BIT(RCC->AHBENR,Peripheral);
}
/*
 * Disable the clock for a specific AHB peripheral
 *
 * Parameters:
 *   - Peripheral: AHB peripheral to enable clock for
 *          _DMA1     ,
			_DMA2     ,
			_SRAM     ,
			_FLITF    ,
			_CRC      ,
			_FSMC     ,
			_SDIO
 */
void MRCC_AHB_DisablePeripheralClk(AHB_Peripheral_t Peripheral )
{
	CLEAR_BIT(RCC->AHBENR,Peripheral);
}


/*
 * Enable the clock for a specific APB1 peripheral
 *
 * Parameters:
 *   - Peripheral: APB1 peripheral to enable clock for
 *  _TIM2     ,_TIM3     ,_TIM4     ,_TIM5     ,
	_TIM6     ,_TIM7     ,_WWDG     ,_SPI2     ,
	_SPI3     ,_USART2   ,_USART3   ,_UART4    ,
	_UART5    ,_I2C1     ,_I2C2     ,_USB      ,
	_CAN1     ,_CAN2     ,_BKP      ,_PWR      ,
	_DAC      ,
 *
 */

void MRCC_APB1_EnablePeripheralClk(APB1_Peripheral_t Peripheral)
{
	SET_BIT(RCC->APB1ENR,Peripheral);
}

/*
 * Disable the clock for a specific APB1 peripheral
 *
 * Parameters:
 *   - Peripheral: APB1 peripheral to enable clock for
 *  _TIM2     ,_TIM3     ,_TIM4     ,_TIM5     ,
	_TIM6     ,_TIM7     ,_WWDG     ,_SPI2     ,
	_SPI3     ,_USART2   ,_USART3   ,_UART4    ,
	_UART5    ,_I2C1     ,_I2C2     ,_USB      ,
	_CAN1     ,_CAN2     ,_BKP      ,_PWR      ,
	_DAC      ,
 *
 */
void MRCC_APB1_DisablePeripheralClk(APB1_Peripheral_t Peripheral)
{
	CLEAR_BIT(RCC->APB1ENR,Peripheral);
}



/*
 * Enable the clock for a specific APB2 peripheral
 *
 * Parameters:
 *   - Peripheral: APB2 peripheral to enable clock for
 *     _AFIO      ,_GPIOA     ,_GPIOB     ,
	   _GPIOC     ,_GPIOD     ,_GPIOE     ,
	   _ADC1      ,_ADC2      ,_TIM1     ,
	   _SPI1      ,_USART1    ,
 */
void MRCC_APB2_EnablePeripheralClk(APB2_Peripheral_t Peripheral)
{
	SET_BIT(RCC->APB2ENR,Peripheral);
}

/*
 * Disable the clock for a specific APB2 peripheral
 *
 * Parameters:
 *   - Peripheral: APB2 peripheral to enable clock for
 *     _AFIO      ,_GPIOA     ,_GPIOB     ,
	   _GPIOC     ,_GPIOD     ,_GPIOE     ,
	   _ADC1      ,_ADC2      ,_TIM1     ,
	   _SPI1      ,_USART1    ,
 */
void MRCC_APB2_DisablePeripheralClk(APB2_Peripheral_t Peripheral)
{
	CLEAR_BIT(RCC->APB2ENR,Peripheral);
}
