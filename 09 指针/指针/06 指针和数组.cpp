#include<iostream>
using namespace std;
int main6()
{



	//ָ�������
	//����ָ����������е�Ԫ��

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "��һ��Ԫ��Ϊ��" << arr[0] << endl;



	int* p = &arr[0];
	//      int*p=arr;     Ҳ����     arr����������׵�ַ

	cout << "����ָ����ʵ�һ��Ԫ�أ�" << *p << endl;

	p++;//��ָ�����ƫ��4���ֽ�,��Ϊ����һ������ָ��

	cout << "����ָ����ʵڶ���Ԫ�أ�" << *p << endl;


	cout << "����ָ���������" << endl;

	//int* p2 = arr;
	//for (int i=0;i<10;i++)
	//{
	//	//cout << arr[i] << endl;
	//	cout << *p2 << endl;
	//	p2++;
	//}
	//       �һ�������������֣�Ҳ�е�ͨ
	for (int* p2 = arr; p2 < arr + 10; p2++)
	{
		cout << *p2 << endl;
	}


	system("pause");
	return 0;
}