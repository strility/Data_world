#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：展示链表中的所有节点-----------*/
/*--------------------------------------*/

stu *Display_(stu*head)
{
	stu*p;
	if (head == NULL)      //是否为空
	{
		cout << "the List is empty" << endl; 
		return NULL;
	}
	for (p = head; p != NULL; p=p->next)   //不空就遍历输出
	{
		cout << p->id << " " << p->name << " " << p->tel << endl;
	}
	return head;
}