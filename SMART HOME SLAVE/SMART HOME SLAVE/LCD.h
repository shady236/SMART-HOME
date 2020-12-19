
#ifndef LCD_H_
#define LCD_H_

#define CURSOR_OFF           0x0C
#define CURSOR_LEFT_TO_RIGHT 0x06
#define RETURN_HOME          0x02
#define F_CPU 16000000

#include "LCD_confg.h"
#include "DIO.h"
#include "STD.h"
#include <util/delay.h>


void LCD_init();
void LCD_sendCommand(uint8 cmd);
void LCD_writeChar(uint8 ch);
void LCD_writeStr(uint8* str);
void LCD_clear();
void LCD_goTo(uint8 row, uint8 col);
void LCD_writeInt(sint32 num);


#endif /* LCD_H_ */