#include<iostream>
using namespace std;

//创建英雄结构体
struct Hero
{
	string Name;
	int age;
	string sex;
};

//创建一个排序年龄的函数
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


//创建一个输出排序后数组的函数

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
	//创建英雄的结构体数组
	struct Hero HeroArray[] =
	{
		{"刘备",23,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"关羽",22,"男"},
		{"貂蝉",19,"女"},
	};


	int len;
	len = sizeof(HeroArray) / sizeof(HeroArray[0]);
	
	match(HeroArray, len);


	printall( HeroArray, len);


	system("pause");
	return 0;
}