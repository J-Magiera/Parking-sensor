#include "LCD.h"
void LCDInit() 
{
	I2C_write(0x3F, 0b00000000);
	//I2Cinit();
	//for (int i = 0; i<41940000; i++)
	//{}
	I2C_write(0x3F, 0b00000000);	
	I2C_write(0x3F, 0b00110000);
	I2C_write(0x3F, 0b00110100);
	I2C_write(0x3F, 0b00110000);
		
	//for (int i = 0; i<192505; i++)
	//{}	
	I2C_write(0x3F, 0b00110000);
	I2C_write(0x3F, 0b00110100);
	I2C_write(0x3F, 0b00110000);
		
//	for (int i = 0; i<192505; i++)
//	{}		
	I2C_write(0x3F, 0b00110000);
	I2C_write(0x3F, 0b00110100);
	I2C_write(0x3F, 0b00110000);

	//for (int i = 0; i<9017; i++)
	//{}
	I2C_write(0x3F, 0b00100000);
	I2C_write(0x3F, 0b00100100);
	I2C_write(0x3F, 0b00100000);
		
	I2C_write(0x3F, 0b00100000);
	I2C_write(0x3F, 0b00100100);
	I2C_write(0x3F, 0b00100000);

	I2C_write(0x3F, 0b10000000);
	I2C_write(0x3F, 0b10000100);
	I2C_write(0x3F, 0b10000000);
		
	I2C_write(0x3F, 0b00000000);
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
		
	I2C_write(0x3F, 0b11000000);
	I2C_write(0x3F, 0b11000100);
	I2C_write(0x3F, 0b11000000);
	
	I2C_write(0x3F, 0b00000000);
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
	
	I2C_write(0x3F, 0b00010000);
	I2C_write(0x3F, 0b00010100);
	I2C_write(0x3F, 0b00010000);
	
	//for (int i = 0; i<87235; i++)
//	{}
	I2C_write(0x3F, 0b00000000);
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);

	I2C_write(0x3F, 0b11000000);
	I2C_write(0x3F, 0b11000100);
	I2C_write(0x3F, 0b11000000);
		
	I2C_write(0x3F, 0b00000000);
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
	
	I2C_write(0x3F, 0b00000000);
	I2C_write(0x3F, 0b00000100);
	I2C_write(0x3F, 0b00000000);
		
	//for (int i = 0; i<87235; i++)
//	{}	
	I2C_write(0x3F, 0b00001000);			//koniec inicjalizacji
	
	I2C_write(0x3F, 0b10001000);
	I2C_write(0x3F, 0b10001100);
	I2C_write(0x3F, 0b10000000);
	
	I2C_write(0x3F, 0b00001000);
	I2C_write(0x3F, 0b00001100);
	I2C_write(0x3F, 0b00001000);			//set cursor 0.0
		
	I2C_write(0x3F, 0b01001001);
	I2C_write(0x3F, 0b01001101);
	I2C_write(0x3F, 0b01001001);
	
	I2C_write(0x3F, 0b10001001);
	I2C_write(0x3F, 0b10001101);
	I2C_write(0x3F, 0b10001001);		//H
	
}