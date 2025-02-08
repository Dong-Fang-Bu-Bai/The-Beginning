#include<iostream>
using namespace std;


int main1()
{

	int n;
	cin >> n;


	int array[100];

	array[0] = 0;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		array[i] = a;
	}

	int temp = array[0];

	for (int i = 0; i < n; i++)
	{
		
		if (array[i]<=temp)
		{
			temp = array[i];
		}
	}

	cout << temp << endl;



	system("pause");
	return 0;
}