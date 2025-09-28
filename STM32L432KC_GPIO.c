// STM32L432KC_GPIO.c
// Source code for GPIO functions

#include "STM32L432KC_GPIO.h"

void pinMode(int pin, int function) {
    switch(function) {
        case GPIO_INPUT:
            GPIO->MODER &= ~(0b11 << 2*pin);
            break;
        case GPIO_OUTPUT:
            GPIO->MODER |= (0b1 << 2*pin);
            GPIO->MODER &= ~(0b1 << (2*pin+1));
            break;
        case GPIO_ALT:
            GPIO->MODER &= ~(0b1 << 2*pin);
            GPIO->MODER |= (0b1 << (2*pin+1));
            break;
        case GPIO_ANALOG:
            GPIO->MODER |= (0b11 << 2*pin);
            break;
    }
}

int digitalRead(int pin) {
    return ((GPIO->IDR) >> pin) & 1;
}

void digitalWrite(int pin, int val) {
    GPIO->ODR |= (1 << pin);
}

void togglePin(int pin) {
    GPIO->ODR ^= (1 << pin);
}

// setting PAF14, TIM15_CH1, PA2, EVENTOUT

void setAF(int pin){
    GPIO->OTYPER &= ~(0b1 << pin);
    // set to output push-pull ?

   // GPIO->PURPDR &= ~(0b1 << 2*pin);
   // GPIO->PURPDR |= (0b1 << (2*pin+1));
    // set to output pull down

    // set to PA2, PAF14
    GPIO->AFRL |= (0b1 << (4*pin+3));
    GPIO->AFRL |= (0b1 << (4*pin+2));
    GPIO->AFRL |= (0b1 << (4*pin+1));
    GPIO->AFRL &= ~(0b1 << 4*pin);

}
