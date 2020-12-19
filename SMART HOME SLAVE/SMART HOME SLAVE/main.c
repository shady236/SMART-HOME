
#include "SPI.h"
#include "LED1.h"
#include "LED2.h"
#include "LCD.h"

#define LED1_ON_CMD				'1'
#define LED1_OFF_CMD			'2'

#define LED2_ON_CMD				'3'
#define LED2_OFF_CMD			'4'

#define ALL_LEDS_ON_CMD			'5'
#define ALL_LEDS_OFF_CMD		'6'

int main(void)
{
	SPI_init();
	LED1_Init();
	LED2_Init();
	LCD_init();
	
	uint8 cmd = 0;
	
    while(1)
    {
		cmd = SPI_Transiver(0);
		LCD_writeChar(cmd);
		switch(cmd)
		{
			case LED1_ON_CMD:
			LED1_ON();
			break;
			
			case LED1_OFF_CMD:
			LED1_OFF();
			break;
			
			case LED2_ON_CMD:
			LED2_ON();
			break;
			
			case LED2_OFF_CMD:
			LED2_OFF();
			break;
			
			case ALL_LEDS_ON_CMD:
			LED1_ON();
			LED2_ON();
			break;
			
			case ALL_LEDS_OFF_CMD:
			LED1_OFF();
			LED2_OFF();
			break;
			
			default:
			break;
		}
		cmd = 0;
    }
}