//#include "MK20D5.h"
#include "mkl05z4.h"
#include "extra.h"
uint16_t stop = 0;
void PWMInitialize(){

	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;		// Clock on PORTB 
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;		// Clock on TMP0 module 
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1); 		// TPM Clock source, MCGFLLCLK = 48MHz
	
	PORTB->PCR[11] |= PORT_PCR_MUX(2); 		// PTB, pin 11 as buzzer output
	TPM0->SC &= ~TPM_SC_CPWMS_MASK;				// Up counting mode
	TPM0->SC &= ~TPM_SC_CMOD_MASK;				// LPTPM counter is disabled
	TPM0->SC |= TPM_SC_PS(5); 						// Clock divider, 5 = clk/32
	
	TPM0->MOD = 1600; 										
	
	TPM0->CONTROLS[0].CnSC |= (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK); // Center-aligned PWM High-pulse CH0
	TPM0->SC |= TPM_SC_TOIE_MASK;					//enable interrupts
	NVIC_ClearPendingIRQ(TPM0_IRQn);	
	NVIC_SetPriority (TPM0_IRQn, 4);
	
	TPM0->SC |= TPM_SC_CMOD(1);						// start counter
	
	
}

void TPM0_IRQHandler(){
		
	TPM0->SC |= TPM_SC_TOF_MASK;				// clear status flag
}

int startBuzzer(uint16_t pulse){

	while( !(TPM0->STATUS & TPM_STATUS_TOF_MASK )) {}
	
	TPM0->SC &= ~TPM_SC_CMOD(0); 											// 0 = LPTPM counter is disabled
	TPM0->CONTROLS[0].CnV = TPM_CnV_VAL(pulse); 	// Pulse width CH0 PB11
	TPM0->SC |= TPM_SC_CMOD(1); 											// 1 = LPTPM counter increments on every LPTPM counter clock
	
	return 0;
}

void stopBuzzer(void) 
	{
	TPM0->SC &= ~TPM_SC_CMOD(0); 											
	TPM0->CONTROLS[0].CnV = TPM_CnV_VAL(stop); 				
	TPM0->SC |= TPM_SC_CMOD(1); 											
	
	}