//先把以下程序的no改成本人的学号，然后运行程序，用十六进制编辑软件，打开stu.dat，
//解释stu.dat的文件内容(文件长度是如何计算的，文件中每个字节代表什么含义）。

#include <iostream>
#include <fstream> 

using namespace std;
int main() 
{
    long long no = 202430551135; //改成本人学号
    double x;

    fstream outCredit("stu.dat", ios::out | ios::binary);
    if (!outCredit)
    {
        cerr << "File could not be opened." << endl;
        exit(1);
    }

    outCredit.write(reinterpret_cast<const char*>(&no), sizeof(no));
    x = no / 1000.0;
    outCredit.write(reinterpret_cast<const char*>(&x), sizeof(x));
    x = no / 10000.0;
    outCredit.write(reinterpret_cast<const char*>(&x), sizeof(x));

    outCredit.close();
}