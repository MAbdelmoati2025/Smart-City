

#include "DIO.h"
#include "ADC.h"
#define F_CPU 1000000
#include <util/delay.h>


int main(void)
{
	ADC_F_Init(ADC_VCC,ADC_PRESCALER_8);
	
	int x;
	int y;
	int z;
	DIO_F_Set_Pin_Dir(PD,PIN_6,OUTPUT);
	DIO_F_Set_Pin_Dir(PD,PIN_5,OUTPUT);
	DIO_F_Set_Pin_Dir(PD,PIN_4,OUTPUT);
	DIO_F_Set_Pin_Dir(PD,PIN_3,OUTPUT);
   
    while (1) 
    {
		ADC_F_Start_Conversion(ADC_CHANNEL_0);
		ADC_F_Start_Conversion(ADC_CHANNEL_1);
		ADC_F_Start_Conversion(ADC_CHANNEL_2);
		
		
		x=ADC_F_Read(ADC_CHANNEL_0);
		y=ADC_F_Read(ADC_CHANNEL_1);
		z=ADC_F_Read(ADC_CHANNEL_2);
		
		
		if (z>450)
		{
			DIO_F_Set_Pin_Val(PD,PIN_4,HIGH);
			
		}
		else
		{
			DIO_F_Set_Pin_Val(PD,PIN_4,LOW);
		}
		if (x<300)
		{
			DIO_F_Set_Pin_Val(PD,PIN_5,HIGH);
			
		}
		else
		{
			DIO_F_Set_Pin_Val(PD,PIN_5,LOW);
		}
		if (y<600)
		{
			DIO_F_Set_Pin_Val(PD,PIN_6,HIGH);
			DIO_F_Set_Pin_Val(PD,PIN_3,LOW);
		}
		else
		{
			DIO_F_Set_Pin_Val(PD,PIN_6,LOW);
			DIO_F_Set_Pin_Val(PD,PIN_3,HIGH);
		}
    }
}

