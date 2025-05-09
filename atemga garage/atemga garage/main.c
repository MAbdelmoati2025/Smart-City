

#include "DIO.h"
#include "ADC.h"
#define F_CPU 1000000
#include <util/delay.h>
#include "LCD.h"
#include "ultrasonic.h"

#define TCNT1       (*(volatile U8_t*)(0x2c))

extern U32_t distance;

int main(void)
{
	
	
	
	
	LCD_F_Init();
	DIO_F_Set_Pin_Dir(PB,PIN_1,OUTPUT);
	ADC_F_Init(ADC_VCC,ADC_PRESCALER_128);
	ADC_F_Start_Conversion(ADC_CHANNEL_2);
	
	DIO_F_Set_Pin_Dir(PD,PIN_4,INPUT);
    DIO_F_Set_Pin_Dir(PC,PIN_1,OUTPUT);
	DIO_F_Set_Pin_Dir(PD,PIN_6,INPUT);
	
	DIO_F_Set_Pin_Dir(PA,PIN_0,OUTPUT);
	DIO_F_Set_Pin_Dir(PA,PIN_1,OUTPUT);
	int counter =0;
	 
	
	DIO_F_Set_Pin_Dir(PB,PIN_2,OUTPUT);
	
	
   ultrasonic_init();
	
	
	
	int flag_in=1;
	int flag_out=1;
	//servo
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11);
	ICR1 =2449;
	TCNT1 =0;
	DIO_F_Set_Pin_Dir(PD,PIN_5,OUTPUT);
	
	DIO_F_Set_Pin_Dir(PA,PIN_3,OUTPUT);
	DIO_F_Set_Pin_Dir(PA,PIN_5,OUTPUT);
	DIO_F_Set_Pin_Dir(PA,PIN_6,OUTPUT);
	
	
    while (1) 
    {
// 		OCR1A=300;
// 		_delay_ms(2000);
// 		OCR1A=220;
// 		_delay_ms(2000);
		if (DIO_F_Get_Pin_Val(PD,PIN_4)==0)
		{
			flag_in=0;
			if(counter>0)
			{counter--;
			
			
			while(DIO_F_Get_Pin_Val(PD,PIN_4)==0);
			}
			
			
		}
		else
		{
			flag_in=1;
		}
		if (DIO_F_Get_Pin_Val(PD,PIN_6)==0)
		{
			flag_out=0;
			if(counter<8)
			{counter++;
			
			
			
			while(DIO_F_Get_Pin_Val(PD,PIN_6)==0);
			}
		}
		else
		{
			flag_out=1;
		}
		
		if ((flag_out==0))
		{
			DIO_F_Set_Pin_Val(PC,PIN_1,HIGH);
			OCR1A=200;
			_delay_ms(2000);	
			while(flag_in==0);
		}
		else if(flag_in==0)
		{
			DIO_F_Set_Pin_Val(PC,PIN_1,HIGH);
			OCR1A=200;
			_delay_ms(2000);
			while(flag_out==0);
		}
		else
		{
			DIO_F_Set_Pin_Val(PC,PIN_1,LOW);
			OCR1A=300;
		}
		if (counter<8)
		{
			DIO_F_Set_Pin_Val(PA,PIN_0,HIGH);
			DIO_F_Set_Pin_Val(PA,PIN_1,LOW);
		}
		else
		{
			DIO_F_Set_Pin_Val(PA,PIN_0,LOW);
			DIO_F_Set_Pin_Val(PA,PIN_1,HIGH);
			
		}
// 		for(int i=200;i<=400;i++)
// 		{
// 			OCR1A=i;
// 			_delay_us(50);
// 		}
// 		for(int i=400;i>=200;i=i-1)
// 		{
// 			OCR1A=i;
// 			_delay_us(50);
// 		}
			 		
     if (distance<6)
     {
		 DIO_F_Set_Pin_Val(PB,PIN_2,HIGH);
		 if (distance>0 && distance<=20)
		 {
			 DIO_F_Set_Pin_Val(PA,PIN_3,HIGH);
			 _delay_ms(500);
			 
		 }
		else if (distance>20 && distance<=40)
		 {
			 DIO_F_Set_Pin_Val(PA,PIN_5,HIGH);
			 _delay_ms(500);
		 }
		 else if (distance>40 && distance<=60)
		 {
			 DIO_F_Set_Pin_Val(PA,PIN_6,HIGH);
			 _delay_ms(500);
		 }
     }
	 else
	 {
		 DIO_F_Set_Pin_Val(PA,PIN_3,LOW);
		 DIO_F_Set_Pin_Val(PA,PIN_5,LOW);
		 DIO_F_Set_Pin_Val(PA,PIN_6,LOW);
		  DIO_F_Set_Pin_Val(PB,PIN_2,LOW);
	 }
		
		
		

		
    }
}



