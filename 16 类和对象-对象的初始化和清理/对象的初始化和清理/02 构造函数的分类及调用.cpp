#include<iostream>
using namespace std;

//1.���캯���ķ��༰����
//����
//   ���ղ�������  �޲ι��죨Ĭ�Ϲ��죩 ��  �вι���
//   �������ͷ���   ��ͨ����  ��������
class Person2
{
public:
	//���캯��

	//�޲ι��캯��
	Person2()
	{
		cout << "Person���޲ι��캯������" << endl;

	}

	//�вι��캯��
	Person2(int a)
	{
		age = a;
		cout << "Person���вι��캯������" << endl;

	}

	//�������캯��
	Person2(const Person2 &p)
	{
		//������������ϵ��������ԣ�������������
		cout << "Person�Ŀ������캯������" << endl;
		age = p.age;
	}


	~Person2()
	{
		cout << "Person��������������" << endl;
	}


	int age;

};

//����
void test9()
{
	//1.���ŷ�
	

	//Person p1;//Ĭ�Ϲ��캯������
	//Person p2(10);//�вι��캯������
	//Person p3(p2);//�������캯��

	//ע������1
	//����Ĭ�Ϲ��캯��ʱ����Ҫ�ӣ���
	//��Ϊ�������д��룬����������Ϊ��һ��������������������Ϊ�ڴ�������
	//Person p1();
	


	//cout << "p2������Ϊ��" << p2.age << endl;
	//cout << "p3������Ϊ��" << p3.age << endl;



	//2.��ʾ��
	

	//Person p1;
	//Person p2 = Person(10);//�вι���
	//Person p3 = Person(p2);//��������

	//Person(10);//��������  �ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
	//cout << "aaaaa" << endl;

	//ע������2
	// ��Ҫ���ÿ������캯������ʼ����������  
	// ��Ϊ��������Ϊ Person(p3) ���� Person p3; �� �����������������
	
	//Person(p3);




	//3.��ʽת�������ټ���
	//Person2 p4 = 10;//�вι��죬�൱�� д�� Person p4 = Person(10);
	//Person2 p5 = p4;//��������
}


int main2()
{

	test9();





	system("pause");
	return 0;
}