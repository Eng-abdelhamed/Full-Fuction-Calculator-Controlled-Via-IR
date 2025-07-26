
#include"STD_TYPES.h"
#include "CALC.h"
#include "TFT_CALC.h"
#include "IR_interface.h"
#include "math_functions.h"
#include "TFT_interface.h"
u8 variable=0;
u8  OPERATOR_STACK[100];
f64 OPERANDS_STACK[100];
u8  Expression[100] = "2+-3*-4+-56.48*(45.8--77.1)/89.465";
u8  Post_Fix[100];
u8  Temp_String[100];              //
u8  operators_counter=0;          //
u8  operands_counter=0;          //
s16  expression_counter=-1;       //
u8  total_expression_counter=0;//
u8 cursor_pos=15;
u8 post_fix_counter=0;
u8 temp_string_counter=0;

u8  push_operator(u8 operator)
{
	if(operators_counter==100)
		return 0;
	OPERATOR_STACK[operators_counter++]=operator;
	return 1;

}

u8  push_operand(f64 operand)
{
	if(operands_counter==100)
		return 0;
	OPERANDS_STACK[operands_counter++]=operand;
	return 1;

}
u8  pop_operator()
{
	if(operators_counter!=0)
	{
		operators_counter--;
		return OPERATOR_STACK[operators_counter];

	}
	else
	{
		return 0;
	}
}
u8  peak_operator()
{
	if(operators_counter!=0)
	{
		return OPERATOR_STACK[operators_counter-1];

	}
	else
	{
		return 0;
	}
}

f64  pop_operand()
{
	if(operands_counter!=0)
	{
		operands_counter--;
		return OPERANDS_STACK[operands_counter];

	}
	else
	{
		return -1;
	}
}
void adjust_expression(u8 letter)
{
	if(expression_counter==-1)
	{
		for(u8 i=0;i<total_expression_counter;i++)
		{
			Expression[total_expression_counter-i]=Expression[total_expression_counter-i-1];

		}
	}
	else
	{
		for(u8 i=0;i<total_expression_counter-expression_counter-1;i++)
		{
			Expression[total_expression_counter-i]=Expression[total_expression_counter-i-1];

		}
	}
	expression_counter++;
	Expression[expression_counter]=letter;
	total_expression_counter++;
}
void adjust_deletion()
{
	if(expression_counter==-1)
	{
		return;
	}
	for(u8 i=0;i<total_expression_counter-expression_counter-1;i++)
	{
		Expression[expression_counter+i]=Expression[expression_counter+i+1];
	}
	total_expression_counter--;
	expression_counter--;
}
void DRAW_EXPRESSION(void)
{
	//cursor at 16+exp_pos
	u16 start=16;
	TFT_DrawRectangle(0,7,127,8*3+8-1+1,TFT_LIGHT_BLUE);
	if(expression_counter==-1)
	{
		Draw_Cursor(15);
	}
	for(u8 i=0;i<total_expression_counter;i++)
	{
		if(Expression[i]>=48 && Expression[i]<=57)
		{
			DRAW_NUMBER(Expression[i]-48,start);
			start++;
		}
		else if(Expression[i]=='.')
		{
			DRAW_NUMBER(TFT_SYMBOL_DOT,start);
			start++;
		}
		else if(Expression[i]=='+')
		{
			DRAW_NUMBER(TFT_SYMBOL_ADD,start);
			start++;
		}
		else if(Expression[i]=='-')
		{
			DRAW_NUMBER(TFT_SYMBOL_SUBTRACT,start);
			start++;
		}
		else if(Expression[i]=='*')
		{
			DRAW_NUMBER(TFT_SYMBOL_MULTIPLY,start);
			start++;
		}
		else if(Expression[i]=='/')
		{
			DRAW_NUMBER(TFT_SYMBOL_DIVIDE,start);
			start++;
		}
		else if(Expression[i]=='^')
		{
			DRAW_NUMBER(TFT_SYMBOL_POWER,start);
			start++;
		}
		else if(Expression[i]=='(')
		{
			DRAW_NUMBER(TFT_SYMBOL_BRACKETO,start);
			start++;
		}
		else if(Expression[i]==')')
		{
			DRAW_NUMBER(TFT_SYMBOL_BRACKETC,start);
			start++;
		}
		else if(Expression[i]=='s')
		{
			if(start%16>12)
			{
				start=16*(start/16+1);
			}
			DRAW_NUMBER(TFT_LETTER_S,start);
			DRAW_NUMBER(TFT_LETTER_I,start+1);
			DRAW_NUMBER(TFT_LETTER_N,start+2);
			DRAW_NUMBER(TFT_SYMBOL_BRACKETO,start+3);

			start+=4;
		}
		else if(Expression[i]=='c')
		{
			if(start%16>12)
			{
				start=16*(start/16+1);
			}
			DRAW_NUMBER(TFT_LETTER_C,start);
			DRAW_NUMBER(TFT_LETTER_O,start+1);
			DRAW_NUMBER(TFT_LETTER_S,start+2);
			DRAW_NUMBER(TFT_SYMBOL_BRACKETO,start+3);

			start+=4;
		}
		else if(Expression[i]=='t')
		{
			if(start%16>12)
			{
				start=16*(start/16+1);
			}
			DRAW_NUMBER(TFT_LETTER_T,start);
			DRAW_NUMBER(TFT_LETTER_A,start+1);
			DRAW_NUMBER(TFT_LETTER_N,start+2);
			DRAW_NUMBER(TFT_SYMBOL_BRACKETO,start+3);

			start+=4;
		}
		else if(Expression[i]=='e')
		{
			if(start%16>12)
			{
				start=16*(start/16+1);
			}
			DRAW_NUMBER(TFT_LETTER_E,start);
			DRAW_NUMBER(TFT_LETTER_X,start+1);
			DRAW_NUMBER(TFT_LETTER_P,start+2);
			DRAW_NUMBER(TFT_SYMBOL_BRACKETO,start+3);

			start+=4;
		}
		else if(Expression[i]=='l')
		{
			if(start%16>12)
			{
				start=16*(start/16+1);
			}
			DRAW_NUMBER(TFT_LETTER_L,start);
			DRAW_NUMBER(TFT_LETTER_O,start+1);
			DRAW_NUMBER(TFT_LETTER_G,start+2);
			DRAW_NUMBER(TFT_SYMBOL_BRACKETO,start+3);

			start+=4;
		}
		if(i==expression_counter)
		{
			Draw_Cursor(start-1);
			cursor_pos=start-1;
		}
	}


}

u8  convert_symbol_to_number(u8 symbol)
{
	if(symbol=='+')
	{
		return 129;
	}
	if(symbol=='-')
	{
		return 130;
	}
	if(symbol=='*')
	{
		return 139;
	}
	if(symbol=='/')
	{
		return 140;
	}
	if(symbol=='^')
	{
		return 150;
	}
	if(symbol=='(')
	{
		return 1;
	}
	if(symbol==')')
	{
		return 11;
	}

	return symbol;
}



u8  convert_number_to_symbol(u8 number)
{
	if(number==129)
	{
		return '+';
	}
	if(number==130)
	{
		return '-';
	}
	if(number==139)
	{
		return '*';
	}
	if(number==140)
	{
		return '/';
	}
	if(number==150)
	{
		return '^';
	}
	if(number==1)
	{
		return '(';
	}
	if(number==11)
	{
		return ')';
	}
	return number;

}
void In_To_Post(void)
{

	for(u8 j=0;j<expression_counter;j++)
	{
		if((Expression[j]>=48 && Expression[j]<=57) || (Expression[j]==46))
		{
			Post_Fix[post_fix_counter]=Expression[j];
			post_fix_counter++;
		}
		else
		{
			if(operators_counter==0)
			{
				push_operator(convert_symbol_to_number(Expression[j]));
				Post_Fix[post_fix_counter]=' ';
				post_fix_counter++;
			}
			else
			{
				if(convert_symbol_to_number(Expression[j])==11)
				{
					while((peak_operator()!=1) && (peak_operator()<97 || peak_operator()>122))
					{

						Post_Fix[post_fix_counter]=convert_number_to_symbol(pop_operator());
						post_fix_counter++;

					}
					if(peak_operator()>=97 && peak_operator()<=122)
					{
						Post_Fix[post_fix_counter]=convert_number_to_symbol(peak_operator());
						post_fix_counter++;
					}
					pop_operator();
					continue;
				}
				if(convert_symbol_to_number(Expression[j])<10 || (Expression[j]>=97 && Expression[j]<=122))
				{
					push_operator(convert_symbol_to_number(Expression[j]));
					Post_Fix[post_fix_counter]=' ';
					post_fix_counter++;
					continue;
				}
				if((peak_operator()+1)<convert_symbol_to_number(Expression[j]))
				{
					push_operator(convert_symbol_to_number(Expression[j]));
					Post_Fix[post_fix_counter]=' ';
					post_fix_counter++;
				}
				else
				{
					while(operators_counter!=0 && (peak_operator()+1)>=convert_symbol_to_number(Expression[j]))
					{

						Post_Fix[post_fix_counter]=convert_number_to_symbol(pop_operator());
						post_fix_counter++;
					}
					push_operator(convert_symbol_to_number(Expression[j]));

				}
			}

		}

	}


	while(operators_counter!=0)
	{

		Post_Fix[post_fix_counter]=convert_number_to_symbol(pop_operator());
		post_fix_counter++;
	}



	//here
}
void preprocessing(void)
{
	u8 i=0;
	while(i<expression_counter)
	{
		if(Expression[i]=='-')
		{
			if(i==0 || (!((Expression[i-1]>=48 && Expression[i-1]<=57)) &&(Expression[i-1]!=')')))
			{
				Temp_String[temp_string_counter]='(';
				Temp_String[temp_string_counter+1]='0';
				Temp_String[temp_string_counter+2]='-';
				temp_string_counter+=3;
				i++;
				while((i<expression_counter) &&((Expression[i]>=48 && Expression[i]<=57) || (Expression[i]==46)))
				{
					Temp_String[temp_string_counter]=Expression[i];
					temp_string_counter++;
					i++;
				}
				Temp_String[temp_string_counter]=')';
				temp_string_counter++;
				i--;
			}
			else
			{
				Temp_String[temp_string_counter]=Expression[i];
				temp_string_counter++;
			}
		}
		else
		{
			Temp_String[temp_string_counter]=Expression[i];
			temp_string_counter++;
		}

		i++;
	}
	expression_counter=temp_string_counter;
	for(u8 i=0;i<expression_counter;i++)
	{
		Expression[i]=Temp_String[i];
	}
}
f32 POW_MATH(f32 num1,f32 num2)
{
	f32 result=1;
	for(u8 i=0;i<num2;i++)
	{
		result=result*num1;
	}
	return result;

}
f64 Convert_string_float(u8 *ptr,u8 string_size)
{
	f64 conversion_result=0;
	u8 dot_position=string_size;
	for(u8 i=0;i<string_size;i++)
	{
		if(ptr[i]=='.')
		{
			dot_position=i;
		}
	}
	u8 integer_part=dot_position;
	for(u8 i=0;i<integer_part;i++)
	{
		conversion_result+=(POW_MATH(10,integer_part-i-1)*((f64)(ptr[i]-48)));
	}
	for(u8 i=dot_position+1;i<string_size;i++)
	{
		conversion_result+=((f64)(ptr[i]-48))*(f64)(1.0/(POW_MATH(10,i-dot_position)));
	}

	return conversion_result;
}
f64 evaluate_expression(void)
{

	u8 i=0;
	while(i<post_fix_counter)
	{
		if(Post_Fix[i]==' ')
		{
			i++;
			continue;
		}
		else if(((Post_Fix[i]>=48 && Post_Fix[i]<=57) || (Post_Fix[i]==46)))
		{
			u8 initial_pos=i;
			u8 number_size=0;
			while(( (Post_Fix[i]>=48 && Post_Fix[i]<=57) || (Post_Fix[i]==46) )&&(i<post_fix_counter))
			{
				number_size++;
				i++;
			}
			push_operand(Convert_string_float(&Post_Fix[initial_pos],number_size));

		}
		else if(Post_Fix[i]=='+')
		{
			f64 num2=pop_operand();
			f64 num1=pop_operand();
			push_operand(num1+num2);
			i++;

		}
		else if(Post_Fix[i]=='-')
		{
			f64 num2=pop_operand();
			f64 num1=pop_operand();
			push_operand(num1-num2);
			i++;

		}
		else if(Post_Fix[i]=='*')
		{
			f64 num2=pop_operand();
			f64 num1=pop_operand();
			push_operand(num1*num2);
			i++;

		}
		else if(Post_Fix[i]=='/')
		{
			f64 num2=pop_operand();
			f64 num1=pop_operand();
			push_operand(num1/num2);
			i++;

		}
		else if(Post_Fix[i]=='^')
		{
			f64 number2=pop_operand();
			f64 number1=pop_operand();
			push_operand(general_exponent(number1,number2));
			i++;

		}
		else if(Post_Fix[i]=='s')
		{
			f64 number1=pop_operand();
			push_operand(sin_func(number1));
			i++;

		}
		else if(Post_Fix[i]=='c')
		{
			f64 number1=pop_operand();
			push_operand(cos_func(number1));
			i++;

		}
		else if(Post_Fix[i]=='t')
		{
			f64 number1=pop_operand();
			push_operand(tan_func(number1));
			i++;

		}
		else if(Post_Fix[i]=='e')
		{
			f64 number1=pop_operand();
			push_operand(expo(number1));
			i++;

		}
		else if(Post_Fix[i]=='l')
		{
			f64 number1=pop_operand();
			push_operand(logarithm(number1));
			i++;

		}
	}

	return pop_operand();

}

f64 Calculate(void)
{
	expression_counter=(s16)total_expression_counter;
	total_expression_counter=0;
	preprocessing();
	In_To_Post();
	expression_counter=-1;
	return evaluate_expression();
}



void Display_Float(f64 number,u8 starting_position)
{
	int integer=(int)number;
	int floating;
	if(integer<0)
	{
		floating=(int)(((number*-1)-(double)(integer*-1))*10000);

	}
	else
	{
		floating=(int)((number-(double)integer)*10000);
	}
	u8 int_size=0;
	int temp=integer;
	while(1)
	{
		int_size++;
		temp=temp/10;
		if(temp==0)
		{
			break;
		}
	}
	if(integer<0)
	{
		starting_position++;
		DRAW_NUMBER(12,starting_position-1);
		integer*=-1;
	}
	for(u8 i=0;i<int_size;i++)
	{
		DRAW_NUMBER(integer%10,starting_position+(int_size-1)-i);
		integer=integer/10;
	}
	DRAW_NUMBER(10,starting_position+int_size);
	for(u8 i=0;i<4;i++)
	{
		DRAW_NUMBER(floating%10,starting_position+int_size+4-i);
		floating=floating/10;
	}
}

void CALC_BUTTON_ACTION(u8 button)
{
	f64 answer;
	switch (button)
	{
	case REMOTE_BUTTON_9:
		adjust_expression('0');
		DRAW_EXPRESSION();
		break;
	case REMOTE_BUTTON_12:
		adjust_expression('1');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_13:
		adjust_expression('2');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_14:
		adjust_expression('3');
		DRAW_EXPRESSION();
		break;
	case REMOTE_BUTTON_15:
		adjust_expression('4');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_16:
		adjust_expression('5');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_17:
		adjust_expression('6');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_18:
		adjust_expression('7');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_19:
		adjust_expression('8');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_20:
		adjust_expression('9');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_6:
		adjust_expression('-');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_7:
		adjust_expression('+');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_2:
		IR_StartDetection();
		while(1)
		{
			u8 button_press=IR_GetButtonPress();
			if(button_press!=0)
			{
				switch(button_press)
				{
				case REMOTE_BUTTON_12:
					adjust_expression('s');
					DRAW_EXPRESSION();
					break;
				case REMOTE_BUTTON_13:
					adjust_expression('c');
					DRAW_EXPRESSION();
					break;
				case REMOTE_BUTTON_14:
					adjust_expression('t');
					DRAW_EXPRESSION();
					break;
				case REMOTE_BUTTON_15:
					adjust_expression('^');
					DRAW_EXPRESSION();
					break;
				case REMOTE_BUTTON_16:
					adjust_expression('e');
					DRAW_EXPRESSION();
					break;
				case REMOTE_BUTTON_17:
					adjust_expression('l');
					DRAW_EXPRESSION();
					break;
				}
				break;
			}


		}
		IR_PauseDetection();
		break;
	case REMOTE_BUTTON_3:
		adjust_expression('*');
		DRAW_EXPRESSION();
		break;
	case REMOTE_BUTTON_4:
		adjust_expression('/');
		DRAW_EXPRESSION();
		break;
	case REMOTE_BUTTON_0:
		adjust_expression('(');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_1:
		adjust_expression(')');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_5:
		adjust_expression('.');
		DRAW_EXPRESSION();

		break;
	case REMOTE_BUTTON_8:
		answer=Calculate();
		variable=1;
		Display_Float(answer,96);
		variable=0;
		Erase_Cursor(cursor_pos);
		IR_StartDetection();
		while(1)
		{
			u8 button_press=IR_GetButtonPress();
			if(button_press!=0)
			{
				post_fix_counter=0;
				temp_string_counter=0;
				total_expression_counter=0;
				expression_counter=-1;
				IR_PauseDetection();
				TFT_DrawRectangle(0,0,127,159,TFT_WHITE);
				TFT_DrawRectangle(0,6,127,8*3+8-1+2,TFT_BLACK);
				TFT_DrawRectangle(0,7,127,8*3+8-1+1,TFT_LIGHT_BLUE);
				Draw_Cursor(15);
				break;
			}
		}
		break;
	case REMOTE_BUTTON_10:
		adjust_deletion();
		DRAW_EXPRESSION();
		break;
	case REMOTE_BUTTON_11:
		IR_StartDetection();
		while(1)
		{
			u8 button_press=IR_GetButtonPress();
			if(button_press==REMOTE_BUTTON_11)
			{
				break;
			}
			if(button_press!=0)
			{
				switch(button_press)
				{
				case REMOTE_BUTTON_6:
					if(expression_counter>-1)
					{
						expression_counter--;
						DRAW_EXPRESSION();
					}

					break;
				case REMOTE_BUTTON_7:
					if(expression_counter<(total_expression_counter-1))
					{
						expression_counter++;
						DRAW_EXPRESSION();
					}
					break;
				}
			}
		}
		IR_PauseDetection();
		break;
	}

}




