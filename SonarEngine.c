#include "SonarEngine.h"

uint8_t Buzz = 0;

void SensorInit(void){	
	I2CInit();
	PWMInitialize();																//Initialize every 
	GPIOInit();																			//peripheral used in the project
	PitInit();
	LCDInit();
}

uint8_t IncBuzz()
{
	Buzz++;
}
void Run(void)
{																					//
	SensorInit();														//Main program loop responsible for:
																					//-Polling communication with LCD and sonar
	while(1) {															//-Computing all variables
	uint8_t a =LCDCountSquares();						//-Managing interrupts
	if(a == 0){															//-Acoustic acknoledgement of distance between car and object
		PWMBuzz();														//
		delay_mc(20);
	}
	if(a >=16){
		Buzz = 0;
	}

	if (Buzz >= a*4)	{
				PWMBuzz();
				Buzz = 0;
	}
}
	
}