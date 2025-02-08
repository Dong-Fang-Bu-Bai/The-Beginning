//给定一个整数
//𝑁
//N，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例 2）。

#include<iostream>
#include<string>
using namespace std;

int main5()
{
	string x;
	cin >> x;
	int y = x.size();
	
	if (x[0] != '-'&&x[0]!='0')
	{

		if (x[y - 1] != '0')
		{
			for (int i = 0; i < (y / 2); i++)
			{
				char temp1;
				temp1 = x[i];
				x[i] = x[y - 1 - i];
				x[y - 1 - i] = temp1;
			}
		}
		else
		{
		
			for (int i = 0; i < (y / 2); i++)
			{
				char temp1;
				temp1 = x[i];
				x[i] = x[y - i - 1];
				x[y - i - 1] = temp1;
			}
			while (x[0] == '0')
			{
				x.replace(0, 1, "");
			}
			
		}
	}

	if (x[0] == '-')
	{
		if (x[y - 1] != '0')
		{
			for (int j = 1; j < (y / 2); j++)
			{
				char temp1;
				temp1 = x[j];
				x[j] = x[y - j];
				x[y - j] = temp1;
			}
		}
		else
		{
			for (int k = 1; k < (y / 2); k++)
			{
				char temp1;
				temp1 = x[k];
				x[k] = x[y - k];
				x[y - k ]= temp1;
			}
			while (x[1] == '0')
			{
				x.replace(1, 1, "");
			}
		}
	}
	else if (y = 1 && x[0] == '0')
	{
		x = "0";
	}
	
	
	
			
	


	
	
	cout << x << endl;




	system("pause");
	return 0;


	
}