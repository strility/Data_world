#include<bits/stdc++.h>
using namespace std;

/*-------------数据结构-----------------*/
/*-学号：int----------------------------*/
/*-名字：char---------------------------*/
/*-电话：int----------------------------*/
/*--------------------------------------*/

/*
typedef struct tele
{
	string telea;
	tele*next;
}tele;/**/


typedef struct stu {
	int id;			//id storage student ID
	char name[20];	//storage student name
	int tel;		//storage student telephone
	stu *next;		//Link to the next node
}stu;				