#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：删除节点-----------------------*/
/*-关键字：辅助指针---------------------*/
/*--------------------------------------*/

struct stu*Delete_(struct stu*head, int id)
{
	stu *ptr1, *ptr2;						//两个辅助指针 一个用来辅助删除
	if (head == NULL)
		return NULL;
	while (head != NULL && head->id == id)	//如果第一个就是所查找的数据
	{
		ptr2 = head;
		head = head->next;
		free(ptr2);
	}

	ptr1 = head;
	ptr2 = head->next;						//一前以后删除链表

	while (ptr2->next != NULL)
	{
		if (ptr2->id == id)
		{
			ptr1->next = ptr2->next;
			free(ptr2);					//
		}
		else
			ptr1->next = ptr2;
		ptr2 = ptr1->next;
	}
	cout << "delete finish" << endl;
	return head;
}