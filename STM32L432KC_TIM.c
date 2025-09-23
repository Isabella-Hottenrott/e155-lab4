// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM.h"


void config() {
    // Use 80 MHz clock as system 

    // Turning on Auto-reload preload enable
    TIM->CR1 |= (1 << 7);
    
    // Turn to Edge aligned mode selection
    TIM->CR &= ~(0b11 << 6);
    // Set direction to upcounter
    TIM->CR &= ~(1 << 4);

    // Update request source to 1: only over/underflow generates DMA
    TIM->CR1 |= (1 << 2);

    // Enable update
    TIM->CR1 |= (1 << 1);

    // Enable counter
    TIM->CR1 |= 1;

    //Disable slave mode
    TIM->SMCR &= ~(0b1111);

    // Wait till PLL is unlocked (e.g., off)
    while ((TIM->CR1 >> 25 & 1) != 0);

    // Load configuration
    // Set PLL SRC to MSI
    RCC->PLLCFGR |= (1 << 0);
    RCC->PLLCFGR &= ~(1 << 1);

    // Set PLLN
    RCC->PLLCFGR &= ~(0b11111111 << 8); // Clear all bits of PLLN
    RCC->PLLCFGR |= (0b1010000 << 8); // |= 80
    
    // Set PLLM
    RCC->PLLCFGR &= ~(0b111 << 4);  // Clear all bits
    
    // Set PLLR
    RCC->PLLCFGR &= ~(1 << 26);
    RCC->PLLCFGR |= (1 << 25);
    
    // Enable PLLR output
    RCC->PLLCFGR |= (1 << 24);

    // Enable PLL
    RCC->CR |= (1 << 24);
    
    // Wait until PLL is locked
    while ((RCC->CR >> 25 & 1) != 1);
}


#define SystemCoreClock 4e6

void initTIM(TIM_TypdeDef * TIM){
    uint32_t psc_div = (uint32_t) ((SystemCoreClock/1e3)-1);

    TIMx -> PSC = (psc_div -1);
    
    // Generate an update event to update prescalar value
    TIMx -> EGR |= 1;

    TIMx -> CR1 |= 1;
    }


    void delay_millis(TIM_TypeDef * TIMx, uint32_t ms){

    TIMx -> ARR = ms; // set timer max count
    TIMx -> EGR |= 1; // force update
    TIMx -> SR &= ~(0x1); // clear UIF
    TIMx -> CNT =0; // reset count

    while(!(TIMx -> SR &1)); // stuck inwhile loop here. look at bottom loop of status register. 
    // interrupts is how you get out of the while loop
}
