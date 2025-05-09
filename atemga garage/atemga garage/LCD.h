


#ifndef LCD_H_
#define LCD_H_


#include "STD_TYPE.h"
#define F_CPU 1000000
#include "util\delay.h"
#include "DIO.h"

#define _4_BIT_MODE	1
#define _8_BIT_MODE	2
#define LCD_MODE _4_BIT_MODE

#define LCD_E				PIN_3
#define LCD_RW				PIN_2
#define LCD_RS				PIN_1

#define LCD_D4				PIN_4
#define LCD_D5				PIN_5
#define LCD_D6				PIN_6
#define LCD_D7				PIN_7

#define LCD_PORT			PA
#define LCD_CONTROL_PORT	PB


void LCD_F_Init(void);
void LCD_F_Write_Data(U8_t data);
void LCD_F_Write_Command(U8_t command);
void LCD_F_Write_Char(U8_t character);
void LCD_F_Write_String(S8_t* str);
void LCD_F_Go_To(U8_t row,U8_t cell);
void LCD_F_Write_Number(S32_t num);
void LCD_F_Build_Char(U8_t location, U8_t* ptr);
void LCD_F_Trigger(void);
void LCD_F_Go_To_Clear(U8_t col, U8_t cell);
void LCD_F_Get_Decimal_Point(U16_t number);

#endif /* LCD_H_ */