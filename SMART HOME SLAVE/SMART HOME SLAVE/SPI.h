
#ifndef SPI_H_
#define SPI_H_


#include "ATmega32_Registers.h"
#include "BIT_Math.h"
#include "STD.h"
#include "DIO.h"
#include "SPI_config.h"


#define SPI_DISABLE		0
#define SPI_ENABLE		1

#define SPI_MSTR		0
#define SPI_SLAV		1

#define SPI_INTERRUPT_DISABLE	0
#define SPI_INTERRUPT_ENABLE	1

#define SPI_TRANSFER_LSB_FIRST	0
#define SPI_TRANSFER_MSB_FIRST	1

#define SPI_CLK_POLARITY_LOW	0
#define SPI_CLK_POLARITY_HIGH	1

#define SPI_CLK_PHASE_LOW		0
#define SPI_CLK_PHASE_HIGH		1

#define SPI_CLK_PRESCALER_2		0
#define SPI_CLK_PRESCALER_4		1
#define SPI_CLK_PRESCALER_8		2
#define SPI_CLK_PRESCALER_16	3
#define SPI_CLK_PRESCALER_32	4
#define SPI_CLK_PRESCALER_64	5
#define SPI_CLK_PRESCALER_128	6

#define SPI_PORT		DIO_PORTB
#define SPI_SS_PIN		DIO_PIN4
#define SPI_MOSI_PIN	DIO_PIN5
#define SPI_MISO_PIN	DIO_PIN6
#define SPI_CLK_PIN		DIO_PIN7


void  SPI_init();
uint8 SPI_Transiver(uint8 data);
uint8 SPI_RxOnly();
uint8 SPI_RxOnlyIfAvailableNow(uint8 *data);

#if  SPI_DEVISE_MODE == SPI_MSTR
void SPI_masterStartTransmission();
void SPI_masterEndTransmission();
#endif

#endif /* SPI_H_ */