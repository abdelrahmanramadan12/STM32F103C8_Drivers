/*
 *      @file GPIO_Program.c
 *
 *      Created on: Dec 23, 2023
 *      @author: Abdelrahman Ramadan 
 *      @brief The GPIO main source file ,including functions' definitions 
 *
 */

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATHS.h"
#include "../../Library/Stm32f103C8T6.h"

#include "GPIO_Private.h"
#include "GPIO_Cfg.h"
#include "GPIO_Interface.h"


/**************************************************************************
*   @fn GPIO_u8PinInit
*   @brief initializing the GPIO pin according to the input parameters
*   @param[in]  PinConfig : the initialization values of the pin
*   @retval errtorStatus 
*/

static  GPIO_RegDef_t *GPIO_PORT_Arr [NUM_OF_PORTS]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF};

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t*  PinConfig)
{
	uint8_t  local_u8ErrorState = STD_TYPES_OK;
	if (PinConfig!= NULL)
	{
		if ((PinConfig->port < NUM_OF_PORTS)&&(PinConfig->PinNum < NUM_OF_PINS))
		{
			uint8_t _u8RegNum=(PinConfig->PinNum/8);
			uint8_t _u8BitNum=(PinConfig->PinNum%8);

			switch (_u8RegNum) {
				case 0:
					/***********CLear 4 BITs for MODE and CNF******/
					GPIO_PORT_Arr[PinConfig->port]->CRL  &=((~CRL_CLEAR_MASK)<<_u8BitNum*BIT_LOC_MUL);
					/**********************************************/
					/*******************Set bits to select Select the mode INPUT,OUTPUT_10MHZ,OUTPUT_2MHZ,OUTPUT_50MHZ****/
					GPIO_PORT_Arr[PinConfig->port]->CRL  |=((PinConfig->Mode)<<_u8BitNum*BIT_LOC_MUL);
					if (PinConfig->Mode==INPUT)
					{
						/*****Set Pins for the input type (CRL)***************/
						GPIO_PORT_Arr[PinConfig->port]->CRL  |=((PinConfig->InputType)<<((_u8BitNum*BIT_LOC_MUL)+2));
					}
					else
					{
						/*****Set Pins for the output type  (CRL) ***************/
						GPIO_PORT_Arr[PinConfig->port]->CRL  |=((PinConfig->OutputType)<<((_u8BitNum*BIT_LOC_MUL)+2));
					}
					break;
				case 1:
					/***********CLear 4 BITs for MODE and CNF******/
					GPIO_PORT_Arr[PinConfig->port]->CRH  &=((~CRL_CLEAR_MASK)<<_u8BitNum*BIT_LOC_MUL);
					/**********************************************/
					/*******************Set bits to select the mode INPUT,OUTPUT_10MHZ,OUTPUT_2MHZ,OUTPUT_50MHZ****/
					GPIO_PORT_Arr[PinConfig->port]->CRH  |=((PinConfig->Mode)<<_u8BitNum*BIT_LOC_MUL);
					if (PinConfig->Mode==INPUT)
					{
						/*****Set Pins for the input type ***************/
						GPIO_PORT_Arr[PinConfig->port]->CRH  |=((PinConfig->InputType)<<((_u8BitNum*BIT_LOC_MUL)+2));
					}
					else
					{
						/*****Set Pins for the output type ***************/
						GPIO_PORT_Arr[PinConfig->port]->CRH  |=((PinConfig->OutputType)<<((_u8BitNum*BIT_LOC_MUL)+2));
					}

					break;
				default:
					break;
			}

		}
		else 
		{
			local_u8ErrorState =STD_TYPES_NOK;
		}
	}
	else 
	{
		local_u8ErrorState = ERROR_NULL_PTR;

	}
	
	return local_u8ErrorState;
}
/**************************************************************************
*   @fn GPIO_u8SetPinValue
*   @brief setting the value of GPIO pin according to the input value
*   @param [in]  Port     : to select the port
*   @param [in]  PinNum   : to select the number of the pin
*   @param [in]  PinStatus: to select the status HIGH or LOW
*   @retval errtorStatus
*/
uint8_t GPIO_u8SetPinValue(Port_t Port ,Pin_t PinNum , PinStatus_t  PinStatus)
{
	uint8_t  local_u8ErrorState = STD_TYPES_OK;

		if ((Port < NUM_OF_PORTS)&&(PinNum < NUM_OF_PINS))
		{

				switch (PinStatus)
				{
					case HIGH:
						 GPIO_PORT_Arr[Port]->BSRR=SET_VALUE<<PinNum;
						break;
					case LOW:
						 GPIO_PORT_Arr[Port]->BRR=SET_VALUE<<PinNum;
						break;
					default:
					     local_u8ErrorState=STD_TYPES_NOK;
						break;
				}
		}
		else
		{
			local_u8ErrorState=STD_TYPES_NOK;
		}
		return local_u8ErrorState;

}

uint8_t GPIO_u8TogglePinValue(Port_t Port ,Pin_t PinNum )
{
	uint8_t  local_u8ErrorState = STD_TYPES_OK;

		if ((Port < NUM_OF_PORTS)&&(PinNum < NUM_OF_PINS))
		{
          GPIO_PORT_Arr[Port]->ODR^=(SET_VALUE<<PinNum);

		}
		else
		{
			local_u8ErrorState=STD_TYPES_NOK;
		}
		return local_u8ErrorState;


}

uint8_t GPIO_u8ReadPinValue(Port_t Port ,Pin_t PinNum , PinStatus_t*  PinStatus)
{
	uint8_t  local_u8ErrorState = STD_TYPES_OK;

		if ((Port < NUM_OF_PORTS)&&(PinNum < NUM_OF_PINS))
		{
        *PinStatus = SET_VALUE|(GPIO_PORT_Arr[Port]->IDR>>PinNum);

		}
		else
		{
			local_u8ErrorState=STD_TYPES_NOK;
		}
		return local_u8ErrorState;
}
void GPIO_WritePort(Port_t Port,uint8_t value)
{
	switch(Port)
	{
		case PORTA:
		GPIOA->IDR =value;
		break;
		case PORTB:

			GPIOB->IDR=value;
		break;
		case PORTC:

			GPIOC->IDR=value;
		break;
		case PORTD:

			GPIOD->IDR=value;
		break;
		case PORTE:

			GPIOE->IDR=value;
		break;
	}


}
