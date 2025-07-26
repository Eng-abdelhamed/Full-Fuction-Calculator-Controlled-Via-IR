/*
 * CALC.h
 *
 *  Created on: Sep 12, 2024
 *      Author: ahmed
 */

#ifndef CALC_H_
#define CALC_H_


u8 push_operator(u8 operator_);
u8  push_operand(f64 operand);
u8  pop_operator();
u8  peak_operator();
f64  pop_operand();
void adjust_expression(u8 letter);
void adjust_deletion();
u8  convert_symbol_to_number(u8 symbol);
u8  convert_number_to_symbol(u8 number);
void In_To_Post(void);
void preprocessing(void);
f32 POW_MATH(f32 num1,f32 num2);
f64 Convert_string_float(u8 *ptr,u8 string_size);
f64 evaluate_expression(void);
f64 Calculate(void);
void Display_Float(f64 number,u8 starting_position);
void CALC_BUTTON_ACTION(u8 button);
void DRAW_EXPRESSION(void);

#endif /* CALC_H_ */
