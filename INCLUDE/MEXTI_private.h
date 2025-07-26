/*
 * MEXTI_private.h
 *
 *  Created on: Jul 27, 2024
 *      Author: ahmed
 */

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_


typedef struct
{
	u32   SYSCFG_MEMRMP ;
	u32   SYSCFG_PMC ;
	u32   SYSCFG_EXTICR[4];
	u32   RESERVED[3];
	u32   SYSCFG_CMPCR;

}MSYSCONFIG_t;

typedef struct
{
	u32   EXTI_IMR ;
	u32   EXTI_EMR ;
	u32   EXTI_RTSR;
	u32   EXTI_FTSR;
	u32   EXTI_SWIER;
	u32   EXTI_PR;//flags

}MEXTI_t;



#define EXTI__BASE_ADRESS  0x40013C00
#define SYSCONFIG__BASE_ADRESS  0x40013800

#define EXTI ((volatile MEXTI_t*)(EXTI__BASE_ADRESS))

#define SYSCONFIG       ((volatile MSYSCONFIG_t*)(SYSCONFIG__BASE_ADRESS))


#endif /* MEXTI_PRIVATE_H_ */
