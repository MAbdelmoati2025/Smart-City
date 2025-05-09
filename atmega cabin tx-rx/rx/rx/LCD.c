#include "LCD.h"



#if LCD_MODE==_4_BIT_MODE


void LCD_F_Init(void)
{
	DIO_F_Set_Pin_Dir(LCD_CONTROL_PORT, LCD_E, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_CONTROL_PORT, LCD_RW, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_CONTROL_PORT, LCD_RS, OUTPUT);
	
	DIO_F_Set_Pin_Dir(LCD_PORT, LCD_D4, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_PORT, LCD_D5, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_PORT, LCD_D6, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_PORT, LCD_D7, OUTPUT);
	
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_RW, LOW); // always write on lcd
	
	_delay_ms(50); // powering on sequence page 13
	LCD_F_Write_Command(0x02);
	LCD_F_Write_Command(0x28); //4-bit mode|2 lines|5*7;
	LCD_F_Write_Command(0x0C); //Display on|cursor off|Blinking on
	LCD_F_Write_Command(0x01);
	_delay_ms(1);
	LCD_F_Write_Command(0x06); //Increase address | no shift the entire display
	
}

void LCD_F_Write_Data(U8_t data)
{
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_RS, HIGH); // data
	
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D7, GET_BIT(data, 7));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D6, GET_BIT(data, 6));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D5, GET_BIT(data, 5));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D4, GET_BIT(data, 4));

	DIO_F_Set_Port_Val(LCD_PORT, data & 0xF0);
	LCD_F_Trigger();
	
 	DIO_F_Set_Port_Val(LCD_PORT, data<<4);
	LCD_F_Trigger();
	
	
 
	
// 	
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D7, GET_BIT(data, 3));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D6, GET_BIT(data, 2));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D5, GET_BIT(data, 1));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D4, GET_BIT(data, 0));
//  	LCD_F_Trigger();
}

void LCD_F_Write_Command(U8_t command)
{
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_RS, LOW); // command

//	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D7, GET_BIT(command, 7));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D6, GET_BIT(command, 6));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D5, GET_BIT(command, 5));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D4, GET_BIT(command, 4));
	DIO_F_Set_Port_Val(LCD_PORT, command & 0xF0);
 	LCD_F_Trigger();
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D7, GET_BIT(command, 3));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D6, GET_BIT(command, 2));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D5, GET_BIT(command, 1));
// 	DIO_F_Set_Pin_Val(LCD_PORT, LCD_D4, GET_BIT(command, 0));
	DIO_F_Set_Port_Val(LCD_PORT, command<<4);
	LCD_F_Trigger();
}

#elif LCD_MODE == _8_BIT_MODE


void LCD_F_Init(void)
{
	DIO_F_Set_Port_Dir(LCD_PORT, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_CONTROL_PORT, LCD_E, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_CONTROL_PORT, LCD_RW, OUTPUT);
	DIO_F_Set_Pin_Dir(LCD_CONTROL_PORT, LCD_RS, OUTPUT);
	
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_RW, LOW); // always write on lcd
	
	
	_delay_ms(50); // powering on sequence page 13
	/*Function set 0b00 0011 NFXX*/ //N:
	LCD_F_Write_Command(0x38); //8-bit mode|2 lines|5*7;
	LCD_F_Write_Command(0x0F); //Display on|cursor on|Blinking ON
	LCD_F_Write_Command(0x01);
	_delay_ms(1);
	LCD_F_Write_Command(0x06); //Increase ddram addrea|no shift the entire display
	
}

void LCD_F_Write_Data(U8_t data)
{
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_RS, HIGH); // data
	DIO_F_Set_Port_Val(LCD_PORT, data);
	LCD_F_Trigger();
}

void LCD_F_Write_Command(U8_t command)
{
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_RS, LOW); // command
	DIO_F_Set_Port_Val(LCD_PORT, command);
	LCD_F_Trigger();
}
#endif

void LCD_F_Write_Char(U8_t character)
{
	LCD_F_Write_Data(character);
}

void LCD_F_Write_String(S8_t* str)
{
	while(*str != '\0')
	{
		LCD_F_Write_Char(*str);
		str++;
	}
}



void LCD_F_Go_To(U8_t row,U8_t cell)
{
	if(row == 0)
	{
		LCD_F_Write_Command(0x80 + cell); //0x08 for setting DDRAM address
	}
	else if(row == 1)
	{
		LCD_F_Write_Command(0x80 + 0x40 + cell);
	}
}

void LCD_F_Write_Number(S32_t num)
{
	U8_t rem = 0;
	S8_t arr[10];
	S8_t i = 0;
	if(num == 0)
	{
		LCD_F_Write_Char('0');
		return;
	}
	else if(num < 0)
	{
		num*= -1;
		LCD_F_Write_Char('-');
	}
	
	while (num > 0)
	{
		rem = num % 10;
		rem = rem + '0';
		arr[i] = (char)rem;
		num = num / 10;
		i++;
	}
	
	for(S8_t j=i-1; j>=0; j--) /*j>=0, j must be a signed number*/
	{
		LCD_F_Write_Char(arr[j]);
	}
}

void LCD_F_Build_Char(U8_t location, U8_t* ptr)
{
	LCD_F_Write_Command(0x40 + (location * 8));
	for(U8_t i = 0; i < 8; i++)
	{
		LCD_F_Write_Char(ptr[i]);
	}
}

void LCD_F_Trigger(void)
{
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_E, HIGH);
	_delay_ms(1);
	DIO_F_Set_Pin_Val(LCD_CONTROL_PORT, LCD_E, LOW);
	_delay_ms(1);
}

void LCD_F_Go_To_Clear(U8_t col, U8_t cell)
{
	LCD_F_Go_To(col, cell);
	LCD_F_Write_Char(' ');
}

void LCD_F_Get_Decimal_Point(U16_t number)
{
	number%= 10;
	LCD_F_Write_Char('.');
	LCD_F_Write_Number(number);
}