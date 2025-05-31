
//实现有理数运算

//#include<iostream>
//#include<string>
//#include<iomanip>
//using namespace std; 
//
////处理输入
//class MyInput 
//{
//private:
//	string data[10];
//
//public:
//	MyInput(string in)  // 把输入的字符串按逗号分成单独的字符串
//	{
//		int j = 0;
//		string temp = "";
//		for (int i = 0; i < in.size(); i++)
//		{
//			if (in[i] == ',')
//			{
//				data[j++] = temp;
//				temp = "";
//			}
//			else
//				temp = temp + in[i];
//		}
//		data[j] = temp;
//	}
//	string GetInput(int index)
//	{
//		return data[index];
//	}
//};
//
//
////有理数类
//class Fraction 
//{
//private:
//	int numerator, denominator;  //分子，分母
//	friend Fraction operator * (const Fraction&, const Fraction&);
//	friend Fraction operator / (const Fraction&, const Fraction&);
//	friend ostream& operator <<(ostream&, const Fraction&);
//public:
//	Fraction(double _numerator = 1, double _denominator = 1)
//	{
//		//归整一下，统一把分子当负，分母当正
//		if (_numerator * _denominator < 0)
//			numerator = -abs(_numerator), denominator = abs(_denominator);
//		else
//			numerator = abs(_numerator), denominator = abs(_denominator);
//	}
//
//	Fraction operator +(const Fraction& b)
//	{
//		Fraction sum;
//		sum.numerator = numerator * b.denominator + denominator * b.numerator;
//		sum.denominator = denominator * b.denominator;
//		sum.Simplification();
//		return sum;
//	}
//
//	Fraction operator - (const Fraction b)
//	{
//		Fraction diff;
//		diff.numerator = numerator * b.denominator - denominator * b.numerator;
//		diff.denominator = denominator * b.denominator;
//		diff.Simplification();
//		return diff;
//	}
//
//
//	void Simplification() // 化为最简分数
//	{
//		//找最大公约数
//		int a = abs(numerator), b = abs(denominator);
//		unsigned int temp;
//		while (b > 0)
//		{
//			temp = a % b;
//			a = b;
//			b = temp;
//		}
//		numerator /= a;
//		denominator /= a;
//	}
//	void Display() const
//	{
//		cout << numerator;
//		if (denominator != 1)
//			cout << "/" << denominator << endl;
//	}
//};
//
////三个全局函数重载乘除以及插入运算符
//
//Fraction operator * (const Fraction& a, const Fraction& b) 
//{
//	Fraction mul;
//
//	mul.numerator = a.numerator * b.numerator;
//	mul.denominator = a.denominator * b.denominator;
//	mul.Simplification();
//	return mul;
//}
//
//Fraction operator / (const Fraction& a, const Fraction& b) 
//{
//	Fraction div;
//
//	div.numerator = a.numerator * b.denominator;
//	div.denominator = a.denominator * b.numerator;
//	div.Simplification();
//	return div;
//}
//
//ostream& operator <<(ostream& output, const Fraction& x) 
//{
//	output << x.numerator;
//	if (x.denominator != 1)
//		output << "/" << x.denominator;
//	return output;
//}
//
//int main() 
//{
//	//freopen("s:\\temp\\12.txt", "r", stdin);
//	string s;
//
//	getline(cin, s);
//	MyInput in(s);
//
//	Fraction x(stoi(in.GetInput(0)), stoi(in.GetInput(1)));
//
//
//	while (getline(cin, s))
//	{
//		if (s.empty())
//		{
//			break;
//		}
//		in = MyInput(s);
//		Fraction y(stoi(in.GetInput(1)), stoi(in.GetInput(2)));
//		if (in.GetInput(0) == "add")
//			x = x + y;//x.add(y);
//		else if (in.GetInput(0) == "sub")
//			x = x - y;
//		else if (in.GetInput(0) == "mul")
//			x = x * y;
//		else if (in.GetInput(0) == "div")
//			x = x / y;
//	}
//
//	cout << x << endl;
//}