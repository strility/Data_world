#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：输出所有有关于关键字的信息-----*/
/*--------------------------------------*/
stu*Rough(stu*head, char name[])
{
	stu*p;
	int count = 0;								//根据关键字查找，如果有找到的关键字就把有关键字的数据都输出
	for (p = head; p != NULL; p = p->next)
	{
		if (p->name[0]==name[0]||p->name[1]==name[1]||p->name[2]==name[2])
		{
			cout << p->id << " " << p->name << " " << p->tel << endl;
			count = 1;
		}
	}
	if (!count)									//是否存在
		cout << "can't find it" << endl;
	return head;
}