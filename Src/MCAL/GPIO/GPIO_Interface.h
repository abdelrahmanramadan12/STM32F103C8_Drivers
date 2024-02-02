/*
 * GPIO_Interface.h
 *
 *  Created on: Dec 23, 2023
 *      Author: abdel
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_



typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
    NUM_OF_PORTS
}Port_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	NUM_OF_PINS
}Pin_t;

typedef enum{
	INPUT=0,
	OUTPUT_10MHZ,
	OUTPUT_2MHZ,
	OUTPUT_50MHZ
}Mode_t;

/**************************ENUM to select the output type**********************************/
typedef enum{
	OP_PUSH_PULL,
	OP_OPEN_DRAIN,
	AF_PUSH_PULL,
	AF_OPEN_DRAIN

}OutputType_t;

typedef enum{
ANALOG,
FLOATING,
PULL_UP_DOWM

}InputType_t;

typedef enum
{
	LOW,
	HIGH
}PinStatus_t;

typedef struct
{
  Port_t        port;
  Pin_t         PinNum;
  Mode_t        Mode;
  OutputType_t  OutputType;
  InputType_t   InputType;
 // AltFunc_t     AltFunc;
}GPIO_PinConfig_t;

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t*  PinConfig);

uint8_t GPIO_u8SetPinValue(Port_t Port ,Pin_t PinNUm , PinStatus_t  PinStatus);

uint8_t GPIO_u8TogglePinValue(Port_t Port ,Pin_t PinNUm );

uint8_t GPIO_u8ReadPinValue(Port_t Port ,Pin_t PinNUm , PinStatus_t*  PinStatus);
void GPIO_WritePort(Port_t Port,uint8_t value);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
