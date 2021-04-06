#ifndef LCD_h
#define LCD_h

#include "mkl05z4.h"
#include "I2C.h"
#include "extra.h"
#include "HC-SR04.h"

void LCDInit();

void LCDWrite(uint8_t, uint8_t);
void LCDWriteTwoSquares(uint8_t x, uint8_t y);
void LCDStatic();

void LCDFirstRow();
void LCDSecondRow();
void LCDGotoXY(uint8_t x, uint8_t y);
void LCDGoto00();
void LCDClearXY(uint8_t x, uint8_t y);
void LCDCoursorRight();
void LCDCoursorLeft();



uint8_t LCDCountSquares();
#endif
