
#include "UART.h"

void UART_init()
{
	uint32 buadRate = F_OSC / (16*BUAD_RATE) - 1;
	UBRRL = buadRate;
	UBRRH = buadRate>>8;
	
	
	#if  RX_STATE == RX_ENABLE
		DIO_setPinDirection(UART_PORT, UART_RX_PIN, DIO_PIN_INPUT);
		SET_BIT(UCSRB, 4);
	#elif RX_STATE == RX_DISABLE
		CLR_BIT(UCSRB, 4);
	#endif
	
	#if  TX_STATE == TX_ENABLE
		DIO_setPinDirection(UART_PORT, UART_TX_PIN, DIO_PIN_OUTPUT);
		SET_BIT(UCSRB, 3);
	#elif TX_STATE == TX_DISABLE
		CLR_BIT(UCSRB, 3);
	#endif
	
	
	
	#if  RX_INTERRUPT_STATE == RX_INTERRUPT_ENABLE
		SET_BIT(UCSRB, 7);
	#elif RX_INTERRUPT_STATE == RX_INTERRUPT_DISABLE
		CLR_BIT(UCSRB, 7);
	#endif
	
	#if  TX_INTERRUPT_STATE == TX_INTERRUPT_ENABLE
		SET_BIT(UCSRB, 6);
	#elif TX_INTERRUPT_STATE == TX_INTERRUPT_DISABLE
		CLR_BIT(UCSRB, 6);
	#endif
	
	
	
	uint8 UCSRC_value = 0x80;	// bit7 = 1 to write to UCSRC register
	
	#if UART_MODE == UART_SYNCRONOUS
		SET_BIT(UCSRC_value, 6);
	#endif
	
	
	#if PARITY_MODE == PARITY_EVEN
		SET_BIT(UCSRC_value, 5);
	#elif PARITY_MODE == PARITY_ODD
		SET_BIT(UCSRC_value, 5);
		SET_BIT(UCSRC_value, 4);
	#endif
	
	
	
	#if STOP_BITS_NUM == TWO_STOP_BITS
		SET_BIT(UCSRC_value, 3);
	#endif
	
	
	#if   DATA_BITS_NUM == SIX_DATA_BITS
		SET_BIT(UCSRC_value, 1);
	#elif DATA_BITS_NUM == SEVEN_DATA_BITS
		SET_BIT(UCSRC_value, 2);
	#elif DATA_BITS_NUM == EIGHT_DATA_BITS
		SET_BIT(UCSRC_value, 2);
		SET_BIT(UCSRC_value, 1);
	#elif DATA_BITS_NUM == NINE_DATA_BITS
		SET_BIT(UCSRB, 2);
		SET_BIT(UCSRC_value, 2);
		SET_BIT(UCSRC_value, 1);
	#endif
	
	UCSRC = UCSRC_value;
	
}

uint8 UART_Rx()
{
	while(GET_BIT(UCSRA, 7) == 0);
	return UDR;
}

void UART_Tx(uint8 data)
{
	UDR = data;
	while(GET_BIT(UCSRA, 5) == 0);
}

void UART_TxString(uint8* str)
{
	uint8 i=0;
	while(str[i] != 0) 
	{
		UART_Tx(str[i]);
		i++;
	}
}
