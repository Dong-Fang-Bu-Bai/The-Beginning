#include<iostream>
#include<iomanip>
using namespace std;

int main5()
{
	int a, b;
	cin >> a >> b;

	int k = a;
	
	for (int i = 0; i < b-1; i++)
	{
		k = k*a;
		
		k = k % 1000;

	}

	
	
	cout << setw(3) << setfill('0') << k<< endl;
	

	system("pause");
	return 0;
}