/*----------------------------------*/
/*--------------数据转换------------*/
/*---功能：把非单个数字转化为double-*/
/*---作者：徐炜涛-------------------*/
/*---时间：2019：12：22-------------*/
/*----------------------------------*/
#include"head.h"
#include"global.h"

int deal_number(string S,int i)
{
	Node T;
	T.Judge = true;					//是数据
	T.num = S[i] - '0';				//先得到
	i++;							//往前走
	while (i < S.length() && (S[i] >= '0'&&S[i] <= '9')||S[i]=='.') {
		int k = 0;					//计算后面小数点后面的
		if (S[i] >= '0'&&S[i] <= '9')	//超过个位数的
		{
			if (S[i] > '0'&&S[i] <= '9')
				T.num = T.num * 10 + (S[i] - '0');		
			else      
				{ 
				T.num = T.num;         //没想到他居然是个0
				k++;
				}
			}
			else if (S[i] == '.')	   //遇到小数点的处理
			{
				i++;				   //串长
				k++;
				while (i <= S.length() && S[i] >= '0'&&S[i] <= '9')
				{
					T.num = (S[i] - '0') * pow(10, -k) + T.num;		//小数点后面的数据
					i++;
					k++;
				}
				i--;					//好好品下这里的i++我不会告诉你在这上面花了1小时的  原因是最后忘记减了
			}
			i++;
			}
		i--;
		q.push(T);
	return i;
}