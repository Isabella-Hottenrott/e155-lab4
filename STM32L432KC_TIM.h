// STM32L432KC_TIM.h
// Header for TIM functions

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////
#define TIM2_BASE     (0x40000000UL)
#define __IO volatile

Need CR1, SR, EGR, ARR
egr - how to reset
arr- comparison value
typedef struct {
    __IO uint32_t CR1;        // 0x00
    uint32_t      RESERVED3; // 0x04 
    __IO uint32_t SMCR;        // 0x08
    uint32_t 
    __IO uint32_t SR;         // 0x10 -> doesnt seemlikeill need
    __IO uint32_t EGR;        // 0x14 why do i need this (UG. reinitialize the counter. how to kick off thecount)
    __IO uint32_t CCMR1;      // 0x18 why do I need this
    uint32_t      RESERVED4;  // 0x1C why do I need this
    __IO uint32_t CCER;       // 0x20 why do Ineed this
    __IO uint32_t CNT;        // 0x24
    __IO uint32_t PSC;        // 0x28 
    __IO uint32_t ARR;        // 0x2C
    uint32_t      RESERVED5;  // 0x30 
    __IO uint32_t CCR1;       // 0x34
} TIM2_TypeDef;
#define TIM2 ((TIM2_TypeDef*)TIM2_BASE)

use timers to generate square waves of a given frequency
configure clocks in RCC
Turn on clock to timer in RCC
Select correct clock source in TIM control (disable slave mode)
Configure counter
Prescalerreg
autoreload reg
enable counter CEN

