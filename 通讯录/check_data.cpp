#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：查找表中数据是否有重复的数据---*/
/*------有重复的数据就不输入------------*/


int check_data(stu*head, int id, char name[], int tel)
{
	stu *p;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->id == id && !strcmp(p->name, name) && p->tel == tel)
			return 1;
	}
}