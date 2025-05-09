
#include "DIO.h"
#include "LCD.h"
#define F_CPU 1000000
#include <util/delay.h>


int main(void)
{
	LCD_F_Init();
	DIO_F_Set_Pin_Dir(PA,PIN_0,INPUT);
	DIO_F_Set_Pin_Dir(PA,PIN_1,INPUT);
	DIO_F_Set_Pin_Dir(PA,PIN_2,INPUT);
	DIO_F_Set_Pin_Dir(PA,PIN_3,INPUT);
    
    while (1) 
    {
		LCD_F_Write_Number(DIO_F_Get_Port_Val(PA));
		_delay_ms(200);
		LCD_F_Write_Command(0x01);
		
    }
}

