#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#define LCD_MODE  4

#define  LCD_CMD_PORT            DIO_PORTB
#define  LCD_DATA_PORT           DIO_PORTA
#define  LCD_WRITING_DATA_PORT   PORTA

#define RS_PIN    DIO_PIN1
#define RW_PIN    DIO_PIN2
#define E_PIN     DIO_PIN3

#if  LCD_MODE == 8
#define D0_PIN    DIO_PIN0
#define D1_PIN    DIO_PIN1
#define D2_PIN    DIO_PIN2
#define D3_PIN    DIO_PIN3
#endif

#define D4_PIN    DIO_PIN4
#define D5_PIN    DIO_PIN5
#define D6_PIN    DIO_PIN6
#define D7_PIN    DIO_PIN7



#endif /* LCD_CONFG_H_ */