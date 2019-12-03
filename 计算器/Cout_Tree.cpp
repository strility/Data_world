/*--------------------------------*/
/*-----------���ʽ�����---------*/
/*---���ܣ�����������ʽ��-------*/
/*---���ߣ������-----------------*/
/*---ʱ�䣺2019��12��22-----------*/
/*--------------------------------*/
#include"head.h"
#include"global.h"

//��ž��ǵݹ鵽��Ҳ�ܿ�����Ҳ�ܿ����ĵز���

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
	cout << "�������" << endl;
	Pre_Order_Cout_Tree(root);
	cout << endl;
	cout << "�������" << endl;
	In_Order_Cout_Tree(root);
	cout << endl;
	cout << "�������" << endl;
	Post_Order_Cout_Tree(root);
	cout << endl;
}