#include<iostream>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	if (a == "0" || b == "0")
	{
		cout << 0;
		return 0;
	}
	int aans = 0, bans = 0;
	for (char& c : a)
	{
		aans += c - '0';
	}
	for (char& c : b)
	{
		bans += c - '0';
	}
	int ans = (aans % 9 * bans % 9) % 9;
	if (ans == 0)
	{
		cout << 9;
	}
	else
	{
		cout << ans;
	}
	cout << endl;
	
	//cout << (char)('a'+2 )<< endl;


	/*char c;
	cin >> c;
	if (c > 64 && c < 98)
	{
		cout << "ด๓ะด";
	}
	else
	{
		cout << "ะกะด";
	}*/

	system("pause");
	return 0;
}