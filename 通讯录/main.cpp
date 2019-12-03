/*-------------------通讯录----------------------*/
/*-authon：徐炜涛--------------------------------*/
/*-Edition：第一版-------------------------------*/
/*-Completion time：2019-9-28--------------------*/
/*-----------------------------------------------*/
#include"all.h"

stu*Create();                       //批量创建数据节点
stu*Insert_(stu*head, stu*p);		//插入数据节点
stu*Delete_(stu*head, int id);		//删除数据节点
stu*Display_(stu*head);				//展示所有节点
stu*Find_(stu*head, char name[]);	//根据名字查找所需的节点
stu*Rough(stu*head, char name[]);	//粗略查找，关键字查找
stu*Store_(stu*head);				//储存到文件中
stu*Clear_(stu*head);				//清除节点并删除文件
int check_data(stu*head, int id, char name[], int tel); //查找是否有重复的数据，有就不储存到表中

int main()
{
	stu *head, *p,*link;            //head是存放指针的节点，p是临时数据储存节点，link是
	int choice, id, tel;			//choice选择结构
	char name[20];
	head = NULL;					//头指针指向NULL
	int size = sizeof(stu);			//计算结构体stu的大小以方便后面的操作
	fstream check("学生信息.txt", ios::in | ios::out | ios::app);		//检查文件中是否存在学生信息
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
		while(check >> id >> name >> tel)//如果文本中存在信息   读取出来存放到链表中
		{
			link = (stu*)malloc(size);
			link->id = id;
			strcpy(link->name, name);
			link->tel = tel;
			head = Insert_(head, link);
		}
		fstream  clear("学生信息.txt", ios::trunc);    //如果前面有就删除，没有也执行一边 使数据保持无重复性
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Exit procedure" << endl;			//输入0退出程序
			break;		
		case 1:
			 head=Create();							//批量创造，返回头节点一边后续操作
			break;
		case 2: {
			cout << "Input your id name tel " << endl;	//插入一个节点并按照学号排序
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
			head=Delete_(head, id);					//根据id删除
			break;
		case 4:
			head=Display_(head);						//展示全部学生信息
			break;
		case 5:
			head=Store_(head);							//把链表信息储存回文本中
			break;
		case 6:
			Clear_(head);
			break;										//清除当前信息
		case 7:
			cout << "Search by name" << endl;
			cin >> name;
			Find_(head, name);							//按名字查找
			break;
		case 8:
			cout << "Rough Search" << endl;				//关键字查找
			cin >> name;
			Rough(head, name);
			break;
		default:
			cout << "enter error" << endl;				//无关选项
			break;
		}
	} while (choice != 0);
	while (head)										//释放链表节点
	{
		p = head;
		p = head->next;
		free(p);
		head = p;
	}
}