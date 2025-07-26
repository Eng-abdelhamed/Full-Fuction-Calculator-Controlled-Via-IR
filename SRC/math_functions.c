/*
 * math_functions.c
 *
 *  Created on: Sep 15, 2024
 *      Author: mom
 */


#include "math_functions.h"
long double factorial_array[100]={0};
long double fact(int number)
{
	if(factorial_array[number]!=0)
	{
		return factorial_array[number];
	}
	long double start=1.0;
	for(int i=0;i<number;i++)
	{
		start*=((long double)i+1.0);

	}
	factorial_array[number]=start;
	return start;
}
double pow_func(double num,int power)
{
	double result=1.0;
	for(int i=0;i<power;i++)
	{
		result*=num;
	}
	return result;
}
double expo(double number)
{
	double result=0;
	for(int i=0;i<70;i++)
	{
		result+=((1.0/fact(i))*(pow_func(number,i)));
	}
	return result;
}
double logarithm(double number)
{
	double incrementer=0.1;

	if(number<=1)
	{
		incrementer=0.001;
	}
	else if((number<=100) && (number>=1))
	{
		incrementer=4.0;

	}
	else if((number<=2500) && (number>=100))
	{
		incrementer=7.3;

	}
	else if((number<=100000) && (number>=2500))
	{
		incrementer=11.0;

	}
	else if(number>100000)
	{
		incrementer=15.5;

	}
	double value_to_taylor=(number/(expo(incrementer)))-1.0;
	double taylor_result=0;
	for(int i=1;i<500;i++)
	{
		taylor_result+=((pow_func(-1.0,i+1))*(pow_func(value_to_taylor,i))/((double)i));
	}
	return taylor_result+incrementer;
}
double general_exponent(double num1,double num2)
{
	return (expo(num2*logarithm(num1)));
}




double sin_func(double angle)
{
	if(angle<0)
	{
		while(angle<-360)
		{
			angle+=360;
		}
	}
	else if(angle>0)
	{
		while(angle>360)
		{
			angle-=360;
		}
	}
	angle=angle*((3.1415926535)/180.0);
	double result=0;
	int sign_iterator=1;
	int iterator2=1;
	for(int i=0;i<40;i++)
	{
		result+=(double)sign_iterator*((1.0/fact(iterator2))*(pow_func(angle,iterator2)));
		iterator2+=2;
		sign_iterator*=-1;
	}
	return result;
}
double cos_func(double angle)
{
	if(angle<0)
	{
		while(angle<-360)
		{
			angle+=360;
		}
	}
	else if(angle>0)
	{
		while(angle>360)
		{
			angle-=360;
		}
	}
	angle=angle*((3.1415926535)/180.0);
	double result=0;
	int sign_iterator=1;
	int iterator2=0;
	for(int i=0;i<40;i++)
	{
		result+=(double)sign_iterator*((1.0/fact(iterator2))*(pow_func(angle,iterator2)));
		iterator2+=2;
		sign_iterator*=-1;
	}
	return result;
}
double tan_func(double angle)
{
	return ((sin_func(angle))/(cos_func(angle)));
}

