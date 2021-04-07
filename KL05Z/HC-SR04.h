#ifndef HC_SR04_h
#define HC_SR04_h
 
#define TRIG 10
#define ECHO 11
 
 #include "mkl05z4.h"
 #include "SonarEngine.h"
 
 void PitInit(void);
 void GPIOInit(void);

 
 uint16_t GetDistance(void);
 
 #endif
