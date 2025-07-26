/*
 * TFT_CALC.h
 *
 *  Created on: Sep 12, 2024
 *      Author: ahmed
 */

#ifndef TFT_CALC_H_
#define TFT_CALC_H_

#define TFT_NUMBER_0 0
#define TFT_NUMBER_1 1
#define TFT_NUMBER_2 2
#define TFT_NUMBER_3 3
#define TFT_NUMBER_4 4
#define TFT_NUMBER_5 5
#define TFT_NUMBER_6 6
#define TFT_NUMBER_7 7
#define TFT_NUMBER_8 8
#define TFT_NUMBER_9 9
#define TFT_SYMBOL_DOT 10
#define TFT_SYMBOL_ADD 11
#define TFT_SYMBOL_SUBTRACT 12
#define TFT_SYMBOL_MULTIPLY 13
#define TFT_SYMBOL_DIVIDE 14
#define TFT_SYMBOL_BRACKETO 15
#define TFT_SYMBOL_BRACKETC 16
#define TFT_SYMBOL_POWER 17
#define TFT_LETTER_S 18
#define TFT_LETTER_C 19
#define TFT_LETTER_O 20
#define TFT_LETTER_I 21
#define TFT_LETTER_A 22
#define TFT_LETTER_N 23
#define TFT_LETTER_L 24
#define TFT_LETTER_G 25
#define TFT_LETTER_E 26
#define TFT_LETTER_X 27
#define TFT_LETTER_P 28
#define TFT_LETTER_T 29


void DRAW_NUMBER(int Number,u8 block_number);
void ERASE_BLOCK(u8 block_number);
void Draw_Cursor(u8 block_number);
void Erase_Cursor(u8 block_number);

#endif /* TFT_CALC_H_ */
