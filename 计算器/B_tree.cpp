/*---------------------------------*/
/*------------表达式树-------------*/
/*---功能：建立表达式树-----------*/
/*---作者：徐炜涛-----------------*/
/*---时间：2019：12：22-----------*/
/*--------------------------------*/
#include"head.h"
#include"global.h"

stack<B_Tree*> T_Tree;				//结构体
struct B_Tree* root;				//根节点
//坑点1：一开始栈没建立成指针，还一直懵逼怎么回事，导致内存泄漏，建立完这里也就完了
//坑点2：在给左右节点的时候请使用B来判断，虽然队列头节点是赋值给B的，但是会有内存泄漏（空的时候）没想到吧！

void Creat_Tree()
{
	while (!q.empty())
	{
		B_Tree * B = (B_Tree*)malloc(sizeof(B_Tree));	
		if (q.front().Judge == true)
		{
			B->Judge = true;
			B->value = q.front().num;
		}
		else
		{
			B->Judge = false;
			B->op = q.front().op;
		}
		B->R = NULL;
		B->L = NULL;

		if ((B->Judge!=true)&&(B->op == '+') || (B->op == '-') || (B->op == '*')||(B->op== '/'))
		{
			B->R = T_Tree.top();
			T_Tree.pop();
			B->L = T_Tree.top();
			T_Tree.pop();
		}
		T_Tree.push(B);
		q.pop();
	}
	root = T_Tree.top();
}

