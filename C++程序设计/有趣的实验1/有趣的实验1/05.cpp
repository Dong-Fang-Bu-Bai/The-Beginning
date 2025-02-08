//【5】       写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过 100 个字符），
// 然后用柱状图输出每个字符在输入文件中出现的次数。严格地按照输出样例来安排你的输出格式。
// （洛谷P1598）
//
//例如：输入
//
//
//
//THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
//
//THIS IS AN EXAMPLE TO TEST FOR YOUR
//
//HISTOGRAM PROGRAM.
//
//HELLO!
//
//则输出为：


#include<iostream>
#include<string>
using namespace std;

int main5()
{
	int Letter[26] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		string a;
		getline(cin, a);

		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] >= 65 && a[j] < 91)
			{
				Letter[int(a[j]) - 65]++;
			}
		}
	}

	char display[100][100];//定义输出数组并初始化
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			display[i][j] = ' ';
		}
	}
	int j = 0;
	for (int i = 0; i < 52; i += 2)
	{

		display[99][i] = (char)(j + 65);
		j++;

	}

	int k = 0;
	for (int i = 0; i < 52; i += 2)
	{

		for (int j = 98; j >= 99 - Letter[k]; j--)
		{
			display[j][i] = '*';
		}
		k++;
	}

	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max <= Letter[i])
		{
			max = Letter[i];
		}
	}

	for (int j = 99 - max; j <= 99; j++)
	{
		for (int i = 0; i < 52; i++)
		{
			cout << display[j][i];

		}
		cout << endl;
	}


	system("pause");
	return 0;
}
	

