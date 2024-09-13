#include <stdio.h>

#define STM32F103 0
#define ATMEGA 1
#define Pic16f887 2

#if MCU == STM32F103

void Blinkled(){
    DRC = !DRC;
    delay(1000);
}
#elif MCU == ATMEGA

void Blinkled(){
    ALU = !ALU;
    delay(1000);
}

#elif MCU == Pic16f887

void Blinkled(){
    AIT = !AIT;
    delay(1000);
}

#endif
