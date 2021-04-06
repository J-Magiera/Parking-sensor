#include "LCD.h"
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control

#define LCD_NOBACKLIGHT 0x00
#define Bl 0b00001000
#define En 0b00000100  // Enable bit
#define Rw 0b00000010  // Read/Write bit
#define Rs 0b00000001  // Register select bit

#define LCD 0x3F 			 // Constant address of a slave screen device

/*
Writing single byte of data to LCD screen. 
*/
void LCDWrite(uint8_t data, uint8_t type){	
	uint8_t data2=data;
	data2 &= 0xF0;
	I2CWrite(LCD, (data2) | Bl | (type ? Rs : 0) |  En);
	I2CWrite(LCD, (data2)| Bl | (type ? Rs : 0));
	I2CWrite(LCD, (data << 4) | Bl | (type ? Rs : 0) |  En);
	I2CWrite(LCD, (data << 4)| Bl | (type ? Rs : 0));

}
/*
Functions to select which row to write into
*/
void LCDFirstRow() {
	LCDWrite(0b10000000,0);
	delay_mc(1);
}
void LCDSecondRow(){
	LCDWrite(0b11000000,0);
	delay_mc(1);
}
// 		2 8-bit packages consist of:
// 0b	0		0		0		0		0		0		0		0				0b	0		0		0		0		0		0		0		0
//		DB7	DB6	DB5	DB4	BL	E		R/W	RS					DB3	DB2	DB1	DB0	BL	E		R/W	RS

void LCDInit() {											//initialization made according to HD44780U datasheet		
																			//4-bit interface, 2x16, 5x8 DOTS
	I2CWrite(0x3F, 0b00000000);					//
																			//All sequences below are necessary to initialize 2x16 LCD screen
	for (int i = 0; i<419400; i++)			//via I2C communication.
	{}																	//Derived from datasheet
	I2CWrite(0x3F, 0b00000000);					//
																			//DB7-0 - Data bits
	I2CWrite(0x3F, 0b00110100);					//BL - Blacklight bit. 1 means blacklight is set on.
	I2CWrite(0x3F, 0b00110000);					//Rs  - Register select bit.
																			//R/W - Read/Write bit, 0 equals write.
	for (int i = 0; i<19250; i++)				//E - enable bit, switched from 1 to 0 in each transmission.
	{}	
	;
	I2CWrite(0x3F, 0b00110100);
	I2CWrite(0x3F, 0b00110000);
		
	for (int i = 0; i<19250; i++)
	{}		
	
	I2CWrite(0x3F, 0b00110100);
	I2CWrite(0x3F, 0b00110000);

	for (int i = 0; i<9017; i++)
	{}
	
	I2CWrite(0x3F, 0b00100100);
	I2CWrite(0x3F, 0b00100000);
		

	I2CWrite(0x3F, 0b00100100);
	I2CWrite(0x3F, 0b00100000);

	
	I2CWrite(0x3F, 0b10000100);
	I2CWrite(0x3F, 0b10000000);
		
	
	I2CWrite(0x3F, 0b00000100);
	I2CWrite(0x3F, 0b00000000);
		
	
	I2CWrite(0x3F, 0b11000100);
	I2CWrite(0x3F, 0b11000000);
	
	
	I2CWrite(0x3F, 0b00000100);
	I2CWrite(0x3F, 0b00000000);
	
	
	I2CWrite(0x3F, 0b00010100);
	I2CWrite(0x3F, 0b00010000);
	
	for (int i = 0; i<8723; i++)
	{}
	
	I2CWrite(0x3F, 0b00000100);
	I2CWrite(0x3F, 0b00000000);

	
	I2CWrite(0x3F, 0b11000100);
	I2CWrite(0x3F, 0b11000000);
		
	
	I2CWrite(0x3F, 0b00000100);
	I2CWrite(0x3F, 0b00000000);
	
	
	I2CWrite(0x3F, 0b00000100);
	I2CWrite(0x3F, 0b00000000);
		
	for (int i = 0; i<8723; i++)		//Delaying
	{}	
	I2CWrite(0x3F, 0b00001000);			//koniec inicjalizacji
	LCDStatic();
	LCDFirstRow();
	
	
	LCDWrite(0b00000000,0);
	
}

/*
Moves coursor into field with x and y coordinates.
*/
void LCDGotoXY(uint8_t x, uint8_t y)
{
	LCDGoto00();
	
	if(y ==1){LCDSecondRow();}
	for(int i = 0; i < x; i++)
	{
	LCDCoursorRight();
	//delay_mc(1);
	}
}

/*
Returns coursor to left top corner of LCD.
*/
void LCDGoto00()
{
	LCDWrite(0b000000010, 0);
	delay_mc(1);
}

void LCDCoursorRight()
{	
	LCDWrite(0b00010100, 0);
	delay_mc(1);
}

void LCDCoursorLeft()
{	
	LCDWrite(0b00010000, 0);
	delay_mc(1);
}

/*
Clears chosen field of LCD
*/
void LCDClearXY(uint8_t x, uint8_t y)
{
	LCDGotoXY(x, y);
	LCDWrite(0b00100000, Rs);
	delay_mc(1);
}

/*
Writes two square bars on LCD into x, y coordinates
*/
void LCDWriteTwoSquares(uint8_t x, uint8_t y)
{
	LCDGotoXY(x, y);
	LCDWrite(0b11111111, Rs);
	LCDWrite(0b11111111, Rs);
}


/*
CountSquares funcition calculates number of square bars to be shown on screen
Bars increase with distance and are quanitized in packs of two, meaning 8 possible
distances to be distinguished by the screen and buzzer.
*/
uint8_t LCDCountSquares()
{
	delay_mc(20);
	uint16_t dist = GetDistance();
	uint8_t bars = 0;
	if (dist >= 10) {
		LCDWriteTwoSquares(0, 1);
		bars++;
	}
	if (dist >= 50) {
		LCDWriteTwoSquares(2, 1);
		bars++;
	}
	if (dist >= 75) {
		LCDWriteTwoSquares(4, 1);
		bars++;
	}
	if (dist >= 100) {
		LCDWriteTwoSquares(6, 1);
		bars++;
	}
	if (dist >= 125) {
		LCDWriteTwoSquares(8, 1);
		bars++;
	}
	if (dist >= 150) {
		LCDWriteTwoSquares(10, 1);
		bars++;
	}
	if (dist >= 175) {
		LCDWriteTwoSquares(12, 1);
		bars++;
	}
	if (dist >= 200) {
		LCDWriteTwoSquares(14, 1);
		bars++;
	}
	bars *= 2;
	for(int i = bars; i <= 16; i++)
	{
		LCDClearXY(i, 1);
		delay_mc(2);
	}
return bars;
}

/*
Function to display static text
*/
void LCDStatic(){
	LCDWrite(0b01000100, Rs);				//d
	LCDWrite(0b01011001, Rs);				//y
	LCDWrite(0b01010011, Rs);				//s
	LCDWrite(0b01010100, Rs);				//t	
	LCDWrite(0b01000001, Rs);				//a
	LCDWrite(0b01001110, Rs);				//n
	LCDWrite(0b01010011, Rs);				//s
	LCDWrite(0b00111010, Rs);				//:
}
