#include<iostream>
using namespace std;


//1.���Ӣ�۵Ľṹ��
//Ӣ�۵Ľṹ��
struct Hero
{
	//����
	string name;
	//����
	int age;
	//�Ա�
	string sex;
};

//ð������ʵ���������������
void Bubblesort(struct Hero heroArray[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j <len-i-1; j++)
		{
			if (heroArray[j].age > heroArray[j + 1].age)
			{
				struct Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;

			}
		}
	}

}

//��ӡ����������е���Ϣ
void printHero(struct Hero heroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������" << heroArray[i].name << " "
			<< "���䣺" << heroArray[i].age << " "
			<< "�Ա�" << heroArray[i].sex << endl;

	}
}


int main8()
{

	//2.����������5��Ӣ��
	
	struct Hero heroArray[5]=
	{
		{"����",23,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",22,"��"},
		{"����",19,"Ů"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	for (int i = 0; i < len; i++)
	{
		cout << "������" << heroArray[i].name << " "
			<< "���䣺" << heroArray[i].age << " "
			<< "�Ա�" << heroArray[i].sex << endl;
	
	}
	//3.������������򣬰������������������
	Bubblesort( heroArray, len);

	cout << "������ӡΪ��" << endl;
	//4.�������Ľ����ӡ���
	printHero(heroArray, len);



	system("pause");
	return 0;
}