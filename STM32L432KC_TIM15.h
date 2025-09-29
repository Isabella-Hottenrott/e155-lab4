// STM32L432KC_TIM.h
// Header for TIM functions

#ifndef STM32L432KC_TIM15_H
#define STM32L432KC_TIM15_H


#include <stdint.h>


#define TIM15_BASE     (0x40014000UL)
#define __IO volatile


typedef struct {
    __IO uint32_t CR1;        // 00
    __IO uint32_t CR2;        // 04 
    __IO uint32_t SMCR;        // 08 why do I need
    __IO uint32_t DIER;   // 
    __IO uint32_t SR;         // 10
    __IO uint32_t EGR;        // 0x14 How to restart
    __IO uint32_t CCMR1;      // 0x18 capture and compare mode, 0x1C
    uint32_t      RESERVED9;  // 0x1C for input 
    __IO uint32_t CCER;       // 0x20 capture and compare enable. DONT need?
    __IO uint32_t CNT;        // 0x24 dont need?
    __IO uint32_t PSC;        // 0x28  dont need?
    __IO uint32_t ARR;        // 0x2C autoreload
    __IO uint32_t RCR;  // 0x30 
    __IO uint32_t CCR1;       // 0x34 dont need?
} TIM15_TypeDef;

#define TIM15 ((TIM15_TypeDef*)TIM15_BASE)




// function prototypes
void set_hz(int freq);


#endif

