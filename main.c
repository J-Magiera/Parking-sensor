//#include "mk20d5.h"
#include "mkl05z4.h"
//#include "I2C.h"
#include "extra.h"
#include "PWM.h"
#include "HC-SR04.h"
#include "I2C.h"
#include "LCD.h"

#define LCD_CLRSCR          0b00000001  // clear screen & go to [0,0]
#define LCD_GOTO00          0b00000010  // go to [0,0]
#define LCD_ENTRYMODE       0b00000100
#define LCD_SETUP           0b00100000

#define LCDBL               3           // backlight bit
#define LCDEN               2           // enable bit
#define LCDRW               1           // read/write bit
#define LCDRS               0           // register select bit

#define LCD_BL              1<<LCDBL
#define LCD_EN              1<<LCDEN
#define LCD_RW              1<<LCDRW
#define LCD_RS              1<<LCDRS

int main()
{
	//GPIOInit();
	//PitInitialize();
	I2CInit();
	LCDInit();
	//Pwm_Initialize();
	//while (1) {
	//pwmBuzzer(14); 
	//pwmBuzzer(100);
	//delay_mc(1000);
	//pwmBuzzer(1000);
	//stopBuzzer();
	
	while(1) 
	{}

}
