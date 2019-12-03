#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：插入一个节点并排序-------------*/
/*关键字：两个辅助指针------------------*/
/*--------------------------------------*/

stu*Insert_(stu*head, stu*p)
{
	stu *ptr, *ptr1, *ptr2;    //创建两个辅助指针一个接受的数据的指针
	ptr2 = head;			  //接受头节点
	ptr = p;				 //接受数据节点
	if (head == NULL)			//判断链表是否为空
	{	
		head = ptr;
		head->next = NULL;
	}
	else
	{
		while (ptr->id > ptr2->id&&(ptr2->next != NULL))  //遍历去查找比传入数据小的位置
		{
			ptr1 = ptr2;								//利用辅助指针记录找到的位置
			ptr2 = ptr2->next;
		}
		if (ptr->id <= ptr2->id)						
		{
			if (head == ptr2)							//查找到的节点是否在头节点
				head = ptr;
			else
				ptr1->next = ptr;						//不在头节点
			ptr1->next = ptr2;		

		}
		else
		{
			ptr2->next = ptr;							//最小的情况就插入尾部
			ptr->next = NULL;
		}
	}
	return head;
}