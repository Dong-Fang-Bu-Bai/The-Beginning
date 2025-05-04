#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
string str[10001];

ll a[10001];

ll mod = 1e9 + 9;//模数，反映哈希值范围

ll b = 99991;//基数base

ll hashn(string str) 
{
	ll hash = 0;
	for (int i = 0; i < str.size(); i++) 
	{
		hash = (hash * b + (ll)str[i]) % mod;//
	}
	return hash;
}

int main() 
{
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> str[i];
		a[i] = hashn(str[i]);
	}

	sort(a, a + n + 1);

	
	ll count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1]) {
			count++;
		}
	}
	cout << count << endl;

	system("pause");
	return 0;
}