/*--------------------------------*/
/*------------优先级函数----------*/
/*---功能：判断符号优先级---------*/
/*---作者：徐炜涛-----------------*/
/*---时间：2019：12：22-----------*/
/*--------------------------------*/
#include"head.h"

//在写这个函数的时候其实也发现了一种比较好的写法，使用map去对应可以让函数更短
//强调以下STl库很好用，多看看会有很多解决办法

int judge_Symbol(char Symbol)
{
	if (Symbol == '+' || Symbol == '-')
		return 1;
	else if (Symbol == '*' || Symbol == '/')
		return 2;
	else if (Symbol == '(')
		return -1;
	else
		return 0;
}