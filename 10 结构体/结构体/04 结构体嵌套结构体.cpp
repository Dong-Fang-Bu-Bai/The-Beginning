#include<iostream>
using namespace std;

//����ѧ���ṹ��
struct student
{
	string name;//����
	int age;//����
	int score;//����
};



//������ʦ�ṹ��
struct teacher
{
	int id;
	string name;
	int age;
	struct student stu;

};



int main4()
{

	//�ṹ��Ƕ�׽ṹ��
	//������ʦ
	teacher t;
	t.id = 10000;
	t.name = "����";
	t.age = 50;
	t.stu.name = "С��";
	t.stu.age = 20;
	t.stu.score = 60;


	cout << "��ʦ����:" << t.name << endl
		<< "��ʦ���:" << t.id << endl
		<< "��ʦ���䣺" << t.age << endl
		<< "��ʦ������ѧ��������" << t.stu.name << endl
		<< "ѧ�����䣺" << t.stu.age << endl
		<< "ѧ���Ŀ��Է���Ϊ��" << t.stu.score << endl;





	system("pause");
	return 0;
}