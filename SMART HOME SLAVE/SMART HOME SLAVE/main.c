
#include "SPI.h"
#include "LED1.h"
#include "LED2.h"
#include "LCD.h"
#include "Timer0.h"

#define LED1_ON_CMD				'1'
#define LED1_OFF_CMD			'2'

#define LED2_ON_CMD				'3'
#define LED2_OFF_CMD			'4'

#define ALL_LEDS_ON_CMD			'5'
#define ALL_LEDS_OFF_CMD		'6'



/**
	instructions is array of 6 strings holds the instructions to be displayed for user on 6 lines on LCD
**/

char instructions[6][13] = {	"1-->LED1 ON ", 
								"2-->LED1 OFF",
								"3-->LED2 ON ",
								"4-->LED2 OFF",
								"5-->LEDs ON ",
								"6-->LEDs OFF"		};


void writeNextLineOfInstructionsAtLCD();

int main(void)
{
	SPI_init();
	LED1_Init();
	LED2_Init();
	LCD_init();
	Timer0_init();
	Timer0_delay_ms(1000, writeNextLineOfInstructionsAtLCD);
	Timer0_start();
	
	uint8 cmd = 0;		//command received by SPI
	uint8 flag = 0;		//indicate that is the command received by SPI is valid or not
	
    while(1)
    {
		flag = SPI_RxOnlyIfAvailableNow(&cmd);
		
		if(flag == 1)
		{
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
			}// end of switch(cmd)
			cmd = 0;
		}// end of if(flag == 1)
    }//end of while(1)
}//end of main()

void writeNextLineOfInstructionsAtLCD(void)
{
	static uint8 currentLine = 0;
	//LCD_clear();
	LCD_goTo(0, 0);
	LCD_writeStr(instructions[currentLine]);
	LCD_goTo(1, 0);
	LCD_writeStr(instructions[(currentLine+1)%6]);
	
	//update current line for the next writing time
	if(currentLine==5)
	{
		currentLine=0;
	}
	else
	{
		currentLine++;
	}
}