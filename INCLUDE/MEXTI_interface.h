/*
 * MEXTI_interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: ahmed
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

typedef enum{
	EXTI_Disable,
	EXTI_Enable
}EXTI_ENDis;

typedef enum{
	EXTI_Rising,
	EXTI_Falling,
	EXTI_OnChange
}EXTI_Trigger;

typedef enum{
	EXTI_LineZero=0,
	EXTI_LineOne,
	EXTI_LineTwo,
	EXTI_LineThree,
	EXTI_LineFour,
	EXTI_LineFive,
	EXTI_LineSix,
	EXTI_LineSeven,
	EXTI_LineEight,
	EXTI_LineNine,
	EXTI_LineTen,
	EXTI_LineEleven,
	EXTI_LineTwelve,
	EXTI_LineThirteen,
	EXTI_LineFourteen,
	EXTI_LineFifteen

}EXTI_Line;

typedef enum{
	EXTI_PortA=0,
	EXTI_PortB,
	EXTI_PortC,
	EXTI_PortD,
	EXTI_PortE,
	EXTI_PortH=7,

}EXTI_Port;

void MEXTI_voidInterruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port);
void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis);
void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig);
void MEXTI_voidCallBack(u8 Copy_u8IntLine,void (*ptr)(void));





#endif /* MEXTI_INTERFACE_H_ */




