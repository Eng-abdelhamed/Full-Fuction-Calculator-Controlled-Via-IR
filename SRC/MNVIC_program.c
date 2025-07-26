/*
 * MNVIC_program.c
 *
 *  Created on: Jul 27, 2024
 *      Author: ahmed
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"MNVIC_private.h"
#include"MNVIC_interface.h"

static u8 Copy_u8GroupMode;
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos)
{
	(NVIC->NVIC_ISER[Copy_u8IntPos/NVIC_DIV]) |= (1<<(Copy_u8IntPos%NVIC_DIV));
//49 9

}

void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_t Copy_uddtGroupMode)
{
	Copy_u8GroupMode=Copy_uddtGroupMode;
	u32 Copy_u32Local;

	Copy_u32Local = VECTKEY | (Copy_uddtGroupMode<<8);


	AIRCR=Copy_u32Local;

}

void MNVIC_voidSetInterruptPriority(u8 pos,u8 sub,u8 group)
{
	//  Group16Sub0
	/*	Group8Sub2
		Group4Sub4
		Group2Sub8
		Group0Sub16  */

	switch(Copy_u8GroupMode)
	{
	case Group16Sub0:

		NVIC->NVIC_IPR[pos]  = group<<4;

		break;
	case Group8Sub2:
		NVIC->NVIC_IPR[pos]  = group<<5 | sub<<4;

		break;
	case Group4Sub4:
		NVIC->NVIC_IPR[pos]  = group<<6 | sub<<4;

		break;
	case Group2Sub8:

		NVIC->NVIC_IPR[pos]  = group<<7 | sub<<4;

		break;
	case Group0Sub16:
		NVIC->NVIC_IPR[pos]  = sub<<4;

		break;
	default:
		break;
}



}






