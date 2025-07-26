/*
 * MNVIC_private.h
 *
 *  Created on: Jul 27, 2024
 *      Author: ahmed
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_


typedef struct
{

u32 NVIC_ISER[8];
u32 RESERVED1[24];
u32 NVIC_ICER[8];
u32 RESERVED2[24];
u32 NVIC_ISPR[8];
u32 RESERVED3[24];
u32 NVIC_ICPR[8];
u32 RESERVED4[24];
u32 NVIC_IABR[8];
u32 RESERVED5[56];
u8 NVIC_IPR[240];
u32 RESERVED6[580];
u32 NVIC_STIR;

}MNVIC;



#define NVIC_BASE_ADDRESS  0xE000E100


#define NVIC    ((volatile MNVIC*)(NVIC_BASE_ADDRESS))
#define AIRCR *((volatile u32*)(0xE000ED0C))


#endif /* MNVIC_PRIVATE_H_ */
