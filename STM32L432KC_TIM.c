// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM.h"

use timers to generate square waves of a given frequency
configure clocks in RCC x
Turn on clock to timer in RCC x
Select correct clock source in TIM control (disable slave mode) 
Configure counter
Prescaler reg
autoreload reg
enable counter CEN



#define SystemCoreClock 8e7

void configTIM(TIM_TypdeDef * TIM){
    TIMx->EGR |= 1;
    TIMx->CR1 |= (1 << 7); // Turn on auto-reload preload enable
    TIMx->CR1 |= (1 << 2); // Update request source to 1: only over/underflow generates DMA
    TIMx->CR1 |= (1 << 1);  // Enable update
    TIMx->CR1 |= 1; //Enable counter
}

void delay_millis(TIM_TypeDef * TIMx, uint32_t ms){
uint32_t psc_div = (uint32_t) ((SystemCoreClock/1e3)-1);
TIMx->PSC = (psc_div -1);
TIMx->ARR = ms; // set timer max count
TIMx->EGR |= 1; // force update
TIMx->SR &= ~(0x1); // clear UIF
TIMx->CNT = 0; // reset count

while(!(TIMx->SR & 1)); // stuck in while loop here. look at bottom loop of status register. 
}

// 40,000,000 / (prescaler + 1)(autoreload + 1) = f

void set_hz(TIM_TypeDef * TIMx, uint32_t freq){
    uint32_t autoreload = (uint32_t) ((SystemCoreClock/(2 * freq * 3))-1);
    TIMx->PSC = (uint32_t) 2;
    TIMx->ARR = autoreload; // set timer max count
    TIMx->EGR |= 1; // force update
    TIMx->SR &= ~(0x1); // clear UIF
    TIMx->CNT = 0; // reset count
}

