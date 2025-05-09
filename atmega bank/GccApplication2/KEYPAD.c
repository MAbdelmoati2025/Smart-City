
#include "KEYPAD.h"



#define SCANNING_IF		1
#define SCANNING_FOR	2
#define MODE SCANNING_FOR


void KPAD_F_Init(void)
{
	DIO_F_Set_Pin_Dir(KEYPAD_ROWS_PORT, PIN_0, OUTPUT);
	DIO_F_Set_Pin_Dir(KEYPAD_ROWS_PORT, PIN_1, OUTPUT);
	DIO_F_Set_Pin_Dir(KEYPAD_ROWS_PORT, PIN_2, OUTPUT);
	DIO_F_Set_Pin_Dir(KEYPAD_ROWS_PORT, PIN_3, OUTPUT);
	
	DIO_F_Set_Pin_Dir(KEYPAD_COLS_PORT, PIN_4, INPUT);
	DIO_F_Set_Pin_Dir(KEYPAD_COLS_PORT, PIN_5, INPUT);
	DIO_F_Set_Pin_Dir(KEYPAD_COLS_PORT, PIN_6, INPUT);
	DIO_F_Set_Pin_Dir(KEYPAD_COLS_PORT, PIN_7, INPUT);


	DIO_F_Set_Pin_Val(KEYPAD_COLS_PORT, PIN_4, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_COLS_PORT, PIN_5, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_COLS_PORT, PIN_6, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_COLS_PORT, PIN_7, HIGH);



}


#if MODE == SCANNING_IF
U8_t KPAD_F_Get_Key(void)
{
	U8_t key = 'z'; 
	
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_0, LOW);
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_1, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_2, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_3, HIGH);
	
	
	if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0)
	{
		key = '7';
		while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0);
	}
	else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0)
	{
		key = '8';
		while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0);
	}
	else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0)
	{
		key = '9';
		while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0);
	}
	else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0)
	{
		key = '-';
		while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0);
	}
	
	
	
	
		DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_0, HIGH);
		DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_1, LOW);
		DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_2, HIGH);
		DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_3, HIGH);
		
		if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0)
		{
			key = '4';
			while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0);
		}
		else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0)
		{
			key = '5';
			while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0);
		}
		else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0)
		{
			key = '6';
			while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0);
		}
		else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0)
		{
			key = '*';
			while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0);
		}
		
		
		
		
			DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_0, HIGH);
			DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_1, HIGH);
			DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_2, LOW);
			DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_3, HIGH);
			
			if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0)
			{
				key = '1';
				while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0);
			}
			else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0)
			{
				key = '2';
				while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0);
			}
			else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0)
			{
				key = '3';
				while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0);
			}
			else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0)
			{
				key = '/';
				while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0);
			}
			
			
			
			
				DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_0, HIGH);
				DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_1, HIGH);
				DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_2, HIGH);
				DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_3, LOW);
				
				if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0)
				{
					key = '*';
					while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_4) == 0);
				}
				else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0)
				{
					key = '0';
					while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_5) == 0);
				}
				else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0)
				{
					key = '#';
					while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_6) == 0);
				}
				else if(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0)
				{
					key = '+';
					while(DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, PIN_7) == 0);
				}
	

	return key;
}

#elif MODE == SCANNING_FOR
U8_t KPAD_F_Get_Key(void)
{
	U8_t default_Value = 'z', i, j;
	const U8_t key[4][4] = 
					 {
						{'1', '2', '3', 'A'}, 
						{'4', '5', '6', 'B'}, 
						{'7', '8', '9', 'C'}, 
						{'*', '0', '#', 'D'}
					 };
					 
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_0, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_1, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_2, HIGH);
	DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, PIN_3, HIGH);
	
	for(i=0; i<4; i++)
	{
		DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, i, LOW);
		for(j=0; j<4; j++)
		{
			if(!DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, 4+j))
			{
				default_Value = key[i][j];
				while(!DIO_F_Get_Pin_Val(KEYPAD_COLS_PORT, 4+j));
			}
		}
		DIO_F_Set_Pin_Val(KEYPAD_ROWS_PORT, i, HIGH);
	}	

	return default_Value;
}
#endif