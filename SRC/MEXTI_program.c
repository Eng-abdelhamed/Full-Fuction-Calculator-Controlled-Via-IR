



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MEXTI_private.h"
#include "MEXTI_interface.h"

#include"MRCC_interface.h"
static void (*Global_EXTIPtr[16])(void);

void MEXTI_voidInterruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port)
{
	SYSCONFIG->SYSCFG_EXTICR[Copy_u8Line/4] &=~(15<<(4*(Copy_u8Line%4)));
	SYSCONFIG->SYSCFG_EXTICR[Copy_u8Line/4]|=Copy_u8Port<<(4*(Copy_u8Line%4));
	//test

}
void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis)
{

	if(Copy_u8ENDis==EXTI_Enable)
	{
	EXTI->EXTI_IMR|=1<<Copy_u8IntLine;
	}
	else if(Copy_u8ENDis==EXTI_Disable)
	{

	EXTI->EXTI_IMR&=~(1<<Copy_u8IntLine);

	}
}
void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig)
{


	if(Copy_u8Trig==EXTI_Rising)
	{
		EXTI->EXTI_RTSR|=1<<Copy_u8IntLine;
		EXTI->EXTI_FTSR&=~(1<<Copy_u8IntLine);
	}
	else if(Copy_u8Trig==EXTI_Falling)
	{
		EXTI->EXTI_RTSR&=~(1<<Copy_u8IntLine);
		EXTI->EXTI_FTSR|=1<<Copy_u8IntLine;


	}
	else if(Copy_u8Trig==EXTI_OnChange)
	{
		EXTI->EXTI_RTSR|=1<<Copy_u8IntLine;
		EXTI->EXTI_FTSR|=1<<Copy_u8IntLine;


	}



}
void MEXTI_voidCallBack(u8 Copy_u8IntLine,void (*ptr)(void))
{
	Global_EXTIPtr[Copy_u8IntLine]=ptr;

}



void EXTI0_IRQHandler(void){
	Global_EXTIPtr[0]();
    EXTI->EXTI_PR |=1;
}

void EXTI1_IRQHandler(void){
	Global_EXTIPtr[1]();
	  EXTI->EXTI_PR |=1<<1;
}
void EXTI2_IRQHandler(void){
	Global_EXTIPtr[2]();
	  EXTI->EXTI_PR |=1<<2;
}
