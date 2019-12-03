#include"all.h"
/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*-功能：清除文件中的所有信息-----------*/
/*-----：并释放掉所有节点信息-----------*/
/*--------------------------------------*/

stu*Clear_(stu*head)
{

	stu*p;
	fstream  clear("学生信息.txt", ios::trunc);			//重写
	if(remove("学生信息.txt") == 0)						//删除文件
		cout<<"Delete successful"<<endl;
	cout << "clear all finsih" << endl;
	while (head)										//释放所有节点
	{
		p = head;
		p = head->next;
		free(p);
		head = p;
	}
	clear.close();
	return head;
}