


#include "UART.h"

void UART_F_Init(void)
{
	U32_t UBBR_Val = 0;
	SET_BIT(DDRD, 1); //Tx is output
	CLR_BIT(DDRD, 0); //Rx is input
	
	SET_BIT(UCSRB, 3); //enable Tx
	SET_BIT(UCSRB, 4); //enable Rx
	
	UCSRC = 0x86; 
	
	UBBR_Val = (160000/(16 * 96)) - 1;
	UBRRL = UBBR_Val;
}

void UART_F_Send_8_Bit(U8_t data)
{
	UDR = data;
	while(GET_BIT(UCSRA, 6) == 0); //0 msh fady
}

void UART_F_Send_String(U8_t* string)
{
	while(*string != '\0')
	{
		UART_F_Send_8_Bit(*string++);
	}
}

U8_t UART_F_Receive_8_Bit(void)
{
	while(GET_BIT(UCSRA, 7) == 0);
	return UDR;
}