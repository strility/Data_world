/*-------------------ͨѶ¼----------------------*/
/*-authon�������--------------------------------*/
/*-Edition����һ��-------------------------------*/
/*-Completion time��2019-9-28--------------------*/
/*-----------------------------------------------*/
#include"all.h"

stu*Create();                       //�����������ݽڵ�
stu*Insert_(stu*head, stu*p);		//�������ݽڵ�
stu*Delete_(stu*head, int id);		//ɾ�����ݽڵ�
stu*Display_(stu*head);				//չʾ���нڵ�
stu*Find_(stu*head, char name[]);	//�������ֲ�������Ľڵ�
stu*Rough(stu*head, char name[]);	//���Բ��ң��ؼ��ֲ���
stu*Store_(stu*head);				//���浽�ļ���
stu*Clear_(stu*head);				//����ڵ㲢ɾ���ļ�
int check_data(stu*head, int id, char name[], int tel); //�����Ƿ����ظ������ݣ��оͲ����浽����

int main()
{
	stu *head, *p,*link;            //head�Ǵ��ָ��Ľڵ㣬p����ʱ���ݴ���ڵ㣬link��
	int choice, id, tel;			//choiceѡ��ṹ
	char name[20];
	head = NULL;					//ͷָ��ָ��NULL
	int size = sizeof(stu);			//����ṹ��stu�Ĵ�С�Է������Ĳ���
	fstream check("ѧ����Ϣ.txt", ios::in | ios::out | ios::app);		//����ļ����Ƿ����ѧ����Ϣ
	do {
		cout<< " |*----------1:Create a large number of contacts-*|"<<endl
			<< " |*----------2:Insert a data---------------------*|"<<endl 
			<< " |*----------3:Detele the data-------------------*|"<<endl
			<< " |*----------4:Disply all the Mail list----------*|"<<endl
			<< " |*----------5:Store to the file-----------------*|"<<endl
			<< " |*----------6:Clear the file--------------------*|"<<endl
			<< " |*----------7:Accurate search-------------------*|"<<endl
			<< " |*----------8:rough search----------------------*|"<<endl
			<< " |*----------0:exit------------------------------*|"<<endl;
		while(check >> id >> name >> tel)//����ı��д�����Ϣ   ��ȡ������ŵ�������
		{
			link = (stu*)malloc(size);
			link->id = id;
			strcpy(link->name, name);
			link->tel = tel;
			head = Insert_(head, link);
		}
		fstream  clear("ѧ����Ϣ.txt", ios::trunc);    //���ǰ���о�ɾ����û��Ҳִ��һ�� ʹ���ݱ������ظ���
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Exit procedure" << endl;			//����0�˳�����
			break;		
		case 1:
			 head=Create();							//�������죬����ͷ�ڵ�һ�ߺ�������
			break;
		case 2: {
			cout << "Input your id name tel " << endl;	//����һ���ڵ㲢����ѧ������
			cin >> id >> name >> tel;
			p = (stu*)malloc(size);
			p->id = id;
			strcpy(p->name, name);
			p->tel = tel;
			if (!check_data(head, id, name, tel))
				head = Insert_(head, p);
				break;
			}
		case 3:
			cout << "Input what id do you want to delete" << endl;
			cin >> id;
			head=Delete_(head, id);					//����idɾ��
			break;
		case 4:
			head=Display_(head);						//չʾȫ��ѧ����Ϣ
			break;
		case 5:
			head=Store_(head);							//��������Ϣ������ı���
			break;
		case 6:
			Clear_(head);
			break;										//�����ǰ��Ϣ
		case 7:
			cout << "Search by name" << endl;
			cin >> name;
			Find_(head, name);							//�����ֲ���
			break;
		case 8:
			cout << "Rough Search" << endl;				//�ؼ��ֲ���
			cin >> name;
			Rough(head, name);
			break;
		default:
			cout << "enter error" << endl;				//�޹�ѡ��
			break;
		}
	} while (choice != 0);
	while (head)										//�ͷ�����ڵ�
	{
		p = head;
		p = head->next;
		free(p);
		head = p;
	}
}