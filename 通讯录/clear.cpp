#include"all.h"
/*-------------���ݽṹ-----------------*/
/*-ѧ�ţ�int----------------------------*/
/*-���֣�char---------------------------*/
/*-�绰��int----------------------------*/
/*-���ܣ�����ļ��е�������Ϣ-----------*/
/*-----�����ͷŵ����нڵ���Ϣ-----------*/
/*--------------------------------------*/

stu*Clear_(stu*head)
{

	stu*p;
	fstream  clear("ѧ����Ϣ.txt", ios::trunc);			//��д
	if(remove("ѧ����Ϣ.txt") == 0)						//ɾ���ļ�
		cout<<"Delete successful"<<endl;
	cout << "clear all finsih" << endl;
	while (head)										//�ͷ����нڵ�
	{
		p = head;
		p = head->next;
		free(p);
		head = p;
	}
	clear.close();
	return head;
}