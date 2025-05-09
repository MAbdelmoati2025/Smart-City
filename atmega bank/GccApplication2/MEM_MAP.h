

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "STD_TYPE.h"

/*DIO*/
#define PIND		*((volatile U8_t*)0x30)
#define DDRD		*((volatile U8_t*)0x31)
#define PORTD		*((volatile U8_t*)0x32)

#define PINC		*((volatile U8_t*)0x33)
#define DDRC		*((volatile U8_t*)0x34)
#define PORTC		*((volatile U8_t*)0x35)

#define PINB		*((volatile U8_t*)0x36)
#define DDRB		*((volatile U8_t*)0x37)
#define PORTB		*((volatile U8_t*)0x38)

#define PINA		*((volatile U8_t*)0x39)
#define DDRA		*((volatile U8_t*)0x3A)
#define PORTA		*((volatile U8_t*)0x3B)

/*ADC*/
#define ADMUX		*((volatile U8_t*)0x27) //ADC multiplexer selection register
#define REFS1		 7
#define REFS0		 6
#define ADLAR		 5
#define MUX4		 4
#define MUX3		 3
#define MUX2		 2
#define MUX1		 1
#define MUX0		 0

#define ADCSRA		*((volatile U8_t*)0x26) //ADC status register
#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0

#define ADCH		*((volatile U8_t*)0x25) //ADC data register high
#define ADCL		*((volatile U8_t*)0x24) //ADC data register low

#define ADCLH		*((volatile U16_t*)0x24)

/*EXTI*/
#define MCUCR		*((volatile U8_t*)0x55)
#define ISC00		0
#define ISC01		1
#define MCUCSR		*((volatile U8_t*)0x54)
#define GIFR		*((volatile U8_t*)0x5A)
#define GICR		*((volatile U8_t*)0x5B)
#define INT1		7
#define INT0		6
#define INT2		5

 /*TIMER0*/
#define TCCR0       *((volatile U8_t*)0x53)
#define FOC0		7
#define WGM00		6
#define COM01		5
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0

#define TCNT0       *((volatile U8_t*)0x52)
#define OCR0        *((volatile U8_t*)0x5C)
#define TIMSK       *((volatile U8_t*)0x59)
#define OCIE2		7
#define TOIE2 		6
#define TICIE1 		5
#define OCIE1A 		4
#define OCIE1B 		3
#define TOIE1 		2
#define OCIE0 		1
#define TOIE0		0

#define TIFR        *((volatile U8_t*)0x58)
#define OCF2 		7
#define TOV2 		6
#define ICF1 		5
#define OCF1A 		4
#define OCF1B 		3
#define TOV1 		2
#define OCF0 		1
#define TOV0		0





/*TIMER1*/
#define TCCR1A		(*(volatile U8_t*)(0x4F))
#define COM1A1      7
#define COM1A0 		6
#define COM1B1 		5
#define COM1B0 		4
#define FOC1A 		3
#define FOC1B 		2
#define WGM11 		1
#define WGM10		0

#define TCNT1       (*(volatile U8_t*)(0x2c))

#define TCCR1B		(*(volatile U8_t*)(0x4E))
#define ICNC1		7
#define ICES1 		6

#define WGM13 		4
#define WGM12 		3
#define CS12 		2
#define CS11 		1
#define CS10		 0
#define OCR1A		(*(volatile U16_t*)0x4A)
#define ICR1		(*(volatile U16_t*)0x46)

/*UART*/
#define UBRRH		*((volatile U8_t*)0x40)
#define UBRRL		*((volatile U8_t*)0x29)
#define UCSRA		*((volatile U8_t*)0x2B)
#define UCSRB		*((volatile U8_t*)0x2A)
#define UCSRC		*((volatile U8_t*)0x40)
#define UDR			*((volatile U8_t*)0x2C)

/*SPI*/


typedef struct
{
	U8_t SPCR;
	U8_t SPSR;
	U8_t SPDR;
}SPI_t;


/*I2C*/
#define TWBR		*((volatile U8_t*)0x20)
#define TWSR		*((volatile U8_t*)0x21)
#define TWAR		*((volatile U8_t*)0x22)
#define TWDR		*((volatile U8_t*)0x23)
#define TWCR		*((volatile U8_t*)0x56)












// #define SPDR	*((volatile U8_t*)	((volatile U8_t*)0x2F)
// #define SPSR		((volatile U8_t*)0x2E)
#define SPI_REG		((volatile SPI_t*)0x2D) 
/************************Global interrupt********************/

#define SREG		*((volatile U8_t*)0x5F)

#define sei()	__asm__ __volatile__ ("sei"::) //enable the global interrupt
#define cli()	__asm__ __volatile__ ("cli"::) //disable the glb interrupt


#define ISR(vector)		void vector(void) __attribute__ ((signal));\
						void vector(void)

						
/*****************************vectors************************/

#define ADC_vect			__vector_16
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3
#define TIMER0_OVF_vect		__vector_11
#define TIMER1_COMPA_vect   __vector_7

















#endif /* MEMORY_MAP_H_ */

