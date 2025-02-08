#include<iostream>
using namespace std;

int main4()
{
	int a, b, c;
	cin >> a >> b >> c;

	int array[3] = { a,b,c };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}


	for (int i = 0; i < 3; i++)
	{
		cout << array[i]<<" ";
	}


	system("pause");
	return 0;
}