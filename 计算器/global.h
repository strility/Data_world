/*--------------------------------*/
/*----------变量和结构体----------*/
/*---功能：定义了全局变量---------*/
/*-------：和结构体数组-----------*/
/*---作者：徐炜涛-----------------*/
/*---时间：2019：12：22-----------*/
/*--------------------------------*/
#include"head.h"

typedef struct Node {			//结构体数组：用来存储读取文件串以后的数据和字符
	double num;					//采用分离的方法，数据为数据、符号为符号
	char op;			
	bool Judge;					//是数字就为ture
}Node;

typedef struct B_Tree			//构建树的时候使用，其实可以使用一个结构体
{
	char op;
	double value;
	bool Judge;
	B_Tree*R;
	B_Tree*L;
}B_Tree;

extern stack<Node> s;			//为了后缀表达式的使用，使用了结构体数组其实就不用转后缀表达式
extern stack<Node> S_ans;		//为了计算最后结果的使用栈，其实可以直接使用第一个栈，因为第一次已经使用完毕了
extern queue<Node> q;			//队列，一开始用串去处理的时候使用的是 数组替代了队列，此时需要多一个全局变量k去计数，但是一样可以操作
extern queue<Node> q2;			
extern stack<B_Tree*> T_Tree;	//指针树栈
extern struct B_Tree* root;		//根节点