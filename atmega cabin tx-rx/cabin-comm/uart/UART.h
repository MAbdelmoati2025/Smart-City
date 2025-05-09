


#ifndef UART_H_
#define UART_H_


#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "MEM_MAP.h"









void UART_F_Init(void);
void UART_F_Send_8_Bit(U8_t data);
void UART_F_Send_String(U8_t* string);
U8_t UART_F_Receive_8_Bit(void);







#endif /* UART_H_ */