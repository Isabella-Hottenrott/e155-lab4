// STM32L432KC_TIM.c
//Isabella Hottenrott
// ihottenrott@g.hmc.edu
// 2/10/2025
// Source code for TIM functions

#include "STM32L432KC_TIM15.h"


#define SystemCoreClock 8e7
#define pscale_val 20 //choose prescaler = 20



void set_hz(int freq){
    int autoreload;
    if (freq == 0){
      autoreload = 0;
    } else {
      autoreload = (int) ((SystemCoreClock/((2*(pscale_val)) * freq))-1);
    }
    TIM15->PSC = (int) pscale_val - 1;
    TIM15->EGR |= 1; // force update
    TIM15->CR1 |= 1;

    TIM15->ARR = autoreload; // set timer max count
    TIM15->EGR |= 1; // force update
    TIM15->SR &= ~(1); // clear UIF
    TIM15->CNT = 0; // reset count
}

