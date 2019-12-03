/*---------------------------------*/
/*------------最大函数-------------*/
/*---功能：所有程序在此汇总--------*/
/*-------：以下会详细介绍----------*/
/*---作者：徐炜涛------------------*/
/*---时间：2019：12：22------------*/
/*---------------------------------*/

#include"head.h"
#include"global.h"
clock_t Start, End;						//时间函数   记录最终时间 //起始时间、结束时间
void Postfix_Expression(string S);		//读取到的串放进结构体转化为后缀表达式
void Creat_Tree();						//题目中要求后缀表达式，此处转化为表达式树
void All_Cout(B_Tree*root);				//把表达式树三序输出
double Calculate();						//计算表达式的结果，这里是直接用结构体数组计算，日后可以加树后缀计算
	
void The_Big_Function()
{
	fstream read("计算表达式.txt", ios::app | ios::in | ios::out);
	fstream last("计算表达式_log.txt", ios::trunc | ios::in | ios::out);
	string S, S2;				//S为读取串，S2为处理完毕后的串   可以只使用S一个串，这里我分开来是为了好区分
	stringstream s;				//讲结果为double类型的数据放进串中，贼好用
	vector<string>V;			//向量是为了写入
	double Ans;					//结果
	int Total = 0, Error = 0;	//总数个数和错误个数
	Start = clock();
	while (getline(read, S)) {
		Total++;				 
		Postfix_Expression(S);
		//cout<< Calculate()<<endl;
		Creat_Tree();
		//All_Cout(root);
		Ans = Calculate();

		if (Ans == -999999999)	//错误的表达式会返回特定答案以边区分
		{
			S += "错误表达式";
			Error++;
			V.push_back(S);		//结果放进向量里
		}
		else
		{
			S += "=";
			s << Ans;
			s >> S2;
			S += S2;
			cout << S << endl;
			s.clear();
			V.push_back(S);	
		}
	}
	End = clock();

	fstream  clear("计算表达式.txt", fstream::out | ios_base::trunc);//表中所有数据，把向量内容输入进去
	vector<string>::iterator vc = V.begin();						 //此处使用迭代器
	while (vc != V.end())
	{
		clear << (*vc).c_str();
		clear << endl;
		++vc;
	}
	double endtime = (double)(End - Start) / CLOCKS_PER_SEC;		//执行时间写如文件
	last << "执行运算时间：" << endtime << "ms" << endl;
	last << "正确的表达式个数:" << Total - Error << endl;
	last << "错误表达式个数:" << Error << endl << endl;
}