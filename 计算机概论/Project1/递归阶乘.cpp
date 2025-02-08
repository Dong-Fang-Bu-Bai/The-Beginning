#include<iostream>
using namespace std;

int jiecheng(int N)
{
	while (1)
	{
		if (N == 0)
		{
			return 1;
		}
		else
		{
			return N * jiecheng(N - 1);
		}
	}
}



int main()
{
	int N;
	cin >> N;
	cout << jiecheng(N) << endl;



	system("pause");
	return 0;
}