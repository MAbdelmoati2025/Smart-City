


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#define F_CPU 1000000
#include "util/delay.h"


#define B2_PORT PD
#define B1_PORT PD
#define B0_PORT PB

#define B2 PIN_2
#define B1 PIN_6
#define B0 PIN_0

#define KEYPAD_ROWS_PORT PD
#define KEYPAD_COLS_PORT PB



void KPAD_F_Init(void);
U8_t KPAD_F_Get_Key(void); 


#endif /* KEYPAD_H_ */