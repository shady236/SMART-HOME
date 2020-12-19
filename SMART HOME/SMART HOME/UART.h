

#ifndef UART_H_
#define UART_H_


#include "ATmega32_Registers.h"
#include "BIT_Math.h"
#include "STD.h"
#include "DIO.h"
#include "UART_config.h"



#define RX_DISABLE		0
#define RX_ENABLE		1
#define TX_DISABLE		0
#define TX_ENABLE		1

#define RX_INTERRUPT_DISABLE	0
#define RX_INTERRUPT_ENABLE		1
#define TX_INTERRUPT_DISABLE	0
#define TX_INTERRUPT_ENABLE		1

#define UART_ASYNCRONOUS	0
#define UART_SYNCRONOUS		1

#define PARITY_DISABLE		0
#define PARITY_EVEN			1
#define PARITY_ODD			2

#define ONE_STOP_BIT		1
#define TWO_STOP_BITS		2

#define FIVE_DATA_BITS		5
#define SIX_DATA_BITS		6
#define SEVEN_DATA_BITS		7
#define EIGHT_DATA_BITS		8
#define NINE_DATA_BITS		9

#define UART_PORT		DIO_PORTD
#define UART_RX_PIN		DIO_PIN0
#define UART_TX_PIN		DIO_PIN1


void UART_init();
uint8 UART_Rx();
void UART_Tx(uint8 data);
void UART_TxString(uint8* str);


#endif /* UART_H_ */