#ifndef TPM_h
#define TPM_h

#define BUZZER 11

#include "mkl05z4.h"

void PWMInitialize();
void TPM0_IRQHandler();
int startBuzzer(uint16_t pulse);
int stopBuzzer();
void PWMBuzz();

#endif