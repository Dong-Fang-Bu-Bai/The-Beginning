////Vector向量类的运算实现
//
//#include<iostream>
//
//using namespace std; 
//
//class vector 
//{
//private:
//
//	int size;
//	double* container;
//
//public:
//	vector(int);//constructor
//	vector(const vector&);//copy constructor
//	~vector();//destructor
//	friend vector operator+(vector& a, vector& b);
//	friend vector operator-(vector& a, vector& b);
//	friend double operator*(vector& a, vector& b);
//	friend ostream& operator<<(ostream& out, vector& b);
//	friend istream& operator>>(istream& in, vector& b);
//	double& operator[](int i);
//	//vector operator=(vector b);   //错误的赋值运算符重载 
//	vector& operator=(const vector& b);
//};
//
////默认构造函数
//vector::vector(int s = 0) 
//{
//	size = s;
//	if (size > 0)	container = new double[size];
//}
//
////复制构造函数
//vector::vector(const vector& ori) 
//{
//	size = ori.size;
//	container = new double[size];
//	for (int i = 0; i < size; i++) container[i] = ori.container[i];
//}
//
//vector::~vector() 
//{
//	size = 0;
//	delete[] container;
//	container = nullptr;
//}
//
//double& vector:: operator[](int i) 
//{
//	if (i > size || i < 0) throw "Invalid Index.";
//	return container[i];
//}
//
//vector& vector::operator=(const vector& b) 
//{
//	size = b.size;
//	delete[] container;
//	container = new double[size];
//	for (int i = 0; i < size; i++) 
//		container[i] = b.container[i];
//	return *this;//返回*this可以支持链式操作
//}
//
///*错误的赋值运算符重载
//* //错误点 ：1.作为vector的成员函数，该函数没有使用this指针进行对象操作，而是创建了一个链式对象c，
//不仅无法实现对实际对象的操作，而且返回临时变量的操作是非法的！
//vector vector::operator=(vector b)  
//{
//	vector c(b.size);
//	c.container = new double[b.size];
//	for (int i = 0; i < size; i++) c.container[i] = b.container[i];
//	return c;
//	}
//
//*/
//
//vector operator+(vector& a, vector& b) 
//{
//	if (a.size != b.size) throw "The sizes of vectors do not match.";
//	vector c(a.size);
//	for (int i = 0; i < c.size; i++) {
//		c[i] = a[i] + b[i];
//	}
//	return c;
//}
//
//vector operator-(vector& a, vector& b) 
//{
//	if (a.size != b.size) throw "The sizes of vectors do not match.";
//	vector c(a.size);
//	for (int i = 0; i < c.size; i++) 
//	{
//		c[i] = a[i] - b[i];
//	}
//	return c;
//}
//
//double operator*(vector& a, vector& b) 
//{
//	if (a.size != b.size) throw "The sizes of vectors do not match.";
//	double sum = 0;
//	for (int i = 0; i < a.size; i++) 
//	{
//		sum += a[i] * b[i];
//	}
//	return sum;
//}
//
//ostream& operator<<(ostream& out, vector& b) 
//{
//	out << "(";
//	for (int i = 0; i < b.size - 1; i++) out << b[i] << ",";
//	out << b[b.size - 1] << ")";
//	return out;
//}
//
//istream& operator>>(istream& in, vector& b) 
//{
//	for (int i = 0; i < b.size; i++) 
//		in >> b[i];
//	return in;
//}
//
//
//int main() 
//{
//	int size1, size2;
//	cout << "输入两次向量长度：";
//	cin >> size1 >> size2;
//
//	try {
//		vector a(size1), b(size2);
//		cout << "输入向量1：";
//		cin >> a;
//		cout << "输入向量2：";
//		cin >> b;
//		vector plus = a + b;
//		vector plus1(a);
//		plus1 = a + b;
//		vector minus = a - b;
//		double product = a * b;
//		//cout << "a+b=" << a+b << endl;发生错误：没有匹配的重载，可以把<<的参数改为传值
//		cout << "a+b=" << plus << endl;
//		cout << "a-b=" << minus << endl;
//		cout << "a·b=" << product << endl;
//
//		cout << "plus1=a+b:" << plus1 << endl;
//	}
//	catch (const char* err) 
//	{
//		cout << "运行发生错误，原因为：";
//		cerr << err;
//	}
//
//	system("pause");
//	return 0;
//}