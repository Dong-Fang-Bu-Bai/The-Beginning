#include<iostream>
using namespace std;

//쳲���������
int fff(int a)
{
	static int i = 0;
	if (a == 1 || a == 2)
	{
		i++;
		cout << i << endl;
		return 1;
	}
	else
	{
		i++;
		cout << i << endl;
		return fff(a - 1) + fff(a - 2);
	}
}

//��¼����
int j = 0;
void move(char pos1, char pos2)
{
	j++;
	cout << pos1<< "->" << pos2 << endl;
}

//��ŵ������
void hanoi(int n, char pos1, char pos2, char pos3)
{
	if (n == 1)
	{
		move(pos1, pos3);
	}
	else
	{
		hanoi(n - 1, pos1, pos3, pos2);
		move(pos1, pos3);
		hanoi(n - 1, pos2, pos1, pos3);
	}
}


int main()
{
	/*int a;
	cin >> a;

	
	cout << fff(a) << endl;*/

	while (1)
	{
		j = 0;
		int n;
		cin >> n;
		hanoi(n, 'A', 'B', 'C');
		cout << j << endl;


		system("pause");
		system("cls");
	}
	return 0;
}