// STM32L432KC_TIM.h
//Isabella Hottenrott
// ihottenrott@g.hmc.edu
// 2/10/2025
// Header for TIM functions

#ifndef STM32L432KC_TIM16_H
#define STM32L432KC_TIM16_H


#include <stdint.h>


#define TIM16_BASE     (0x40014400UL)
#define __IO volatile

typedef struct {
    __IO uint32_t CR1;        // 00
    __IO uint32_t CR2;        // 04
   uint32_t      RESERVED0;    //08
    __IO uint32_t DIER;       // 0C
    __IO uint32_t SR;         // 10
    __IO uint32_t EGR;        // 14
    __IO uint32_t CCMR1;      // 18 
    uint32_t      RESERVED1;  // 1C for input ccmr1
    __IO uint32_t CCER;       // 20
    __IO uint32_t CNT;        // 24
    __IO uint32_t PSC;        // 28
    __IO uint32_t ARR;        // 2C
    __IO uint32_t RCR;        // 0x30
    __IO uint32_t CCR1;       // 0x34
   uint32_t      RESERVED2;   // 0x38
   uint32_t      RESERVED3;   // 0x3C
   uint32_t      RESERVED4;   // 0x40
    __IO uint32_t BDTR;       // 0x44
    __IO uint32_t DCR;        // 0x48
    __IO uint32_t DMAR;       // 0x4C
    __IO uint32_t OR1;        // 0x50
    __IO uint32_t OR2;        // 0x60
} TIM16_TypeDef;

#define TIM16 ((TIM16_TypeDef *) TIM16_BASE)



// function prototypes
void config_delay();


#endif

