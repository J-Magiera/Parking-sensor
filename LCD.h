#include "mkl05z4.h"
#include "I2C.h"
#include "extra.h"
#include "HC-SR04.h"

void LCDInit();
void LCDWrite(uint8_t, uint8_t);
void LCDFirstRow();
void LCDSecondRow();
void LCDGotoXY(uint8_t x, uint8_t y);
void LCDGoto00();
void LCDCoursorRight();
void LCDCoursorLeft();
void LCDClearXY(uint8_t x, uint8_t y);
void LCDWriteSquare(uint8_t x, uint8_t y);