#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "MNVIC_interface.h"
#include "MEXTI_interface.h"
#include "MSPI_interface.h"
#include "TFT_interface.h"
#include "IR_interface.h"
#include "CALC.h"
#include "TFT_CALC.h"
#include "math_functions.h"
void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnable_Clock_Periphral(AHB1,AHB1_GPIOA);
	MRCC_voidEnable_Clock_Periphral(AHB1,AHB1_GPIOB);

	MRCC_voidEnable_Clock_Periphral(APB2,12);

	MGPIO_SetMode(PORT_A,PIN_0,OUTPUT_MODE);
	MGPIO_SetMode(PORT_A,PIN_1,OUTPUT_MODE);
	MGPIO_SetMode(PORT_A,PIN_2,OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORT_A,PIN_0,OUT_PUSH_PULL,OUT_MED_SPEED);
	MGPIO_SetOutputPinMode(PORT_A,PIN_1,OUT_PUSH_PULL,OUT_MED_SPEED);
	MGPIO_SetOutputPinMode(PORT_A,PIN_2,OUT_PUSH_PULL,OUT_MED_SPEED);
	for(u8 i=0;i<100;i++)
	{
		fact(i);
	}

	MSYSYTICK_voidInit();
	IR_Init(PORT_B,PIN_0);

	for(u8 i=4;i<8;i++)
	{
		MGPIO_SetMode(PORT_A,i,ALTERNATIVE_FUNC_MODE);
		MGPIO_SetAlternativeFunction(PORT_A,i,5);
	}
	MSPI_MasterInit();
	TFT_Init();
	TFT_DrawRectangle(0,0,127,159,TFT_WHITE);
	TFT_DrawRectangle(0,6,127,8*3+8-1+2,TFT_BLACK);
	TFT_DrawRectangle(0,7,127,8*3+8-1+1,TFT_LIGHT_BLUE);
	Draw_Cursor(15);
	IR_StartDetection();
	while(1)
	{
		u8 button_press;
		button_press=IR_GetButtonPress();
		if(button_press!=0)
		{
			IR_PauseDetection();
			CALC_BUTTON_ACTION(button_press);
			IR_StartDetection();
		}
	}
	//display at 96 and write at 16

	while(1);
}

