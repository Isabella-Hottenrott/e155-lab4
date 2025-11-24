// STM32L432KC_TIM.c
//Isabella Hottenrott
// ihottenrott@g.hmc.edu
// 2/10/2025
// Source code for TIM functions

#include "STM32L432KC_TIM16.h"


#define SystemCoreClock 8e7



void config_delay(){
    TIM16->CR1 &= ~0b1; // disable for config
    TIM16->CR1 &= ~(0b1<<7); //No auto reload
    TIM16->DIER &= ~(0b1);  //Turn off update interrupt
    TIM16->CR1 &= ~(0b1<<1); // update events generated

    TIM16->PSC &= ~(0b1111111111111111);
    TIM16->PSC |= 0b11111001111; // set PSC = 1999

    TIM16->ARR &= ~(0b1111111111111111); // clear register
    TIM16->ARR |= 0b0000000000010011; // set ARR = 19
    TIM16->CNT &= ~(0b1111111111111111); // reset count

    TIM16->SR &= ~(0b1); // clear UIF

    TIM16->CR1 |= (0b1);
    TIM16->EGR |= 0b1; // force update
}

