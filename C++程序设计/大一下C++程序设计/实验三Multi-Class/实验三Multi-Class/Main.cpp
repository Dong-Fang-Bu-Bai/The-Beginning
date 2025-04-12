#include "Library.h"
#include <iostream>

using namespace std;

int main() 
{
    Library library;

    // 从输入数据初始化图书馆
    library.initializeFromInput();


    // 显示所有要求的信息
    library.displayBookStats();
    library.displayBorrowerStats();


    system("pause");
    return 0;
}