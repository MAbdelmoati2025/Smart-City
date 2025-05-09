
#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "ADC.h"
//#include "timer.h"
#define F_CPU 1000000
#include <util/delay.h>


U8_t pass[6];
U8_t pass1[6]= {'1','1','1','1','1','1'};

int main(void)
{
	DIO_F_Set_Pin_Dir(PD,PIN_6,INPUT);
	DIO_F_Set_Pin_Dir(PD,PIN_5,INPUT);
	int flag;
	LCD_F_Init();
	KPAD_F_Init();
	U8_t key;
	DIO_F_Set_Pin_Dir(PC,PIN_1,INPUT);
	DIO_F_Set_Pin_Dir(PB,PIN_0,OUTPUT);
	ADC_F_Init(ADC_VCC,ADC_PRESCALER_128);
	ADC_F_Start_Conversion(ADC_CHANNEL_0);
	
// 	DDRD |=(1<<5);
// 	TCNT1=0;
// 	ICR1=2499;
// 
// 	SET_BIT(TCCR1A,WGM11);
// 	SET_BIT(TCCR1A,COM1A1);
// 
// 	SET_BIT(TCCR1B,WGM12);
// 	SET_BIT(TCCR1B,WGM13);
// 	SET_BIT(TCCR1B,CS10);
// 	SET_BIT(TCCR1B,CS11);
	
	int x; 
	int z=0;
	int hi=0;
	/*LCD_F_Write_String("Enter the pass");*/
	LCD_F_Write_String("hello");
	while(1)
	{
		
		
		x=ADC_F_Read(ADC_CHANNEL_0);
		
		//_delay_ms(2000);
		LCD_F_Write_Command(0x01);
// 		LCD_F_Go_To(1,0);
// 		LCD_F_Write_Number(x);
// 		LCD_F_Go_To(0,0);
        LCD_F_Write_String("Hold the button");
		LCD_F_Go_To(1,0);
		LCD_F_Write_String("to enter pass");
		_delay_ms(300);
		

		
	if (DIO_F_Get_Pin_Val(PC,PIN_1)==1)
	{
		LCD_F_Write_Command(0x01);
		LCD_F_Write_String("pass:");
	
		
		for(U8_t i=0 ;i<6;)
		{
			key=KPAD_F_Get_Key();
			if (key !='z')
			{
				pass[i]=key;
				LCD_F_Write_Char(key);
				i++;	
			}
		}
		LCD_F_Write_Command(0x01);
		 
		flag=  0;
		for (int j=0;j<6;j++)
		{
			if (pass[j]!=pass1[j])
			{
				flag++;
				
			}
						
        }

		if (flag==0)
		{
			
			LCD_F_Write_Command(0x01);
			LCD_F_Go_To(0,4);
			LCD_F_Write_String("hi momen");
			//-90
// 			OCR1A=100;
// 			_delay_ms(1000);
			
		}
		else
		{
			
			LCD_F_Write_Command(0x01);
			LCD_F_Go_To(0,5);
			LCD_F_Write_String("7arammy");
			//0
			//OCR1A=200;
 				//_delay_ms(1000);
				//90
//  				OCR1A=600;
//  				_delay_ms(2000);
		}
		_delay_ms(1000);
		LCD_F_Write_Command(0x01);
	}
	
// 	LCD_F_Write_Number(x);
// 	_delay_ms(500);
	LCD_F_Write_Command(0x01);
	if (x<=500)
	{
		z=1;
		
	}
	LCD_F_Write_Command(0x01);
	if (DIO_F_Get_Pin_Val(PD,PIN_5)==1)
	{
		hi=1;
	}
	else
	{
		hi=0;
	}
	while(z==1)
	{
		
				if(DIO_F_Get_Pin_Val(PD,PIN_6)==1)
				{
					DIO_F_Set_Pin_Val(PB,PIN_0,LOW);
					z=0;
					break;
				}
		LCD_F_Write_String("yalahwy");
		LCD_F_Go_To(0,0);
		DIO_F_Set_Pin_Val(PB,PIN_0,HIGH);

	}
	
		
	}
}













