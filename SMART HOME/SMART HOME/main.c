
#include "UART.h"
#include "SPI.h"
#define F_CPU	8000000UL
#include <util/delay.h>

int main(void)
{
	UART_init();
	SPI_init();
	SPI_masterStartTransmission();
	_delay_ms(1000);
	uint8 data;
	
    while(1)
    {
		data = UART_Rx();
		SPI_Transiver(data);
    }
}