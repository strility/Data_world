#include"all.h"
/*-------------���ݽṹ-----------------*/
/*-ѧ�ţ�int----------------------------*/
/*-���֣�char---------------------------*/
/*-�绰��int----------------------------*/
/*-���ܣ���ȷ���ҵ������������Ϣ-------*/
/*--------------------------------------*/

stu *Find_(stu*head, char name[])
{
	stu*p;
	for (p = head; p != NULL;p=p->next)     //������־�ȷ����
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