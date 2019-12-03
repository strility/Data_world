#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：批量创建节点-------------------*/
/*调用函数：调用插入函数Insert----------*/
/*--------------------------------------*/
int check_data(stu*head, int id, char name[], int tel);
stu*Insert_(stu*head, stu*p);//由于创建节点也是使用的插入函数

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
			head = Insert_(head, p);		//调用Insert函数执行
	}
	return head;
}