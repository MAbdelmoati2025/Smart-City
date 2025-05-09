


#ifndef ADC_H_
#define ADC_H_

#include "BIT_MATH.h"
#include "STD_TYPE.h"

#include "DIO.h"

#include "MEM_MAP.h"


typedef enum
{
    ADC_AREF = 0,
    ADC_VCC  = 1,
    ADC_V256 = 3 
}ENUM_ADC_Vref_Type;


typedef enum
{
    ADC_PRESCALER_2=0,
    ADC_PRESCALER_4=2,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128
}ENUM_ADC_Prescaler_Type;



typedef enum
{
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7
}ENUM_ADC_Channel_Type;



#define CHANNEL_PORT		PA
#define CHANNEL_1			PIN_1	





/*Func prototypes*/
void ADC_F_Init(ENUM_ADC_Vref_Type vref, ENUM_ADC_Prescaler_Type prescaler);
U16_t ADC_F_Read(ENUM_ADC_Channel_Type channel );
U16_t ADC_F_Get_Volt(ENUM_ADC_Channel_Type  channel);



void ADC_F_Start_Conversion(ENUM_ADC_Channel_Type channel);
U16_t ADC_F_Get_Read(void);
U16_t ADC_F_Get_Read_No_Block(void);


/*for example*/





#endif /* ADC_H_ */