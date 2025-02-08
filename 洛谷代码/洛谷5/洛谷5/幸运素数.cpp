#include<iostream>
#include<math.h>
using namespace std;


bool isPrime2(int a)
{
	if (a == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i * i <= a; i++)
		{
			if (a % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

bool check(int p)
{
	while (p)
	{
		if (!isPrime2(p))
		{
			return 0;
		}
		else
		{
			p = p / 10;
		}
	}
	return 1;
}


int main4()
{

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n;++i)
	{
		if (check(i))
		{
			cout << i << endl;
		}
		/*if (i <= 10)
		{
			if (isPrime2(i))
			{
				cout << i << endl;
			}
		}
		else
		{
			while (q > 10)
			{
					if (isPrime2(q))
					{
						q = q/ 10;
						k = k + 1;
					}
					else
					{
						break;
					}
				
			}
			
			if (q == 1)
			{

			}
			else if (q * pow(10, k) <p && p <=(q + 1) * pow(10, k))
			{
				cout << p << endl;
			}
			
		}*/

	}


	system("pause");
	return 0;
}



//#include <iostream>
//
//bool isPrime(int x) { // 判断是否为质数
//	if (x < 2) return false;
//	for (int mod = 2; mod * mod <= x; ++mod)
//		if (!(x % mod)) return false;
//	return true;
//}
//
//bool check(int x) {
//	while (x) {
//		if (!isPrime(x)) return false;
//		x /= 10; // 按位分解，这部操作相当于去掉一个数的最后一位
//	}
//	return true;
//}
//
//int main() {
//	int m, n; std::cin >> m >> n;
//	for (int i = m; i <= n; ++i)
//		if (check(i)) std::cout << i << '\n';
//	return 0;
//}