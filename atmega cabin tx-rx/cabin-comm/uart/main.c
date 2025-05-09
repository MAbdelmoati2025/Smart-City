

#define F_CPU 16000000			/* Define frequency here its 8MHz */
#include "DIO.h"
// #include <avr/io.h>
 #include <util/delay.h>
//  #include <stdlib.h>
//  #include <stdio.h>
#include "LCD.h"
#include "BIT_MATH.h"
#include <util/delay.h>

//#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init(long USART_BAUDRATE)
{
	UCSRB |= (1 << 4) | (1 << 3);/* Turn on transmission and reception */
	UCSRC |= (1 << 7) | (1 << 1) | (1 << 2);/* Use 8-bit character sizes */
	UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
}

unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << 7)) == 0);/* Wait till data is received */
	return(UDR);			/* Return the byte*/
}

void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<5)));	/* Wait for empty transmit buffer*/
	UDR = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);	
		j++;
	}
}

int main()
{
	char c='z';
	UART_init(9600);
	DIO_F_Set_Pin_Dir(PB,PIN_4,OUTPUT);
	DIO_F_Set_Pin_Dir(PD,PIN_5,INPUT);
	
	DIO_F_Set_Pin_Dir(PC,PIN_4,INPUT);
	DIO_F_Set_Pin_Dir(PC,PIN_5,INPUT);
	DIO_F_Set_Pin_Dir(PC,PIN_6,INPUT);
	DIO_F_Set_Pin_Dir(PC,PIN_7,INPUT);
	
	
	
	LCD_F_Init();

	while(1)
	{

		c=UART_RxChar();
		
		
		
		
		 if (c=='f')
		{
			DIO_F_Set_Pin_Val(PB,PIN_4,HIGH);
			LCD_F_Write_Command(0x01);
			
			
		}
		 else if(c=='b')
		{
 			DIO_F_Set_Pin_Val(PB,PIN_4,LOW);
 			LCD_F_Write_Command(0x01);
			 		}
					 
		else
		{			 
					 	
					 	LCD_F_Write_Command(0x01);
						 if (DIO_F_Get_Pin_Val(PD,PIN_5)==1)
						 {
							
							 LCD_F_Write_String("intruder");
							// while(DIO_F_Get_Pin_Val(PD,PIN_5)==1);
						 }
						 if (DIO_F_Get_Pin_Val(PC,PIN_4))
						 {
							 LCD_F_Go_To(1,0);
							 LCD_F_Write_String("accident : 20 cm");
						 }
						 if (DIO_F_Get_Pin_Val(PC,PIN_5))
						 {
							 LCD_F_Go_To(1,0);
							 LCD_F_Write_String("accident : 40 cm");
						 }
						 if (DIO_F_Get_Pin_Val(PC,PIN_6))
						 {
							 LCD_F_Go_To(1,0);
							 LCD_F_Write_String("accident : 60 cm");
						 }
						  if (DIO_F_Get_Pin_Val(PC,PIN_7))
						  {
							  LCD_F_Go_To(0,10);
							  LCD_F_Write_String("fire");
						  }
						 } 
	}	
}
