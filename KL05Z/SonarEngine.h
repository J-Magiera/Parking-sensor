#ifndef I2C_h
#define I2C_h

#include "mkl05z4.h"
#include "LCD.h"
#include "PWM.h"
#include "I2C.h"



void SensorInit(void);
void Run(void);
uint8_t IncBuzz(void);

#endif
