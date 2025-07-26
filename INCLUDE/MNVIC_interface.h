/*
 * MNVIC_interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: ahmed
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

#define NVIC_DIV 32
//letss gooo NVIC babyy

typedef enum
{
	Group16Sub0=3,
	Group8Sub2,
	Group4Sub4,
	Group2Sub8,
	Group0Sub16,



}MNVIC_GROUP_t;


#define VECTKEY 0x05FA0000
typedef enum
{
	EXTI0_VECTOR=6,
	EXTI1_VECTOR,
	EXTI2_VECTOR,
	EXTI3_VECTOR,
	EXTI4_VECTOR

}INTERRUPT_VECTORS_t;
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos);

void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_t Copy_uddtGroupMode);


void MNVIC_voidSetInterruptPriority(u8 pos,u8 sub,u8 group);

#endif /* MNVIC_INTERFACE_H_ */
