#include<iostream>
using namespace std;


//����������
//�ȽϺ�����ʵ�������������ֽ��бȽϣ����ؽϴ��ֵ


//��ǰ���߱����������Ĵ��ڣ��������ú���������
//����������
//��������д��Σ����Ƕ���ֻ����һ��
int max(int a, int b);//��vs2022�У�Ҳ����Ҫд����


int main5()
{

	int a = 10;
	int b = 20;
	cout << max(a, b) << endl;




	system("pause");
	return 0;

}


//���壨Ψһ��
int max(int a, int b)
{
	return a > b ? a : b;
}