


#include "DIO.h"
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
	DIO_F_Set_Port_Dir(PC,OUTPUT);
    
    while (1) 
    {
		DIO_F_Set_Port_Val(PC,3);
    }
}

