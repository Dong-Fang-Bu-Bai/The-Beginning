#include<iostream>
using namespace std;

int main5()
{
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	int array1[3] = { num1,num2,num3 };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (array1[j] > array1[j + 1])
			{
				int temp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = temp;
			}
		}
	}


	int array2[3];

	string haha;
	cin >> haha;

	for (int i = 0; i < 3; i++)
	{
		if (haha[i] == 'A')
		{
			array2[i] = array1[0];
		}
		else if(haha[i] == 'B')
		{
			array2[i] = array1[1];
		}
		else
		{
			array2[i] = array1[2];
		}
	}



	for (int i = 0; i < 3; i++)
	{
		cout << array2[i] << " ";
	}




	system("pause");
	return 0;
}