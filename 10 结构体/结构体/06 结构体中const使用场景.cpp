#include<iostream>
using namespace std;

//const��ʹ�ó���

//����ѧ���ṹ��
struct student
{
	string name;
	int age;
	int score;
};
//�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������


void printStudent(const student *s)//��ָ����Խ�ʡ�ռ䣬��const���Է�ֹ�����
{
	//s->age=150;   ��ʱ���޷��޸�ֵ�ˣ����Է�ֹ�����
	cout << "������" << s->name << "���䣺" << s->age << "�÷֣�" << s->score << endl;
}


int main6()
{
	//�����ṹ�����
	struct student s = { "����",15,70 };

	//ͨ��������ӡ�ṹ�������Ϣ
	printStudent(&s);


	system("pause");
	return 0;
}