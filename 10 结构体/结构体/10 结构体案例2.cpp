#include<iostream>
using namespace std;

//����Ӣ�۽ṹ��
struct Hero
{
	string Name;
	int age;
	string sex;
};

//����һ����������ĺ���
void match(struct Hero HeroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (HeroArray[j].age < HeroArray[j + 1].age)
			{
				struct Hero temp = HeroArray[j];
				HeroArray[j] = HeroArray[j + 1];
				HeroArray[j + 1]= temp;


			}
		}
	}
}


//����һ��������������ĺ���

void printall(struct Hero HeroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << HeroArray[i].Name << " "
			<< HeroArray[i].age << " "
			<< HeroArray[i].sex << endl;
	}
}

int main10()
{
	//����Ӣ�۵Ľṹ������
	struct Hero HeroArray[] =
	{
		{"����",23,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",22,"��"},
		{"����",19,"Ů"},
	};


	int len;
	len = sizeof(HeroArray) / sizeof(HeroArray[0]);
	
	match(HeroArray, len);


	printall( HeroArray, len);


	system("pause");
	return 0;
}