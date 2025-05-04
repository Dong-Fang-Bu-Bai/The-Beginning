#include<iostream> 
#include<algorithm>
using namespace std;

struct people 
{
    string name, zw, nzw;//名字、旧职位、新职位
    long long bg, dj, xh;//帮贡、等级、序号
}a[100005];//每个人的信息

int zdj1(string a) {//将职位转换从而进行比较的函数
    if (a == "BangZhu") return 1;
    if (a == "FuBangZhu") return 2;
    if (a == "HuFa") return 3;
    if (a == "ZhangLao") return 4;
    if (a == "TangZhu") return 5;
    if (a == "JingYing") return 6;
    if (a == "BangZhong") return 7;
}

string zdj2(int a) 
{
    //将顺序转换为职位的函数	
    if (a == 1) return "BangZhu";
    if (a <= 3) return "FuBangZhu";
    if (a <= 5) return "HuFa";
    if (a <= 9) return "ZhangLao";
    if (a <= 16) return "TangZhu";
    if (a <= 41) return "JingYing";
    return "BangZhong";
}

bool cmp1(people a, people b) 
{
    if (a.bg != b.bg) 
        return a.bg > b.bg;//不等时按帮贡排序
    else return a.xh < b.xh;//相等时按序号排序
}//排序函数1

bool cmp2(people a, people b) 
{
    int a1 = zdj1(a.nzw), b1 = zdj1(b.nzw);

    if (a1 != b1) 
        return a1 < b1;//先是职位
    else 
    {
        if (a.dj != b.dj) 
            return a.dj > b.dj;//再是等级
        else return a.xh < b.xh;//最后序号
    }
}//排序函数2

int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].name >> a[i].zw >> a[i].bg >> a[i].dj;
        a[i].xh = i;
    }//读入并存储序号

    sort(a + 4, a + 1 + n, cmp1);//注意要从4开始排序

    for (int i = 1; i <= n; i++) 
    {
        a[i].nzw = zdj2(i);//存入新职位
    }

    sort(a + 1, a + 1 + n, cmp2);//第二次排序

    for (int i = 1; i <= n; i++) 
    {
        cout << a[i].name << ' ' << a[i].nzw << ' ' << a[i].dj << endl;//输出，记得换行
    }

    system("pause");
    return 0;
}


//sort函数的底层逻辑和使用方法
//底层逻辑
//C++标准库中的sort函数通常采用一种混合排序算法，结合了快速排序、堆排序和插入排序的优点：
//
//​​快速排序​​：作为主要排序算法，平均时间复杂度为O(n log n)
//​​堆排序​​：当递归深度过大时使用，保证最坏情况下时间复杂度为O(n log n)
//​​插入排序​​：对小规模数据(通常n ≤ 16)使用，因为在小数据量时插入排序更高效
//这种混合策略被称为"内省排序"(Introsort)，由David Musser在1997年提出。

//#include <algorithm>
//using namespace std;
//
//sort(start, end);
//sort(start, end, compare_function);
// 
//start：指向要排序的第一个元素的指针 / 迭代器
//end：指向要排序的最后一个元素的下一个位置的指针 / 迭代器
//compare_function：可选的自定义比较函数

//注意事项
//​​范围​​：sort排序的范围是左闭右开区间[start, end)  重要！
//​​稳定性​​：sort不是稳定排序（相等元素的相对顺序可能改变），如需稳定排序应使用stable_sort
//​​复杂度​​：平均和最坏情况下都是O(n log n)
//​​自定义类型​​：对自定义类型排序时，必须提供比较函数或重载 < 运算符