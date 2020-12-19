#include "LCD.h"

#if  LCD_MODE == 8

void LCD_init()
{
	DIO_setPinDirection(LCD_CMD_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_CMD_PORT, RW_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_CMD_PORT, E_PIN, DIO_PIN_OUTPUT);
	DIO_setPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	LCD_sendCommand(0x38);
	
	LCD_clear();
	LCD_sendCommand(RETURN_HOME);
	LCD_sendCommand(CURSOR_OFF);
	LCD_sendCommand(CURSOR_LEFT_TO_RIGHT);
}

void LCD_sendCommand(uint8 cmd)
{
	DIO_setPinValue(LCD_CMD_PORT, RS_PIN, DIO_PIN_LOW);
	DIO_setPinValue(LCD_CMD_PORT, RW_PIN, DIO_PIN_LOW);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	DIO_setPortValue(LCD_DATA_PORT, cmd);
	
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	_delay_ms(5);
}

void LCD_writeChar(uint8 ch)
{
	DIO_setPinValue(LCD_CMD_PORT, RS_PIN, DIO_PIN_HIGH);
	DIO_setPinValue(LCD_CMD_PORT, RW_PIN, DIO_PIN_LOW);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	DIO_setPortValue(LCD_DATA_PORT, ch);
	
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	_delay_ms(5);
}

void LCD_writeStr(uint8* str)
{
	for(uint8 i=0; str[i]!=0; i++)
	{
		LCD_writeChar(str[i]);
	}
}

void LCD_clear()
{
	LCD_sendCommand(1);
}

void LCD_goTo(uint8 row, uint8 col)
{
	uint8 arr[2] = {0x80, 0xC0};
	LCD_sendCommand(arr[row]+col);
}

void LCD_writeInt(sint32 num)
{
	if(num == 0)
	{
		LCD_writeChar('0');
		return;
	}
	
	if(num < 0)
	{
		LCD_writeChar('-');
		num *= -1;
	}
	
	uint8 str[15];
	sint32 cpyOfNum = num;
	uint8 len = 0;
	while(cpyOfNum != 0)
	{
		len++;
		cpyOfNum /= 10; 
	}
	
	for(int i=len-1; i>=0; i--)
	{
		str[i] = num%10 + '0';
		num /= 10;
	}
	str[len] = 0;
	
	LCD_writeStr(str);
}





#elif  LCD_MODE == 4

void LCD_init()
{
	DIO_setPinDirection(LCD_CMD_PORT, RS_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_CMD_PORT, RW_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_CMD_PORT, E_PIN, DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(LCD_DATA_PORT, D4_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT, D5_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT, D6_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT, D7_PIN, DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(0x28);
	
	LCD_clear();
	LCD_sendCommand(RETURN_HOME);
	LCD_sendCommand(CURSOR_OFF);
	LCD_sendCommand(CURSOR_LEFT_TO_RIGHT);
}

void LCD_sendCommand(uint8 cmd)
{
	DIO_setPinValue(LCD_CMD_PORT, RS_PIN, DIO_PIN_LOW);
	DIO_setPinValue(LCD_CMD_PORT, RW_PIN, DIO_PIN_LOW);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	
	/* send high 4 bits */
	LCD_WRITING_DATA_PORT = ((cmd & 0xF0) | (LCD_WRITING_DATA_PORT & 0x0F));
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	
	/* send low 4 bits */
	LCD_WRITING_DATA_PORT = ((cmd << 4) | (LCD_WRITING_DATA_PORT & 0x0F));
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_writeChar(uint8 ch)
{	
	DIO_setPinValue(LCD_CMD_PORT, RS_PIN, DIO_PIN_HIGH);
	DIO_setPinValue(LCD_CMD_PORT, RW_PIN, DIO_PIN_LOW);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	
	/* send high 4 bits */
	LCD_WRITING_DATA_PORT = ((ch & 0xF0) | (LCD_WRITING_DATA_PORT & 0x0F));
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	
	/* send low 4 bits */
	LCD_WRITING_DATA_PORT = ((ch << 4) | (LCD_WRITING_DATA_PORT & 0x0F));
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_CMD_PORT, E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_writeStr(uint8* str)
{
	for(uint8 i=0; str[i]!=0; i++)
	{
		LCD_writeChar(str[i]);
	}
}

void LCD_clear()
{
	LCD_sendCommand(1);
}

void LCD_goTo(uint8 row, uint8 col)
{
uint8 arr[2] = {0x80, 0xC0};
LCD_sendCommand(arr[row]+col);
}

void LCD_writeInt(sint32 num)
{
	if(num == 0)
	{
		LCD_writeChar('0');
		return;
	}
	
	if(num < 0)
	{
		LCD_writeChar('-');
		num *= -1;
	}
	
	uint8 str[11];
	sint32 cpyOfNum = num;
	uint8 len = 0;
	while(cpyOfNum != 0)
	{
		len++;
		cpyOfNum /= 10; 
	}
	
	for(int i=len-1; i>=0; i--)
	{
		str[i] = num%10 + '0';
		num /= 10;
	}
	str[len] = 0;
	
	LCD_writeStr(str);
}

#endif