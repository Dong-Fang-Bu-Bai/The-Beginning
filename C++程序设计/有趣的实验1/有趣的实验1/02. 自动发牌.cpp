//【2】       自动发牌。一副扑克有52张牌，打桥牌时应将牌分给四个人。
// 请设计一个程序完成自动发牌的工作。要求：黑桃用S(Spaces)表示；红桃用H(Hearts)表示；
// 方块用D(Diamonds)表示；梅花用C(Clubs)表示。按照打桥牌的规定，每人应当有13张牌。
// 在人工发牌时，先进行洗牌……

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main2()
{
	srand((int)time(0));
	int arr[52];
	for (int i = 1; i <= 52; i++)
	{
		arr[i - 1] = i;//赋初值
	}

	int arr1[13];
	int S[4] = { 0 }, H[4] = { 0 }, D[4] = { 0 }, C[4] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int b = rand() % 52;
			while (arr[b] == 0)
			{
				b = rand() % 52;
			}

			arr1[j] = arr[b];
			if (arr1[j] >= 1 && arr1[j] <= 13)
			{
				S[i]++;
			}
			else if (arr1[j] > 13 && arr1[j] <= 26)
			{
				H[i]++;
			}
			else if (arr1[j] > 26 && arr1[j] <= 39)
			{
				D[i]++;
			}
			else
			{
				C[i]++;
			}
			arr[b] = 0;

		}
	}

	

	cout << "A的黑桃数：" << S[0] << " " << "A的红桃数：" << H[0] << endl;
	cout << "A的方块数：" << D[0] << " " << "A的梅花数：" << C[0] << endl;
	cout << "B的黑桃数：" << S[1] << " " << "B的红桃数：" << H[1] << endl;
	cout << "B的方块数：" << D[1] << " " << "B的梅花数：" << C[1] << endl;
	cout << "C的黑桃数：" << S[2] << " " << "C的红桃数：" << H[2] << endl;
	cout << "C的方块数：" << D[2] << " " << "C的梅花数：" << C[2] << endl;
	cout << "D的黑桃数：" << S[3] << " " << "D的红桃数：" << H[3] << endl;
	cout << "D的方块数：" << D[3] << " " << "D的梅花数：" << C[3] << endl;



	system("pause");
	return 0;
}
