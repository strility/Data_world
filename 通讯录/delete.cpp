#include"all.h"
/*-------------���ݽṹ-----------------*/
/*-ѧ�ţ�int----------------------------*/
/*-���֣�char---------------------------*/
/*-�绰��int----------------------------*/
/*-���ܣ�ɾ���ڵ�-----------------------*/
/*-�ؼ��֣�����ָ��---------------------*/
/*--------------------------------------*/

struct stu*Delete_(struct stu*head, int id)
{
	stu *ptr1, *ptr2;						//��������ָ�� һ����������ɾ��
	if (head == NULL)
		return NULL;
	while (head != NULL && head->id == id)	//�����һ�����������ҵ�����
	{
		ptr2 = head;
		head = head->next;
		free(ptr2);
	}

	ptr1 = head;
	ptr2 = head->next;						//һǰ�Ժ�ɾ������

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