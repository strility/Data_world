/*--------------------------------*/
/*------------����----------------*/
/*---���ܣ�ֱ���ýṹ���������---*/
/*---���ߣ������-----------------*/
/*---ʱ�䣺2019��12��22-----------*/
/*--------------------------------*/
#include"head.h"
#include"global.h"

//�������Ÿ��������ݣ���סС���ǿյ�
stack<Node> S_ans;

double Calculate()
{
	double num_1, num_2;
	Node T, Cur;
	while (!q2.empty())
	{
		Cur = q2.front();
		q2.pop();
		if (Cur.Judge == true)
			S_ans.push(Cur);
		else
		{
			num_2 = S_ans.top().num;
			S_ans.pop();
			num_1 = S_ans.top().num;
			S_ans.pop();
			T.Judge = true;
			if (Cur.op == '+')
				T.num = num_2 + num_1;
			else if (Cur.op == '-')
				T.num = num_1 - num_2;
			else if (Cur.op == '*')
				T.num = num_1 * num_2;
			else if(Cur.op == '/')
				T.num = num_1 / num_2;
			else if(T.op!='+'||T.op!='-'||T.op!='*'||T.op!='/')
			{
				return -999999999;
			}
			S_ans.push(T);
		}
	}
	return S_ans.top().num;
}