
#include "SPI.h"


void SPI_init()
{
	uint8 SPCR_value = 0;
	
	#if   SPI_STATE == SPI_ENABLE
		SET_BIT(SPCR_value, 6);
	#endif
	
	
	#if   SPI_INTERRUPT_STATE == SPI_INTERRUPT_ENABLE
		SET_BIT(SPCR_value, 7);
	#endif
	
	
	#if  SPI_STATE == SPI_ENABLE && SPI_DEVISE_MODE == SPI_MSTR
		DIO_setPinDirection(SPI_PORT, SPI_SS_PIN, DIO_PIN_OUTPUT);
		DIO_setPinDirection(SPI_PORT, SPI_MOSI_PIN, DIO_PIN_OUTPUT);
		DIO_setPinDirection(SPI_PORT, SPI_MISO_PIN, DIO_PIN_INPUT);
		DIO_setPinDirection(SPI_PORT, SPI_CLK_PIN, DIO_PIN_OUTPUT);
		SET_BIT(SPCR_value, 4);
	
	#elif SPI_STATE == SPI_ENABLE && SPI_DEVISE_MODE == SPI_SLAV
		DIO_setPinDirection(SPI_PORT, SPI_SS_PIN, DIO_PIN_INPUT);
		DIO_setPinDirection(SPI_PORT, SPI_MOSI_PIN, DIO_PIN_INPUT);
		DIO_setPinDirection(SPI_PORT, SPI_MISO_PIN, DIO_PIN_OUTPUT);
		DIO_setPinDirection(SPI_PORT, SPI_CLK_PIN, DIO_PIN_INPUT);
	
	#endif
	
	
	#if   SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_2
		SPI->SPSR = 0xC1;
	#elif SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_4
		SPI->SPSR = 0xC0;
	#elif SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_8
		SET_BIT(SPCR_value, 0);
		SPI->SPSR = 0xC1;
	#elif SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_16
		SET_BIT(SPCR_value, 0);
		SPI->SPSR = 0xC0;
	#elif SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_32
		SET_BIT(SPCR_value, 1);
		SPI->SPSR = 0xC1;
	#elif SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_64
		SET_BIT(SPCR_value, 0);
		SET_BIT(SPCR_value, 1);
		SPI->SPSR = 0xC1;
	#elif SPI_DEVISE_MODE == SPI_MSTR && SPI_CLK_PRESCALER == SPI_CLK_PRESCALER_128
		SET_BIT(SPCR_value, 0);
		SET_BIT(SPCR_value, 1);
		SPI->SPSR = 0xC0;
	#endif
	
	
	#if   SPI_DATA_TRANFER_MODE == SPI_TRANSFER_LSB_FIRST
		SET_BIT(SPCR_value, 5);
	#endif
	
	
	#if   SPI_CLK_POLARITY_MODE == SPI_CLK_POLARITY_HIGH
		SET_BIT(SPCR_value, 3);
	#endif
	
	
	#if   SPI_CLK_PHASE_MODE == SPI_CLK_PHASE_HIGH
		SET_BIT(SPCR_value, 2);
	#endif
	
	SPI->SPCR = SPCR_value;
}

uint8 SPI_Transiver(uint8 data)
{
	SPI->SPDR = data;
	while(GET_BIT(SPI->SPSR, 7) == 0);
	return SPI->SPDR;
}

uint8 SPI_RxOnly()
{
	while(GET_BIT(SPI->SPSR, 7) == 0);
	return SPI->SPDR;
}

uint8 SPI_RxOnlyIfAvailableNow(uint8 *data)
{
	/**
		function task is
		1. if there is new data received by SPI now, read it and return 1 to indicate data is valid
		2. if there is no new data received by SPI now, return 0 to indicate data is invalid
	**/
	
	uint8 flag = 0;
	if(GET_BIT(SPI->SPSR, 7) == 1)
	{
		flag = 1;
		*data = SPI->SPDR;
	}
	return flag;
}



#if  SPI_DEVISE_MODE == SPI_MSTR
void SPI_masterStartTransmission()
{
	DIO_setPinValue(SPI_PORT, SPI_SS_PIN, DIO_PIN_LOW);
}

void SPI_masterEndTransmission()
{
	DIO_setPinValue(SPI_PORT, SPI_SS_PIN, DIO_PIN_HIGH);
}
#endif
