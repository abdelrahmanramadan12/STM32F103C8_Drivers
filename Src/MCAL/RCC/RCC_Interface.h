/*
 *      @file RCC_Interface.h
 *
 *      @brief This header file defines the interface for the Reset and Clock Control (RCC) module,
 *      which is responsible for configuring and controlling the system clock and various
 *      peripheral clocks in a microcontroller.
 *
 *      @author Abdelrahman Ramadan
 *
 *      @date Dec 22, 2023
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_





/*___________________________________________________________________________________________

**************************  RCC ENUMS                             **************************
___________________________________________________________________________________________*/
typedef enum
{
  CLK_HSI,
  CLK_HSE,
  CLK_PLL
} clk_t;

typedef enum
{
  DISABLE,
  ENABLE

} Status_t;

typedef enum
{
 HSE_Dvi_1,
 HSE_Dvi_2
}HSE_Presc_t;

typedef enum
{
  PLLSrc_HSI,
  PLLSrc_HSE
} PLLSrc_t;

typedef enum
{
  PLLMUL_2  =(0<<18),
  PLLMUL_3  =(1<<18),
  PLLMUL_4=(2<<18),
  PLLMUL_5=(3<<18),
  PLLMUL_6=(4<<18),
  PLLMUL_7=(5<<18),
  PLLMUL_8=(6<<18),
  PLLMUL_9=(7<<18),
  PLLMUL_10=(8<<18),
  PLLMUL_11=(9<<18),
  PLLMUL_12=(10<<18),
  PLLMUL_13=(11<<18),
  PLLMUL_14=(12<<18),
  PLLMUL_15=(13<<18),
  PLLMUL_16=(14<<18)
} PLLMUL_t;

typedef enum
{
    _DMA1  =0 ,
    _DMA2     ,
    _SRAM     ,
	lol,
    _FLITF  ,
	loll,
    _CRC    ,
	lolll,
    _FSMC   ,
	lollll,
    _SDIO  ,
} AHB_Peripheral_t;

typedef enum
{
	_TIM2     ,
	_TIM3     ,
	_TIM4     ,
	_TIM5     ,
	_TIM6     ,
	_TIM7     ,
	_WWDG =11 ,
	_SPI2 =14 ,
	_SPI3     ,
	_USART2=17,
	_USART3   ,
	_UART4    ,
	_UART5    ,
	_I2C1     ,
	_I2C2     ,
	_USB      ,
	_CAN1 =25 ,
	_CAN2     ,
	_BKP      ,
	_PWR      ,
	_DAC      ,

} APB1_Peripheral_t;

typedef enum
{
	   _AFIO   =0 ,
	   _GPIOA  =2 ,
	   _GPIOB     ,
	   _GPIOC     ,
	   _GPIOD     ,
	   _GPIOE     ,
	   _ADC1   =9 ,
	   _ADC2     ,
	   _TIM1     ,
	   _SPI1     ,
	   _USART1=14,

} APB2_Peripheral_t;

/*___________________________________________________________________________________________*/
/*___________________________________________________________________________________________*/
/*___________________________________________________________________________________________*/


/*___________________________________________________________________________________________

**************************   RCC Functions Declaration           ****************************
___________________________________________________________________________________________*/

uint8_t MRCC_setClockSts(clk_t clk   , Status_t  status);


uint8_t MRCC_setSystemClk(clk_t clk );



uint8_t MRCC_HSE_Config(HSE_Presc_t  HSE_Presc);


uint8_t MRCC_PLL_Config(PLLSrc_t  Src_t,PLLMUL_t Mull_t);


void MRCC_AHB_EnablePeripheralClk(AHB_Peripheral_t Peripheral );
void MRCC_AHB_DisablePeripheralClk(AHB_Peripheral_t Peripheral );

void MRCC_APB1_EnablePeripheralClk(APB1_Peripheral_t Peripheral);
void MRCC_APB1_DisablePeripheralClk(APB1_Peripheral_t Peripheral);

void MRCC_APB2_EnablePeripheralClk(APB2_Peripheral_t Peripheral);
void MRCC_APB2_DisablePeripheralClk(APB2_Peripheral_t Peripheral);


#endif /* RCC_RCC_INTERFACE_H_ */
