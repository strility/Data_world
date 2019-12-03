/*--------------------------------*/
/*-----------表达式树输出---------*/
/*---功能：三序输出表达式树-------*/
/*---作者：徐炜涛-----------------*/
/*---时间：2019：12：22-----------*/
/*--------------------------------*/
#include"head.h"
#include"global.h"

//大概就是递归到你也能看懂我也能看懂的地步吧

void In_Order_Cout_Tree(B_Tree *root)
{
	if (root != NULL)
	{
		In_Order_Cout_Tree(root->L);
		if (root->Judge == true)
			cout << root->value << " ";
		else
			cout << root->op << " ";
		In_Order_Cout_Tree(root->R);
	}
}

void Pre_Order_Cout_Tree(B_Tree *root)
{
	if (root != NULL)
	{
		
		if (root->Judge == true)
			cout << root->value << " ";
		else
			cout << root->op << " ";
		In_Order_Cout_Tree(root->L);
		In_Order_Cout_Tree(root->R);
	}
}

void Post_Order_Cout_Tree(B_Tree*root)
{
	if (root != NULL)
	{
		In_Order_Cout_Tree(root->L);
		In_Order_Cout_Tree(root->R);
		if (root->Judge == true)
			cout << root->value << " ";
		else
			cout << root->op << " ";
	}
}

void All_Cout(B_Tree*root)
{
	cout << "先序遍历" << endl;
	Pre_Order_Cout_Tree(root);
	cout << endl;
	cout << "中序遍历" << endl;
	In_Order_Cout_Tree(root);
	cout << endl;
	cout << "后序遍历" << endl;
	Post_Order_Cout_Tree(root);
	cout << endl;
}