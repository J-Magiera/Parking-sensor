#ifndef I2C_h
#define I2C_h

#include "mkl05z4.h"

#define SCL 3
#define SDA 4

#define I2C_M_START I2C0->C1 |= I2C_C1_MST_MASK
#define I2C_M_STOP I2C0->C1 &= ~I2C_C1_MST_MASK
#define I2C_M_RSTART I2C0->C1 |= I2C_C1_RSTA_MASK
#define I2C_TRAN I2C0->C1 |= I2C_C1_TX_MASK
#define I2C_REC I2C0->C1 &= ~I2C_C1_TX_MASK
#define BUSY_ACK while(I2C0->S & 0x00)
#define TRANS_COMP while(!(I2C0->S & 0x80))
#define I2C_WAIT while((I2C0->S & I2C_S_IICIF_MASK) == 0){} I2C0->S |= I2C_S_IICIF_MASK;
#define NACK I2C0->C1 |= I2C_C1_TXAK_MASK
#define ACK I2C0->C1 &= ~I2C_C1_TXAK_MASK


void I2CInit(void);
void I2CWrite(uint8_t address, uint8_t data);
	
#endif