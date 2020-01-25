#include "HC-SR04.h"
#include "LCD.h"
#include "PWM.h"


uint16_t distance = 0;
uint8_t flag = 0;
void GPIOInit(void) 
{
	SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;  
	PORTA->PCR[TRIG] |= PORT_PCR_MUX(1);						//using PTA10 as gpio   
  PORTA->PCR[ECHO] |= PORT_PCR_MUX(1);    				//using PTA11 as gpio
	PORTA->PCR[ECHO] |= PORT_PCR_IRQC(0b1001);			//interrupt on rising edge
	PTA->PDDR |= (1UL << TRIG);    									//Output pin.  
  PTA->PDDR &= ~(1UL << ECHO);   									//Input pin.
	
	NVIC_ClearPendingIRQ(PORTA_IRQn);								//Clear NVIC any pending interrupts on PORTA
	NVIC_SetPriority (PORTA_IRQn, 1);								//Set PORTA interrupts priority
	NVIC_EnableIRQ(PORTA_IRQn);											// Enable NVIC interrupts source for PORTA module
}


void PitInit(void)
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; 							//clock to PIT
  PIT->MCR = 0x00;   															//enable PIT module

	PIT->MCR &= ~PIT_MCR_MDIS_MASK;									//module disable							
	
	PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(0x0FFFB3);	//time of a single measurement   100ms
	PIT->CHANNEL[1].LDVAL = PIT_LDVAL_TSV(0x99); 			//time of a trigger pulse				 10us
	
	PIT->CHANNEL[0].TCTRL |=PIT_TCTRL_TIE_MASK;			//interupt enable for channel 0		
	PIT->CHANNEL[1].TCTRL |=PIT_TCTRL_TIE_MASK;			//interupt enable for channel 1
	
	NVIC_SetPriority(PIT_IRQn,2);										//set PIT interrupts priority
	NVIC_ClearPendingIRQ(PIT_IRQn);									//clear NVIC any pending interrupts in PIT
	NVIC_EnableIRQ(PIT_IRQn);												//enable NVIC interrupts source for PIT module
	

	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;		//enable timer on channel 0
		
}


void PIT_IRQHandler()
{
	
	NVIC_ClearPendingIRQ(PIT_IRQn);									//clear other interrupts

	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK)		
	{
		if (flag ==1) {
		PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;
		PTA->PSOR = (1UL << TRIG);
			
		flag = 0;																			//flag for doubling PIT utility
		IncBuzz();																		//buzzer period increment;
			
		PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TEN_MASK;	//enable timer on channel 1
		PIT->CHANNEL[0].TCTRL &= ~PIT_TCTRL_TEN_MASK;	//disable timer on channel 0
			
		}
		else {
		PIT->CHANNEL[0].TFLG &= PIT_TFLG_TIF_MASK;		//clear flag status
		
		flag++;				
		IncBuzz();
		}
		
		
	}
	else if(PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK)
	{
		PIT->CHANNEL[1].TFLG &= PIT_TFLG_TIF_MASK;		//clear flag status
		
		PTA->PCOR = (1UL << TRIG);
		
		PIT->CHANNEL[1].TCTRL &= ~PIT_TCTRL_TEN_MASK;	//disable timer on channel 1
		PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;	//enable timer on channel 0
	}

}
void PORTA_IRQHandler() 
{
	distance = 0;
	while(PTA->PDIR&(1<<ECHO))		//if there is a signal on ECHO pin
	{
	for (int i=0; i<2; i++)	{	}  				//delay loop
		distance++;												//Incrementing variable holding length of echo signal
	}
	PORTA->PCR[11] |= PORT_PCR_ISF_MASK;		//clear flag status

}
uint16_t GetDistance() 
{
return distance/58; 		//Distance is scaled
}