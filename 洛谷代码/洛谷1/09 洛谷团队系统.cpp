//�������ʹ���Ŷ�ϵͳ�ǳ����������Լ�����Ŀ��������Լ��ĵ�����������Ŀ�Ͳ������ݣ�ÿ����Ҫ����ʱ��
//5 ���ӣ���������Ŷ����ϴ�˽����Ŀ��ÿ��ֻ��Ҫ����
//3 ���ӣ������ϴ���Ŀ֮ǰ����Ҫһ���Ի���
//11 ���Ӵ����������Ŷӡ�����Ҫ����
//n ����Ŀ������������û��ѵ���ʱ��̣������ Local��������� Luogu��
//�����Ƚϼ򵥣�û�ж���Ļ�˵
#include<iostream>
using namespace std;
int main9()
{
	int n = 0;
	cin >> n;
	int luogu = 11 + 3 * n;
	int local = 5 * n;
	if (local < luogu)
	{
		cout << "Local" << endl;
	}
	else
	{
		cout << "Luogu" << endl;
	}

	system("pause");

	return 0;


}