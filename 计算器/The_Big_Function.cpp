/*---------------------------------*/
/*------------�����-------------*/
/*---���ܣ����г����ڴ˻���--------*/
/*-------�����»���ϸ����----------*/
/*---���ߣ������------------------*/
/*---ʱ�䣺2019��12��22------------*/
/*---------------------------------*/

#include"head.h"
#include"global.h"
clock_t Start, End;						//ʱ�亯��   ��¼����ʱ�� //��ʼʱ�䡢����ʱ��
void Postfix_Expression(string S);		//��ȡ���Ĵ��Ž��ṹ��ת��Ϊ��׺���ʽ
void Creat_Tree();						//��Ŀ��Ҫ���׺���ʽ���˴�ת��Ϊ���ʽ��
void All_Cout(B_Tree*root);				//�ѱ��ʽ���������
double Calculate();						//������ʽ�Ľ����������ֱ���ýṹ��������㣬�պ���Լ�����׺����
	
void The_Big_Function()
{
	fstream read("������ʽ.txt", ios::app | ios::in | ios::out);
	fstream last("������ʽ_log.txt", ios::trunc | ios::in | ios::out);
	string S, S2;				//SΪ��ȡ����S2Ϊ������Ϻ�Ĵ�   ����ֻʹ��Sһ�����������ҷֿ�����Ϊ�˺�����
	stringstream s;				//�����Ϊdouble���͵����ݷŽ����У�������
	vector<string>V;			//������Ϊ��д��
	double Ans;					//���
	int Total = 0, Error = 0;	//���������ʹ������
	Start = clock();
	while (getline(read, S)) {
		Total++;				 
		Postfix_Expression(S);
		//cout<< Calculate()<<endl;
		Creat_Tree();
		//All_Cout(root);
		Ans = Calculate();

		if (Ans == -999999999)	//����ı��ʽ�᷵���ض����Ա�����
		{
			S += "������ʽ";
			Error++;
			V.push_back(S);		//����Ž�������
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

	fstream  clear("������ʽ.txt", fstream::out | ios_base::trunc);//�����������ݣ����������������ȥ
	vector<string>::iterator vc = V.begin();						 //�˴�ʹ�õ�����
	while (vc != V.end())
	{
		clear << (*vc).c_str();
		clear << endl;
		++vc;
	}
	double endtime = (double)(End - Start) / CLOCKS_PER_SEC;		//ִ��ʱ��д���ļ�
	last << "ִ������ʱ�䣺" << endtime << "ms" << endl;
	last << "��ȷ�ı��ʽ����:" << Total - Error << endl;
	last << "������ʽ����:" << Error << endl << endl;
}