#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：将节点储存到学生信息.txt的文件中*/
/*关键字：两个辅助指针------------------*/
/*--------------------------------------*/

stu *Store_(stu*head)
{
	fstream  stroe("./学生信息.txt", ios::out);			//
	stu*p;
	for (p = head; p != NULL; p = p->next)
		stroe << p->id << " " << p->name << " " << p->tel << endl;
	cout << "write finish" << endl;
	stroe.close();
	return head;
}