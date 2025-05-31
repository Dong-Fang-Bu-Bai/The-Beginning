
//实现复数运算

//#include<iostream>
//#include<string>
//#include<iomanip>
//
//using namespace std;
//
//class MyInput 
//{
//private:
//	string data[10];
//
//public:
//	MyInput(string in)  // 把输入的字符串按逗号分成单独的字符串
//	{
//		int k = 0;
//		string temp = "";
//		for (int i = 0; i < in.size();i++)
//		{
//			if (in[i] == ',')
//			{
//				data[k++] = temp;
//				temp = "";
//			}
//			else
//			{
//				temp += in[i];
//			}
//
//			data[k] = temp;
//		}
//	}
//
//	string GetInput(int index)
//	{
//		return data[index];
//	}
//};
//
////复数
//class Complex
//{
//
//private:
//	double real, imag;
//public:
//
//	Complex(double _real = 0, double _image = 0)//含有默认参数的构造函数
//	{
//		real = _real;   imag = _image;
//	}
//
//	//加
//	void add(Complex b)
//	{
//		real += b.real;
//		imag += b.imag;
//	}
//
//	//减
//	void subtract(Complex b)
//	{
//		real -= b.real;
//		imag -= b.imag;
//	}
//
//	//乘
//	void mul(Complex b)
//	{
//		double x1 = real * b.real - imag * b.imag;
//		double x2 = real * b.imag + imag * b.real;
//		real = x1;
//		imag = x2;
//	}
//
//	//除
//	void div(Complex b)
//	{
//		Complex x(real, imag);
//		x.mul(Complex(b.real, -b.imag));
//		real = x.real / b.length();
//		imag = x.imag / b.length();
//	}
//
//	double length() //计算复数的模
//	{
//		return real * real + imag * imag;
//	}
//
//	void Display() const
//	{
//		cout <<fixed << setprecision(2) << "(" << real << "," << imag << ")" << endl;
//	}
//};
//
//int main() 
//{
//
//	string s;
//
//	getline(cin, s);
//	MyInput in(s);
//
//	Complex x(stof(in.GetInput(0)), stof(in.GetInput(1)));
//
//	while (getline(cin, s))
//	{
//		if (s.empty())
//		{
//			break;
//		}
//		in = MyInput(s);
//		Complex y(stof(in.GetInput(1)), stof(in.GetInput(2)));
//		if (in.GetInput(0) == "add")
//			x.add(y);
//		else if (in.GetInput(0) == "sub")
//			x.subtract(y);
//		else if (in.GetInput(0) == "mul")
//			x.mul(y);
//		else if (in.GetInput(0) == "div")
//			x.div(y);
//	}
//	x.Display();
//
//	system("pause");
//	return 0;
//}