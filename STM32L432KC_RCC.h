// STM32L432KC_RCC.h
// Header for RCC functions

#ifndef STM32L4_RCC_H
#define STM32L4_RCC_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define RCC_BASE (0x40021000UL) // base address of RCC
#define GPIOA_BASE    (0x48000000UL)

// PLL
#define PLLSRC_HSI 0
#define PLLSRC_HSE 1

// Clock configuration
#define SW_HSI  0
#define SW_HSE  1
#define SW_PLL  2
// DO i need this?

/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR;          /*!< RCC clock control register,                                              Address offset: 0x00 */
  __IO uint32_t ICSCR;       /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
  __IO uint32_t CFGR;        /*!< RCC clock configuration register,                                        Address offset: 0x08 */
  __IO uint32_t PLLCFGR;     /*!< RCC system PLL configuration register,                                   Address offset: 0x0C */
  uint32_t RESERVED0[15];                      
  __IO uint32_t AHB2ENR;     /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
 uint32_t RESERVED1[2];                                                 
  __IO uint32_t APB1ENR1;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */                                      
  __IO uint32_t APB2ENR1
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *) RCC_BASE)


typedef struct {
    __IO uint32_t MODER;      // 0x00
    __IO uint32_t OTYPER;     // 0x04
    __IO uint32_t OSPEEDR;    // 0x08
    __IO uint32_t PUPDR;      // 0x0C
    uint32_t      RESERVED2[4]; // 0x10..0x1C
    __IO uint32_t AFRL;       // 0x20
} GPIO_TypeDef;
#define GPIOA ((GPIO_TypeDef*)GPIOA_BASE)


///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void configurePLL(void);
void configureClock(void);

#endif

// 
// looking at clock tree, want to enable AHB clock and the APB2ENR1. those are two