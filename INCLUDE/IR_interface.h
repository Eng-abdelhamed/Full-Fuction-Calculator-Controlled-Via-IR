/*
 * IR_interface.h
 *
 *  Created on: Aug 18, 2024
 *      Author: ahmed
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_


/*  BUTTONS LAYOUT
 *
 *   0  1  2
 * 	 3  4  5
 * 	 6  7  8
 * 	 9  10 11
 *   12 13 14
 *   15 16 17
 *	 18 19 20
 *
 */




#define REMOTE_BUTTON_0  69
#define REMOTE_BUTTON_1  70
#define REMOTE_BUTTON_2  71
#define REMOTE_BUTTON_3  68
#define REMOTE_BUTTON_4  64
#define REMOTE_BUTTON_5  67
#define REMOTE_BUTTON_6  7
#define REMOTE_BUTTON_7  21
#define REMOTE_BUTTON_8  9
#define REMOTE_BUTTON_9  22
#define REMOTE_BUTTON_10 25
#define REMOTE_BUTTON_11 13
#define REMOTE_BUTTON_12 12
#define REMOTE_BUTTON_13 24
#define REMOTE_BUTTON_14 94
#define REMOTE_BUTTON_15 8
#define REMOTE_BUTTON_16 28
#define REMOTE_BUTTON_17 90
#define REMOTE_BUTTON_18 66
#define REMOTE_BUTTON_19 82
#define REMOTE_BUTTON_20 74

void IR_Init(u8 Copy_u8Port,u8 Copy_u8Pin);
void IR_StartDetection(void);
void IR_PauseDetection(void);
u8   IR_GetButtonPress(void);

#endif /* IR_INTERFACE_H_ */
