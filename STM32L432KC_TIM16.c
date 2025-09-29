// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM16.h"


#define SystemCoreClock 8e7
#define pscale_val 2



void config_delay(int ms){
    int psc_div = (int) ((SystemCoreClock/1e3)-1);
    TIM16->PSC = (psc_div -1);
    TIM16->EGR |= 1; // force update
    TIM16->CR1 |= (1);

    TIM16->ARR = ms; // set timer max count
    TIM16->EGR |= 1; // force update
    TIM16->SR &= ~(0x1); // clear UIF
    TIM16->CNT = 0; // reset count
}

