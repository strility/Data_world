#include"all.h"
/*-------------���ݽṹ-----------------*/
/*-ѧ�ţ�int----------------------------*/
/*-���֣�char---------------------------*/
/*-�绰��int----------------------------*/
/*-���ܣ����������ڵ�-------------------*/
/*���ú��������ò��뺯��Insert----------*/
/*--------------------------------------*/
int check_data(stu*head, int id, char name[], int tel);
stu*Insert_(stu*head, stu*p);//���ڴ����ڵ�Ҳ��ʹ�õĲ��뺯��

struct stu*Create()
{
	int id, tel;						
	char name[20];
	int size = sizeof(stu);
	stu *head = NULL, *p;
	cout << "Enter your id name tel  when you enter 0 will stop a lot of input" << endl;
	while (cin >> id && id != 0 && cin >> name >> tel )
	{
		p = (stu*)malloc(size);
		p->id = id;
		strcpy(p->name, name);
		p->tel = tel;
		if (!check_data(head, id, name, tel))
			head = Insert_(head, p);		//����Insert����ִ��
	}
	return head;
}