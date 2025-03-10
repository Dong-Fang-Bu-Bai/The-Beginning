//【3】在图中的九个点上, 空出中间的点, 其余的点上任意填入数字1到8; 1的位置固定不动,
// 然后移动其余的数字, 使1到8顺时针从小到大排列.移动的规律是:只能将数字沿线移向空白的点。
// 请编程显示数字移动过程。


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void Graph(char rect[9]);

int main3()//main函数
{ 
    int i, j, k;
    char Cyc[9] = { 0 };//Cyc[0]到Cyc[7]用于保存8个数，Cyc[8]为空白区
    //注意，Cyc是一个字符型数组，现在存入的都只是ASCII码
    int CurNode = 9, Temp;
    srand((unsigned int)time(NULL));

    for (i = 0; i < 8; i++)//随机产生序列 
    {
        Cyc[i] = rand() % 8+ 1; //在前8个位置存入1~8（ASCII代表的数值）
        if (CurNode == 9 && Cyc[i] == 1)
            CurNode = i;//记录数字1的位置 
        for (j = 0; j < 8; j++)
        {
            if (Cyc[i] == Cyc[j] && i != j)
            {
                i--;
                break;
            }
        }
    }
    cout<<"原始状态:";
    cout << endl;

    Graph(Cyc);//调用Graph函数，来展示初始状态的Cyc数组（以 3 * 3 的形式）

    cout<<"开始移动:";
    cout << endl;
    for (i = 2; i <= 8; i++)//下一个要找的数，经过计算，最多只要操作7次
    {
        for (j = 0; j < 8; j++)//扫描找数，相当于遍历数组（除了最后一个）
        {
            if (Cyc[j] == i)//找到了下一个数所在的位置
            {
                Temp = (CurNode + 1) % 8;//意思就是，按照“顺时针”排序，此时的Cyc[temp]应该为i
                
                if (i != Cyc[Temp])//如果位置正确就不用再移，此时位置不正确，进行移动
                {
                    Cyc[8] = i;//移入中心区（空格区）
                    Cyc[j] = 0; //移入中心区（空格区）

                    Graph(Cyc);//向用户展示此时的布局（重新出现空格）

                    
                    //在已经确定位置不对的情况下，temp（本应该在的地方）和j（实际在的地方）肯定不一样
                    //下面就进行一次顺时针轮转

                    if (Temp > j) //如果不小心j的下标小于temp，我们将j加上8，使其始终在temp之前（相当于绕了一圈）
                        j += 8;
                        
                    for (k = j; k > Temp; k--)
                    {
                        Cyc[k % 8] = Cyc[(k - 1) % 8];//顺时针轮转(只需要在temp和j之间的位置即可)
                    }

                    Cyc[Temp] = 0;

                    Graph(Cyc);//展示布局

                    
                   
                    Cyc[Temp] = Cyc[8];//从中心区移出
                    Cyc[8] = 0;       //从中心区移出 

                    Graph(Cyc);//展示布局（重新出现空格）


                }
                
                CurNode = Temp;//记录当前位置，就是说，此时把排好序的最后一个数的位置作为新的原点，进行下一次排序

                break;
            }
        }
    }

    cout << "移动完成!";
    cout << endl;
    system("pause");
    return 1;
}


void Graph(char rect[9])
{ 
    int i; char buf[9]; 
    for(i=0;i<9;i++)
    {
        if(rect[i]) //如果这个位置的元素数值不是0（将字符型进行强制类型转换）
            buf[i]=rect[i]+48; //将每个位置的ASCII码加上48，真正成为1~8数字的字符
        else buf[i]=' '; //将唯一的一个编码为0的元素赋为空格字符
    } 

    cout << buf[0]<<"-" << buf[1] << "-" << buf[2];
    cout << endl;
    cout << buf[7]<< "-"<< buf[8] << "-" << buf[3];
    cout << endl;
    cout << buf[6]<< "-"<< buf[5] << "-" << buf[4];
    cout << endl;
    cout << endl;

}







    //int a[] = { 0, 1, 2, 5, 8, 7, 6, 3 }; // 指针数组，记录环中元素的连接关系
    //int b = { 0, 1, 2, 5, 8, 7, 6, 3 }; // 表示3x3矩阵，中间的元素为空格
    //int c; // 确定1所在的位置后，对环进行调整的指针数组
    //int count = 0; // 数字移动步数计数器

    //void print(int arr)
    //{
    //    for (int i = 0; i < 9; i++) {
    //        printf("%d ", arr[i]);
    //    }
    //    printf("\n");
    //}

    //int main() {
    //    int i, j, k, t;
    //    for (i = 2; i <= 8; i++) { // 从数字2开始调整各个数字的位置
    //        int pos = getdata(a, i); // 查找数值i的坐标
    //        int row = pos / 10; // i的坐标行
    //        int col = pos % 10; // i的坐标列
    //    a‌:ml - citation{ ref = "1" data = "citationList" } = i; // 将数字i移到中间的空格位置
    //        a[row][col] = 0; // 将原有位置空出
    //        pos = get(a, row, col, -1); // 查找数值i的前一个数的位置
    //        while (a[pos / 10][pos % 10] != i - 1) { // 如果前一个数不是i-1，则继续移动
    //            a[row][col] = a[pos / 10][pos % 10]; // 将前一个数移到中间的空格位置
    //            pos = get(a, row, col, -1); // 继续查找前一个数的位置
    //        }
    //        a[row][col] = i; // 将i移到正确的位置
    //        count++; // 移动步数加1
    //    }
    //    print(a); // 打印最终的矩阵状态
    //    printf("移动次数：%d\n", count); // 打印移动次数
    //    system("pause");
    //    return 0;
    //}




