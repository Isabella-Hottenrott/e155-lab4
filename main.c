/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include "STM32L432KC_RCC.h"
#include "STM32L432KC_GPIO.h"
#include "STM32L432KC_FLASH.h"
#include "STM32L432KC_TIM15.h"
#include "STM32L432KC_TIM16.h"

/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
// lab4_starter.c
// Fur Elise, E155 Lab 4
// Updated Fall 2024

// 40,000,000 / (prescaler + 1)(autoreload + 1) = f

// Pitch in Hz, duration in ms
const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};



int main(void) {

    // Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // Setup the PLL and switch clock source to the PLL
    configureClock();

    // Turn on clock to TIM15 and 16
    // bits 17 and 16 of register
    RCC->APB2ENR |= (1 << 16);
    RCC->APB2ENR |= (1 << 17);

    // Turn on clock to GPIOA
    RCC->AHB2ENR |= (1);
    
    //Set speaker as alt fn on pin 3
    pinMode(3, GPIO_OUTPUT);


    for (int i = 0; ; i++) {
        int hz = notes[i][2];
        int ms = notes[i][1];

        if (ms == 0) {
            break;
        } else {
            set_hz(hz);
        }
        config_delay(ms);
        
        printf("frq = %d \n", hz);
        int hz_arr = TIM15->ARR;
        printf("Hz arr = %d \n", hz_arr);
        

        printf("tim = %d \n", ms);
        int ms_arr = TIM16->ARR;
        printf("ms arr = %d \n", ms_arr);


        while(!(TIM16->SR & 1)){
            int gpio_out = (TIM15->SR)&0b1;
            digitalWrite(2, gpio_out);

            }
        printf("gpio done, next \n");

      //  TIM16->SR &= ~(0x1);

  
    }

    while (1) {
    }

}

    //GPIO debug:
    // int digitalRead(int pin);


/*************************** End of file ****************************/
