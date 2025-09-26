// STM32L432KC_TIM.h
// Header for TIM functions

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>


#define TIM15_BASE     (0x40014000UL)
#define TIM16_BASE     (0x40014400UL)
#define __IO volatile

Need CR1, SR, EGR, ARR
egr - how to reset
arr- comparison value
typedef struct {
    __IO uint32_t CR1;        // 00
    uint32_t      RESERVED; // 04 
    __IO uint32_t SMCR;        // 08 why do I need
    uint32_t      RESERVEDi;   // 
    __IO uint32_t SR;         // 10
    __IO uint32_t EGR;        // 0x14 How to restart
    __IO uint32_t CCMR1;      // 0x18 capture and compare mode. DONT need?
    uint32_t      RESERVEDii;;  // 0x1C 
    __IO uint32_t CCER;       // 0x20 capture and compare enable. DONT need?
    __IO uint32_t CNT;        // 0x24 dont need?
    __IO uint32_t PSC;        // 0x28  dont need?
    __IO uint32_t ARR;        // 0x2C autoreload
    uint32_t      RESERVEDiii;  // 0x30 
    __IO uint32_t CCR1;       // 0x34 dont need?
} TIMx_TypeDef;

#define TIM15 ((TIM15_TypeDef*)TIM15_BASE)
#define TIM16 ((TIM16_TypeDef*)TIM16_BASE)



// function prototypes
void configTIM(int TIMx);
void delay_millis(int TIMx, uint32_t ms);
void set_hz(int TIMx, uint32_t freq);


#endif

