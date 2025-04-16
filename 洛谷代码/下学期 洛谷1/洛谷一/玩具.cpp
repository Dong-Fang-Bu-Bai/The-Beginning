#include<iostream>
using namespace std;
struct wjxr 
{
    string name;
    bool b;
}a[100005];//创建一个结构体数组

int main() 
{
    int n, m, h = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)//依次读取数据
    {
        cin >> a[i].b >> a[i].name;
    }
    while (m--) //依次处理位置
    {
        int ai, si;
        cin >> ai >> si;
        if (a[h].b == ai) 
        {
            h -= si;
            if (h < 0)
            {
                h += n*(( - h)/n+1);
            }
        }
        else 
        {
            h = h + si;
            if (h >= n)
            {
                h -= n * (h/n);
            }
        }
    }
    cout << a[h].name << endl;

    system("pause");
    return 0;
}