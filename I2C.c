#include "I2C.h"

void I2CInit (void) 
{
	SIM -> SCGC4 |= SIM_SCGC4_I2C0_MASK ;
	SIM -> SCGC5 |= (SIM_SCGC5_PORTB_MASK);
	
	PORTB->PCR[3] |= PORT_PCR_MUX(2); // I2C0 SCL
	PORTB->PCR[4] |= PORT_PCR_MUX(2); // I2C0 SDA
	I2C0->C1 &= ~(I2C_C1_IICEN_MASK);								
	I2C0->F  |= I2C_F_MULT(1);											//mul=2
	I2C0->F |= I2C_F_ICR(0x19);
	//I2C0->C1 |= I2C_C1_IICEN_MASK; 									//Enables I2C module operation.								//Enables I2C interrupt requests
	I2C0->C1 |= I2C_C1_MST_MASK;										//Master Mode Select, 1-master, 0-slave
	I2C0->C1 |= I2C_C1_TX_MASK;											//Enable transfer
	I2C0->C1 |= I2C_C1_TXAK_MASK;										//Enable transfer acknowledge
	I2C0->C1 |= I2C_C1_DMAEN_MASK;									//Enable DMA (just in case)
	return;
}

void I2CWrite(uint8_t address, uint8_t data){
	I2C0->C1 |= I2C_C1_IICEN_MASK;
	I2C_TRAN;						//set to transmit mode 
	I2C_M_START;				//send start
	
	I2C0->D = address << 1;	//send write address 
	I2C_WAIT;						//wait for ack from salve
	
	I2C0->D = data;			//send data//
	I2C_WAIT;
	
	I2C_M_STOP;					//set start mask off
	I2C0->C1 &= ~(I2C_C1_IICEN_MASK);
	return;
}
