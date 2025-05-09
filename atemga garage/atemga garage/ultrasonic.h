#ifndef _ULTRA_H_
#define _ULTRA_H_

#include "LCD.h"
#include "MEM_MAP.h"
#include "STD_TYPE.h"
#define F_CPU 1000000
#include <util/delay.h>
#include "timer.h"
#include "BIT_MATH.h"


#define ISR(vector)		void vector(void) __attribute__ ((signal));\
void vector(void)


/*****************************vectors************************/

#define ADC_vect			__vector_16
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3
#define TIMER0_OVF_vect		__vector_11
#define TIMER1_COMPA_vect   __vector

#define sei()	__asm__ __volatile__ ("sei"::) //enable the global interru







#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGER        0
#define   ECHO          3


#define ISC10   2



/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void enable_ex_interrupt(void);
void ultrasonic_triger(void);


#endif
