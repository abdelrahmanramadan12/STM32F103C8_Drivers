
#ifndef STM32F103C8T6_H
#define STM32F103C8T6_H


#include "STD_TYPES.h"


/*___________________________________________________________________________________________

**************************   various  Memories Base Addresses *******************************
___________________________________________________________________________________________*/


#define FLASH_BASE_ADDRESS       0x08000000UL
#define SRAM_BASE_ADDRESS        0x20000000UL
#define ROM_BASE_ADDRESS         0x1FFFF000UL


#define SysTick_BASE_ADDRESS     0xE000E010UL

/*___________________________________________________________________________________________

**************************    AHB Peripheral Base Addresses *********************************
___________________________________________________________________________________________*/


/*************Rcc Base Address******************/
#define RCC_BASE_ADDRESS             0x40021000U  
/*_____________________________________________*/




/*___________________________________________________________________________________________

**************************   APB1 Peripheral Base Addresses *******************************
___________________________________________________________________________________________*/





/*___________________________________________________________________________________________

**************************   APB2 Peripheral Base Addresses *******************************
___________________________________________________________________________________________*/

/*************GPIOx Base Addresses**************/
#define GPIOA_BASE_ADDRESS           0x40010800U 
#define GPIOB_BASE_ADDRESS           0x40010C00U 
#define GPIOC_BASE_ADDRESS           0x40011000U
#define GPIOD_BASE_ADDRESS           0x40011400U
#define GPIOE_BASE_ADDRESS           0x40011800U
#define GPIOF_BASE_ADDRESS           0x40011C00U
/*_____________________________________________*/




/*___________________________________________________________________________________________*/
/*___________________________________________________________________________________________*/
/*___________________________________________________________________________________________*/


/*___________________________________________________________________________________________

**************************   RCC Register Definition Structure ****************************
___________________________________________________________________________________________*/

typedef struct {
    volatile uint32 CR;          /* Clock control register ****************/
    volatile uint32 CFGR;        /* Clock configuration register **********/
    volatile uint32 CIR;         /* Clock interrupt register **************/
    volatile uint32 APB2RSTR;    /* APB2 peripheral reset register ********/
    volatile uint32 APB1RSTR;    /* APB1 peripheral reset register ********/
    volatile uint32 AHBENR;      /* AHB peripheral clock enable register***/
    volatile uint32 APB2ENR;     /* APB2 peripheral clock enable register**/
    volatile uint32 APB1ENR;     /* APB1 peripheral clock enable register**/
    volatile uint32 BDCR;        /* Backup domain control register*********/
    volatile uint32 CSR;         /* Control/status register****************/
} RCC_RegDef_t;



/*___________________________________________________________________________________________

**************************   GPIO Register Definition Structure ****************************
___________________________________________________________________________________________*/


typedef struct {
    volatile uint32 CRL;    /* Configuration Register Low***/
    volatile uint32 CRH;    /* Configuration Register High**/
    volatile uint32 IDR;    /* Input Data Register  ********/
    volatile uint32 ODR;    /* Output Data Register ********/
    volatile uint32 BSRR;   /* Bit Set/Reset Register ******/
    volatile uint32 BRR;    /* Bit Reset Register **********/
    volatile uint32 LCKR;   /* Lock Register ***************/
} GPIO_RegDef_t;

/*___________________________________________________________________________________________

**************************   SYSTICK Register Definition Structure *************************
___________________________________________________________________________________________*/

typedef struct {
    volatile uint32 CTRL;      /* SysTick Control and Status Register */
    volatile uint32 LOAD;      /* SysTick Reload Value Register */
    volatile uint32 VAL;       /* SysTick Current Value Register */
    volatile const uint32 CALIB; /* SysTick Calibration Value Register */
} SysTick_RegDef_t;

/*___________________________________________________________________________________________*/
/*___________________________________________________________________________________________*/
/*___________________________________________________________________________________________*/

/*___________________________________________________________________________________________

**************************   GPIO Peripheral Definition ************************************
___________________________________________________________________________________________*/

#define GPIOA                   ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB                   ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC                   ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD                   ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE                   ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF                   ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)

/*___________________________________________________________________________________________

**************************   RCC  Peripheral Definition ************************************
___________________________________________________________________________________________*/

#define RCC                     ((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/*___________________________________________________________________________________________

**************************   SYSTICK  Peripheral Definition ************************************
___________________________________________________________________________________________*/

#define SysTick          ((SysTick_RegDef_t *) SysTick_BASE_ADDRESS)

#endif
