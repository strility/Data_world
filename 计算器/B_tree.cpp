/*---------------------------------*/
/*------------���ʽ��-------------*/
/*---���ܣ��������ʽ��-----------*/
/*---���ߣ������-----------------*/
/*---ʱ�䣺2019��12��22-----------*/
/*--------------------------------*/
#include"head.h"
#include"global.h"

stack<B_Tree*> T_Tree;				//�ṹ��
struct B_Tree* root;				//���ڵ�
//�ӵ�1��һ��ʼջû������ָ�룬��һֱ�±���ô���£������ڴ�й©������������Ҳ������
//�ӵ�2���ڸ����ҽڵ��ʱ����ʹ��B���жϣ���Ȼ����ͷ�ڵ��Ǹ�ֵ��B�ģ����ǻ����ڴ�й©���յ�ʱ��û�뵽�ɣ�

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

