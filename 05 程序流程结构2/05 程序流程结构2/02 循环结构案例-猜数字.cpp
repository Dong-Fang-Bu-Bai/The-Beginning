#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main2()
{
	//添加随机数种子	作用：利用当前系统时间生成随机数，防止一致
	//srand(time(0));这样也可以，而且现在也不需要加<cstdlib>这个库,以及<ctime>这个库
	srand((unsigned int)time(NULL));
	//1.系统生成随机数
	//rand()%100	//生成0~99随机数
	int num = rand() % 100 + 1;
	//cout << num << endl;//不能输出结果
	//2.玩家进行猜测
	int val = 0;//玩家输入的数据
	int	q = 0;//玩家尝试次数
	while (1)
	{
		cin >> val;
		//3.判断玩家的猜测
		if (val > num&&q<=4)
		{
			cout << "猜测过大" << endl;
			q++;
		}
		else if (val < num&&q<=4)
		{
			cout << "猜测过小" << endl;
			q++;
		}
		else if(val==num&&q<=5)
		{
			cout << "恭喜您猜对了" << endl;
			cout << "你尝试的次数为:" << q + 1 << endl;
			//猜对	退出游戏
			break;//以该关键字退出循环
		}
		else if(q>4&&q!=num)
		{
			cout << "抱歉，您失败了" << endl;
			cout << num << endl;
			break;
		}
	}
	//猜对	退出游戏
	//猜错	提示猜的结果	过大或过小	重新返回第2步
	system("pause");
	return 0;



}