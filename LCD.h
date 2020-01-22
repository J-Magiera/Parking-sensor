#include "mkl05z4.h"
#include "I2C.h"
#include "extra.h"
//#define Rs B00000001  // Register select bit
void LCDInit();
void LCDWrite(uint8_t, uint8_t);
void LCDFirstRow();
void LCDSecondRow();