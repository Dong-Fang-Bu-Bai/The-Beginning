//

#include<iostream>
#include<string>
using namespace std;

int main2()
{
	int L;
	int R;
	cin >> L >> R;
	int num1 = 0;


	for (int i = L; i <= R; i++)
	{
		string str1 = to_string(i);
		char num2 = '2';
		int length = str1.size();
		for (int j = 0; j < length; j++)
		{
			if (str1[j] == num2)
			{
				num1++;
			}
		}
	}

	cout << num1 << endl;

	system("pause");
	return 0;
}