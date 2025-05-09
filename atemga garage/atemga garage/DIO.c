
#include "DIO.h"


void DIO_F_Set_Pin_Dir(U8_t port_Name, U8_t pin_Number, U8_t dir)
{
	switch (dir)
	{
		case INPUT:
		switch (port_Name)
		{
			case PA:
			CLR_BIT(DDRA, pin_Number);
			break;
			case PB:
			CLR_BIT(DDRB, pin_Number);
			break;
			case PC:
			CLR_BIT(DDRC, pin_Number);
			break;
			case PD:
			CLR_BIT(DDRD, pin_Number);
			break;
			default:
			break;
		}
		break;
		
		case  OUTPUT:
		switch (port_Name)
		{
			case PA:
			SET_BIT(DDRA, pin_Number);
			break;
			case PB:
			SET_BIT(DDRB, pin_Number);
			break;
			case PC:
			SET_BIT(DDRC, pin_Number);
			break;
			case PD:
			SET_BIT(DDRD, pin_Number);
			break;
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}


/************************Value function********************/

void DIO_F_Set_Pin_Val(U8_t port_Name, U8_t pin_Number, U8_t val)
{
	switch (val)
	{
		case LOW:
		switch (port_Name)
		{
			case PA:
			CLR_BIT(PORTA, pin_Number);
			break;
			case PB:
			CLR_BIT(PORTB, pin_Number);
			break;
			case PC:
			CLR_BIT(PORTC, pin_Number);
			break;
			case PD:
			CLR_BIT(PORTD, pin_Number);
			break;
			default:
			break;
		}
		break;
		
		case  HIGH:
		switch (port_Name)
		{
			case PA:
			SET_BIT(PORTA, pin_Number);
			break;
			case PB:
			SET_BIT(PORTB, pin_Number);
			break;
			case PC:
			SET_BIT(PORTC, pin_Number);
			break;
			case PD:
			SET_BIT(PORTD, pin_Number);
			break;
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}



U8_t DIO_F_Get_Pin_Val(U8_t port_Name, U8_t pin_Number)
{
	U8_t val = 0;
	switch (port_Name)
	{
		case PA:
		val = GET_BIT(PINA, pin_Number);
		break;
		case PB:
		val = GET_BIT(PINB, pin_Number);
		break;
		case PC:
		val = GET_BIT(PINC, pin_Number);
		break;
		case PD:
		val = GET_BIT(PIND, pin_Number);
		break;
		default:
		break;
	}
	
	return val;
}


void DIO_F_Set_Port_Dir(U8_t port_Name, U8_t dir)
{
	switch (dir)
	{
		case INPUT:
		switch (port_Name)
		{
			case PA:
			DDRA = 0x00;
			break;
			case PB:
			DDRB = 0x00;
			break;
			case PC:
			DDRC = 0x00;
			break;
			case PD:
			DDRD = 0x00;
			break;
			default:
			break;
		}
		break;
		case OUTPUT:
		switch (port_Name)
		{
			case PA:
			DDRA = 0xFF;
			break;
			case PB:
			DDRB = 0xFF;
			break;
			case PC:
			DDRC = 0xFF;
			break;
			case PD:
			DDRD = 0xFF;
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}


void DIO_F_Set_Port_State_Low_High(U8_t port_Name, U8_t state)
{
	switch (state)
	{
		case LOW:
		switch (port_Name)
		{
			case PA:
			PORTA = 0x00;
			break;
			case PB:
			PORTB = 0x00;
			break;
			case PC:
			PORTC = 0x00;
			break;
			case PD:
			PORTD = 0x00;
			break;
			default:
			break;
		}
		break;
		case HIGH:
		switch (port_Name)
		{
			case PA:
			PORTA = 0xFF;
			break;
			case PB:
			PORTB = 0xFF;
			break;
			case PC:
			PORTC = 0xFF;
			break;
			case PD:
			PORTD = 0xFF;
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}


void DIO_F_Set_Port_Val(U8_t port_Name, U8_t value)
{
	switch (port_Name)
	{
		case PA:
		PORTA = value;
		break;
		case PB:
		PORTB = value;
		break;
		case PC:
		PORTC = value;
		break;
		case PD:
		PORTD = value;
		break;
		default:
		break;
	}
}


U8_t DIO_F_Get_Port_Val(U8_t port_Name)
{
	U8_t val = 0;
	switch (port_Name)
	{
		case PA:
		val = GET_REG(PINA);
		break;
		case PB:
		val = GET_REG(PINB);
		break;
		case PC:
		val = GET_REG(PINC);
		break;
		case PD:
		val = GET_REG(PIND);
		break;
		default:
		break;
	}
	
	return val;
}