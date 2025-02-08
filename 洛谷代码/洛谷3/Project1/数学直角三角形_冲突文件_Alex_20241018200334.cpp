
//给出
//𝑛
//n，请输出一个直角边长度是
//𝑛
//n 的数字直角三角形。所有数字都是
//2
//2 位组成的，如果没有
//2
//2 位则加上前导
//0
//0。


#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main4()
{

	int n;
	cin >> n;
	int num = 0;
	string array1[99];
	int width = 2;
	for (int i = 0;i < 99; i++)
	{
		std::string str = std::to_string(i+1);

		// 如果字符串长度小于固定宽度，在前面补零
		if (str.length() < width) {
			// 使用 std::setw 和 std::setfill 来插入前导零
			str.insert(0, width - str.length(), '0');
		}

		array1[i] = str;

	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i; j++)
		{
			cout << array1[num];
			num++;
		}
		cout << endl;
	}







	system("pause");
	return 0;
}