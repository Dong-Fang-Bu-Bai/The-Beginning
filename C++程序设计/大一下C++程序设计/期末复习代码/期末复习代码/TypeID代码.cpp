//#include<iostream>
//#include<typeinfo>
//#include<vector>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void speak() = 0;
//
//	//int a = 0;
//};
//
//class A :public Base
//{
//public:
//	void speak()override
//	{
//		cout << "A is here" << endl;
//	}
//};
//
//class B :public Base
//{
//public:
//	void speak()override
//	{
//		cout << "B is here" << endl;
//	}
//};
//
//class C :public Base
//{
//public:
//	void speak()override
//	{
//		cout << "C is here" << endl;
//	}
//};
//
//
//int main()
//{
//
//	vector<Base*>Basevector(3);
//	Basevector[0] = new A;
//	Basevector[1] = new B;
//	Basevector[2] = new C;
//
//	for (auto pointer : Basevector)
//	{
//		pointer->speak();
//		cout << typeid(pointer).name() << endl;
//		cout << typeid(pointer).raw_name() << endl;
//		cout << typeid(pointer).hash_code() << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}