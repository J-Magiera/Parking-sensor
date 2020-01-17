#include "HC-SR04.h"
#include "MKL05Z4.h"
#include "extra.h"

int measurement = 0;

void GPIOInitilize(void) 
{
	SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;  
	PORTA->PCR[10] |= PORT_PCR_MUX(1);				//using PTA10 as gpio   
  PORTA->PCR[11] |= PORT_PCR_MUX(1);    		//using PTA11 as gpio
	PORTA->PCR[10] |= PORT_PCR_IRQC(0b1001);	//interrupt on rising edge
	
	PTA->PDDR |= (1UL << 10);    //Output pin.  
  PTA->PDDR &= ~(1UL << 11);   //Input pin.  
}


void PITInitilize(void)
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; //clock to PIT
  PIT->MCR = 0x00;   //enable PIT module

	PIT->MCR &= ~PIT_MCR_MDIS_MASK;
	PIT->MCR |= PIT_MCR_FRZ_MASK;	
	
	PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(0x1FFF67); //time of a single measurement   100ms
	PIT->CHANNEL[1].LDVAL = PIT_LDVAL_TSV(0xD1); //time of a trigger pulse						10us
	
	PIT->CHANNEL[0].TCTRL |=PIT_TCTRL_TIE_MASK;	
	PIT->CHANNEL[1].TCTRL |=PIT_TCTRL_TIE_MASK;
	
	NVIC_SetPriority(PIT_IRQn,2);
	NVIC_ClearPendingIRQ(PIT_IRQn);
	NVIC_EnableIRQ(PIT_IRQn);
	

		PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;
		
}

void PIT_IRQHandler()
{
	
	//wyczyszczenie innych przerwan
	NVIC_ClearPendingIRQ(PIT_IRQn);

	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK)
	{
		PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;
		
		PTB->PSOR = (1UL << 10);
		//PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(0x00000000);
		PIT->CHANNEL[0].TCTRL &= ~PIT_TCTRL_TEN_MASK;
		//PIT->CHANNEL[1].LDVAL = PIT_LDVAL_TSV(0x00100000);
		PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TEN_MASK;
		
		
	}
	else if(PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK)
	{
		PIT->CHANNEL[1].TFLG &= PIT_TFLG_TIF_MASK;
		PTB->PCOR = (1UL << 10);
		PIT->CHANNEL[1].TCTRL &= ~PIT_TCTRL_TEN_MASK;
		//PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(0x00300000); //time of a single measurement - time of a trigger pulse
		//PIT->CHANNEL[1].LDVAL = PIT_LDVAL_TSV(0x00000000);
		PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;
	}
}
int PORTA_IRQHandler() 
{
	while(PTA->PDIR&(1<<11))
	{
	for (int i=0; i<41; i++)
		{
		}
		measurement++;
	}
	return measurement;
}
uint8_t distance(measurement) 
{
return measurement/58;
}