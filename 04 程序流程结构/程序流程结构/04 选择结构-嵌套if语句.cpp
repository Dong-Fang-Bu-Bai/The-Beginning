#include<iostream>
using namespace std;

 int main4()
{


	//1.提示输入高考分数
	int	score = 0;
	cout << "请输入高考考试分数：" << endl;
	cin >> score;
	//2.显示高考分数
	cout << "您输入的分数为：" << score << endl;

	//3.判断
	//如果大于600	一本
		//大于700	北大
		// 大于650	清华
		// 其余		人大
	//如果大于500	二本
	//如果大于400	三本
	//其余情况	未考上本科
	if (score>600)
	{
		cout << "恭喜您考入一本大学" << endl;
		if (score>700)
		{
			cout << "恭喜您考入北大" << endl;
		}
		else if (score>650)
		{
			cout << "恭喜您考入清华" << endl;
		}
		else
		{
			cout << "恭喜您考入人大" << endl;
		}
	}
	else if(score>500)
	{
		cout << "恭喜您考入二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "恭喜您考入三本大学" << endl;
	}
	else
	{
		cout << "恭喜您未考上大学" << endl;
	}





	system("pause");
	return 0;


}