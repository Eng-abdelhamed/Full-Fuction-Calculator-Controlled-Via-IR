/*
 * IR_program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: ahmed
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "MNVIC_interface.h"
#include "MEXTI_interface.h"
#include "IR_interface.h"
static u8 start_flag=0;
static u8 counter=0;
static u8 Line=255;
static u32 timing_array[50]={0};
static u8 IR_DATA=0;
static u8 data_ready=0;
void func1()
{

	if(start_flag==0)
	{
		start_flag=1;
		MSYSTICK_voidInterruptus(15000);

	}
	else
	{
		timing_array[counter]=(MSTK_u32GetElapsedTime())/2;
		counter++;
		MSYSTICK_voidInterruptus(5000);

	}

}
void func2(void)
{
	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);

	start_flag=0;
	if(counter==33)
	{
	for(u8 i=17;i<25;i++)
	{
		if(timing_array[i]>1000 && timing_array[i]<1300)
		{
			CLR((IR_DATA),(i-17));

		}
		else if(timing_array[i]>2000 && timing_array[i]<2500)
		{
			SET(IR_DATA,(i-17));

		}

	}
	data_ready=1;
	}
	counter=0;

}

void IR_Init(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MNVIC_voidEnableInterrupt(Copy_u8Pin+6);
	MRCC_voidEnable_Clock_Periphral(APB2,APB2_SYSCONFIG);
	MEXTI_voidInterruptTrigger(Copy_u8Pin,EXTI_Falling);
	Line=Copy_u8Pin;
	switch(Copy_u8Port)
	{
	case PORT_A:
		MGPIO_SetMode(PORT_A,Copy_u8Pin,INPUT_MODE);
		MGPIO_SetInputPinMode(PORT_A,Copy_u8Pin,PULL_UP);
		MEXTI_voidInterruptSetPort(Copy_u8Pin,EXTI_PortA);


		break;
	case PORT_B:
		MGPIO_SetMode(PORT_B,Copy_u8Pin,INPUT_MODE);
		MGPIO_SetInputPinMode(PORT_B,Copy_u8Pin,PULL_UP);
		MEXTI_voidInterruptSetPort(Copy_u8Pin,EXTI_PortB);

		break;
	case PORT_C:
		MGPIO_SetMode(PORT_C,Copy_u8Pin,INPUT_MODE);
		MGPIO_SetInputPinMode(PORT_C,Copy_u8Pin,PULL_UP);
		MEXTI_voidInterruptSetPort(Copy_u8Pin,EXTI_PortC);

		break;

	}
	MEXTI_voidCallBack(Copy_u8Pin,func1);
	MSYSTICK_voidCallBack(func2);
}

void IR_StartDetection(void)
{
	IR_DATA=0;
	data_ready=0;

	MEXTI_voidInterruptEnableDisable(Line,EXTI_Enable);


}
void IR_PauseDetection(void)
{
	MEXTI_voidInterruptEnableDisable(Line,EXTI_Disable);
	MSYSYTICK_voidCtrlIntState(SYSTICKDisable);

	start_flag=0;
	counter=0;

	for(u8 i=0;i<33;i++)
	{
		timing_array[i]=0;
	}
}

u8   IR_GetButtonPress(void)
{
	if(data_ready==1 && IR_DATA!=0)
	{
		u8 data=IR_DATA;
		IR_DATA=0;
		data_ready=0;
		for(u8 i=0;i<33;i++)
		{
			timing_array[i]=0;
		}
		return data;
	}
	return 0;
}
