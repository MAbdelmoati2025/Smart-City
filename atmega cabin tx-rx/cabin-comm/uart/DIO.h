

#ifndef DIO_H_
#define DIO_H_



#include "STD_TYPE.h"
#include "MEM_MAP.h"
#include "BIT_MATH.h"



#define PA 0
#define PB 1
#define PC 2
#define PD 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define INPUT  0
#define OUTPUT 1

#define LOW 0
#define HIGH 1





void DIO_F_Set_Pin_Dir(U8_t port_Name, U8_t pin_Number, U8_t dir);
void DIO_F_Set_Pin_Val(U8_t port_Name, U8_t pin_Number, U8_t val);
U8_t DIO_F_Get_Pin_Val(U8_t port_Name, U8_t pin_Number);
void DIO_F_Set_Port_Dir(U8_t port_Name, U8_t dir);
void DIO_F_Set_Port_State_Low_High(U8_t port_Name, U8_t val);
void DIO_F_Set_Port_Val(U8_t port_Name, U8_t value);
U8_t DIO_F_Get_Port_Val(U8_t port_Name);



#endif /* DIO_H_ */