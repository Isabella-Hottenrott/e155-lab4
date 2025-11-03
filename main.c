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
//Isabella Hottenrott
// Fur Elise, E155 Lab 4
// Updated Fall 2024


// Pitch in Hz, duration in ms

const int notes[][2] = {
{392,	125},
{392,	63},
{392,	125},
{392,	63},
{392,	188},
{330,	188},
{349,	125},
{392,	63},
{349,	125},
{330,	63},
{294,	375},

{349,	125},
{349,	63},
{349,	125},
{349,	63},
{349,	188},
{294,	188},
{330,	125},
{349,	63},
{330,	125},
{294,	63},
{262,	375},

{392,	125},
{392,	63},
{392,	125},
{392,	63},
{392,	188},
{330,	188},
{349,	125},
{330,	63},
{349,	125},
{392,	63},
{440,	375},

{523,	125},
{523,	63},
{494,	125},
{440,	63},
{392,	188},
{330,	188},
{349,	125},
{349,	63},
{330,	125},
{294,	63},
{392,	375},

{523,	125},
{523,	63},
{494,	125},
{440,	63},
{392,	188},
{330,	188},
{349,	125},
{349,	63},
{330,	125},
{294,	63},
{262,	250},
{0,	63},

{330,	63},
{294,	188},
{392,	188},
{392,	188},
{0,	63},
{349,	63},
{330,	188},
{392,	188},
{392,	188},
{0,	63},
{330,	63},
{294,	188},
{330,	188},
{349,	188},
{440,	188},
{440,	188},
{392,	188},
{392,	188},
{0,	125},

{330,	63},
{294,	188},
{392,	188},
{392,	188},
{0,	125},
{349,	63},
{330,	188},
{392,	188},
{392,	188},
{0,	125},
{330,	63},
{392,	125},
{392,	63},
{392,	125},
{349,	63},
{330,	125},
{349,	63},
{330,	125},
{294,	63},
{262,	375},
};

int length = sizeof(notes) / sizeof(notes[0]);



int main(void) {



    // Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // Setup the PLL and switch clock source to the PLL
    configureClock();

    // Turn on clock to TIM15 and 16
    // bits 17 and 16 of register
    RCC->APB2ENR |= (1 << 16);
    RCC->APB2ENR |= (1 << 17);

    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);
    

    pinMode(6, GPIO_OUTPUT);
    

    for (int i = 0; i<=length-1; i++) {
        int hz = notes[i][0];
        int ms = notes[i][1];

        set_hz(hz);

        config_delay();
        printf("done %d\n", i);
        
        for(int i = 0; i<2*ms; i++){
        TIM16->SR &= ~0b1;
          while(!((TIM16->SR) & 0b1)){
              if ((TIM15->SR)&0b1) {
                TIM15->SR &= ~(0b1); // clear UIF
                togglePin(6);
              }
          }
        }

        }
      
      
    while (1) {}

}



/*************************** End of file ****************************/
