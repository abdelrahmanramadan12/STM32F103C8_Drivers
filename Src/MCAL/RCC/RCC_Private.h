/*
 * RCC_Private.h
 *
 *  Created on: Dec 22, 2023
 *      Author: Abdelrahman Ramadan
 */

#ifndef RCC_RCC_PRIVATE_H_
#define RCC_RCC_PRIVATE_H_

typedef enum {
    RCC_CR_HSION        = 0,  // Internal High-Speed Clock Enable
    RCC_CR_HSIRDY       = 1,  // Internal High-Speed Clock Ready flag
    RCC_CR_HSEON        = 16, // External High-Speed Clock Enable
    RCC_CR_HSERDY       = 17, // External High-Speed Clock Ready flag
    RCC_CR_HSEBYP       = 18, // External High-Speed Clock Bypass
    RCC_CR_PLLON        = 24, // PLL Enable
    RCC_CR_PLLRDY       = 25, // PLL Ready flag
} RCC_CR_Bits;


typedef enum {
    RCC_CFGR_SW1                   =0  ,
    RCC_CFGR_SW2                       ,


    RCC_CFGR_SWS         = 2,  /* System Clock Switch */


    RCC_CFGR_HPRE       = 4,  /* AHB Prescaler*/


    RCC_CFGR_PPRE1      = 8,  /* APB1 Prescaler */


    RCC_CFGR_PPRE2_DIV1      = 11, /* APB2 Prescaler */


    RCC_CFGR_PLLSRC      = 16, /* PLL Entry Clock Source */

	RCC_CFGR_PLLXTPRE      = 17, /* HSE Divider for PLL Entry*/


    RCC_CFGR_PLLMUL       =  18, /* PLL Multiplier */





} RCC_CFGR_Bits;

#define  RCC_CFGR_SW_MASK              (0b11<<0)
#define  RCC_CFGR_PLLSRC_MASK          (0b1<<16)
#define  RCC_CFGR_PLLXTPRE_MASK        (0b1<<17)
#define  RCC_CFGR_PLLMUL_MASK          (0b111<<18)



#endif /* RCC_RCC_PRIVATE_H_ */
