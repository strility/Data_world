/*--------------------------------*/
/*-----------后缀表达式-----------*/
/*---功能：把串中数据放进结构体里-*/
/*-------：然后转为后缀表达式-----*/
/*---作者：徐炜涛-----------------*/
/*---时间：2019：12：22-----------*/
/*--------------------------------*/

#include"head.h"
#include"global.h"
int judge_Symbol(char Symbol);				//优先级判断函数
int deal_number(string S,int i);			//处理非单个位数

stack<Node> s;
queue<Node> q;
queue<Node> q2;

int flas = 0;
//中缀转后缀函数
void Postfix_Expression(string S) {
	Node T;											//定义结构体变量存放串和数字
	for (int i = 0; i < S.length();i++) {			//中缀转后缀不解释了，网上一堆教程  短就对了，本来就没那么麻烦，如果不是结构体大概也就35行
		if (S[i] == '(') {
			T.Judge = false;
			T.op = S[i];
			s.push(T);
		}
		else if (S[i] == ')') {
			while (!s.empty() && s.top().op != '(') {
				q.push(s.top());
				s.pop();
			}
			s.pop();
		}
		else if (S[i] >= '0'&&S[i] <= '9') {
			i = deal_number(S,i);
		}
		else {
			T.Judge = false;
			while (!s.empty() && judge_Symbol(s.top().op) >= judge_Symbol(S[i])) {			//优先级函数
				q.push(s.top());
				s.pop();
			}
			T.op = S[i];
			s.push(T);
		}
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	q2 = q;
}
