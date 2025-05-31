//
////对MyString类的完善
//
////重点：确保实现new的对象被delete，防止内存泄漏
//
////重点：确保重载=赋值函数，避免浅复制导致的指针地址问题
//
////评分标准：SetNewString函数没有delete扣10分，没有重载=扣20分
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstring>
//#include<iomanip>
//#include<iostream>
//using namespace std;
//
//class MyString
//{
//private:
//    char* p;
//public:
//
//    friend ostream& operator<<(ostream&, const MyString&);
//
//    //默认构造函数
//    MyString() : p(NULL)
//    {
//
//    }
//
//    //带参数的初始化的构造函数
//    MyString(const char* s)
//    {
//        p = new char[strlen(s) + 1];
//        strcpy(p, s);
//    }
//
//   //对对象字符数组进行重新赋值的函数
//    //要先delete再进行new
//    void SetNewString(const char* s)
//    {
//        delete[] p;
//        p = new char[strlen(s) + 1];
//        strcpy(p, s);
//    }
//
//    //复制构造函数
//    MyString(const MyString& s)
//    {
//        p = new char[strlen(s.p) + 1];
//        strcpy(p, s.p);
//    }
//
//    MyString operator+(const MyString& s)
//    {
//        char* temp = new char[strlen(p) + 1];
//        strcpy(temp, p);
//        strcat(temp + strlen(p), s.p);
//        delete[] p;
//        p = new char[strlen(temp) + 1];
//        strcpy(p, temp);
//        return *this;
//    }
//
//    MyString operator=(const MyString& s)
//    {
//        if (this == &s)  //避免自己给自己赋值
//            return *this;
//
//        delete[] p;
//        p = new char[strlen(s.p) + 1];
//        strcpy(p, s.p);
//        return *this;
//    }
//
//    ~MyString()
//    {
//        delete[] p;
//    }
//};
//
//ostream& operator <<(ostream& output, const MyString& s) 
//{
//    output << s.p;
//    return output;
//}
//
//
//int main()
//{
//    MyString s1("First"), s2("Second");
//
//    MyString s3 = s1;
//
//    MyString s4;
//
//    s4 = s2;
//
//    s3.SetNewString("long string");
//    s4.SetNewString("scut");
//
//    cout << s1 << "  " << s3 << endl;   //s1,s3应该显示不一样的内容
//
//    cout << s2 << "  " << s4 << endl;   //s2,s4应该显示不一样的内容
//
//    MyString s5 = s3 + s4;
//
//    cout << s5 << endl;  //应该显示s3,s4合并在一起的内容
//
//    system("pause");
//    return 0;
//}