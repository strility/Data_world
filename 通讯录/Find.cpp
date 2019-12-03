#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：精确查找到所需的名字信息-------*/
/*--------------------------------------*/

stu *Find_(stu*head, char name[])
{
	stu*p;
	for (p = head; p != NULL;p=p->next)     //针对名字精确查找
	{
		if (!strcmp(p->name, name))
		{
			cout << p->id << " "<<p->name<<" "<<p->tel<<endl;
			return head;
		}
		else
			cout << "can't find it" << endl;
	}
	/*for (p = head; !strcmp(p->name, name); p = p->next);
	if (p->next == NULL)
		cout << "can't find it" << endl;
	else
		cout << p->id << " " << p->name << " " << p->tel;*/
	return head;
}