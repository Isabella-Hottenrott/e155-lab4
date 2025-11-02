// STM32L432KC_FLASH.c
//Isabella Hottenrott
// ihottenrott@g.hmc.edu
// 2/10/2025
// Source code for FLASH functions

#include "STM32L432KC_FLASH.h"

void configureFlash() {
    FLASH->ACR |= (0b100); // Set to 4 waitstates
    FLASH->ACR |= (1 << 8); // Turn on the ART
}