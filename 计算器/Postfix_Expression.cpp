/*--------------------------------*/
/*-----------��׺���ʽ-----------*/
/*---���ܣ��Ѵ������ݷŽ��ṹ����-*/
/*-------��Ȼ��תΪ��׺���ʽ-----*/
/*---���ߣ������-----------------*/
/*---ʱ�䣺2019��12��22-----------*/
/*--------------------------------*/

#include"head.h"
#include"global.h"
int judge_Symbol(char Symbol);				//���ȼ��жϺ���
int deal_number(string S,int i);			//����ǵ���λ��

stack<Node> s;
queue<Node> q;
queue<Node> q2;

int flas = 0;
//��׺ת��׺����
void Postfix_Expression(string S) {
	Node T;											//����ṹ�������Ŵ�������
	for (int i = 0; i < S.length();i++) {			//��׺ת��׺�������ˣ�����һ�ѽ̳�  �̾Ͷ��ˣ�������û��ô�鷳��������ǽṹ����Ҳ��35��
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
			while (!s.empty() && judge_Symbol(s.top().op) >= judge_Symbol(S[i])) {			//���ȼ�����
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
