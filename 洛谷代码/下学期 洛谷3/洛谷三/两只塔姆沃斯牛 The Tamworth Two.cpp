//思路：首先读取10 x 10的地图，创建一个二维数组（先行后列），然后依次读取10行输入
//其中，F和C代表猎人和猎物， . 代表空白 ， * 代表障碍物 
//基本逻辑为：F和C每分钟移动一格，具有属性direction，分别为Left、Right、Up、Down，以及位置（x,y）
//在每一次移动前，检测”前方”状态，若为空白则向对应方向移动一格，若为障碍物，或者当前已处于边界，则
//在这一次移动中仅按顺时针方向旋转90度，并且不移动；每一次处理，Time均加一
//在每一次移动后，检测F和C是否重合，若是则输出当前Time值，考虑是否会出现无法抓捕的情况？
//如果F或者C在一开始就被困住了，那就不可能抓到，
//如果在某一次移动后，发现两者的位置和方向均与之前某一次相同，那表明出现循环，无法抓捕
//可以先不考虑无法抓捕的情况，先处理有解情况！

#include<iostream>
using namespace std;
class F
{

public:
	void getIniPos();
	void move();

	int& getX()
	{
		return x;
	}

	int& getY()
	{
		return y;
	}

	bool isBarrier();

private:

	int x = 0;
	int y = 0;
	string Direction = "Up";
};

class C
{
public:
	void getIniPos();
	void move();

	int& getX()
	{
		return x;
	}

	int& getY()
	{
		return y;
	}

	bool isBarrier();

private:

	int x = 0;
	int y = 0;
	string Direction = "Up";
};

char grid[10][10];


int main()
{
	//思路：首先读取10 x 10的地图，创建一个二维数组（先行后列），然后依次读取10行输入
	//其中，F和C代表猎人和猎物， . 代表空白 ， * 代表障碍物 

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> grid[i][j];//（先行后列）
		}
	}

	//创建双方
	F man;
	C cow;

	//获取初始位置
	man.getIniPos();
	cow.getIniPos();

	//开始追捕
	int count = 0;

	while (1)
	{
		man.move();
		cow.move();

		count++;

		if (man.getX() == cow.getX() && man.getY() == cow.getY())
		{
			break;
		}

		if (count > 1000)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}

//初始位置函数
void F::getIniPos()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j]=='F')
			{
				this->x = i;
				this->y = j;
			}
		}
	}

	
}

void C::getIniPos()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == 'C')
			{
				this->x = i;
				this->y = j;
			}
		}
	}

	
}


//基本逻辑为：F和C每分钟移动一格，具有属性direction，分别为Left、Right、Up、Down，以及位置（x,y）
//在每一次移动前，检测”前方”状态，若为空白则向对应方向移动一格，若为障碍物，或者当前已处于边界，则
//在这一次移动中仅按顺时针方向旋转90度，并且不移动；每一次处理，Time均加一

//碰撞函数（边界）
bool F::isBarrier()
{
	//首先排除边界问题
	if ((this->x == 0 && this->Direction == "Up") || (this->y == 0 && this->Direction == "Left")
		|| (this->x == 9 && this->Direction == "Down") || (this->y == 9 && this->Direction == "Right"))
	{
		return true;
	}
	else if (this->Direction == "Up" && grid[this->x - 1][this->y] == '*')//然后再判断前方状态，防止越界
	{
		return true;
	}
	else if (this->Direction == "Down" && grid[this->x + 1][this->y] == '*')
	{
		return true;
	}
	else if (this->Direction == "Left" && grid[this->x][this->y-1] == '*')
	{
		return true;
	}
	else if (this->Direction == "Right" && grid[this->x][this->y+1] == '*')
	{
		return true;
	}

	return false;
}

bool C::isBarrier()
{
	//首先排除边界问题
	if ((this->x == 0&& this->Direction == "Up")|| (this->y == 0&& this->Direction == "Left")
	|| (this->x == 9&& this->Direction == "Down") || (this->y == 9&& this->Direction == "Right"))
	{
		return true;
	}
	else if (this->Direction == "Up" && grid[this->x - 1][this->y] == '*')//然后再判断前方状态，防止越界
	{
		return true;
	}
	else if (this->Direction == "Down" && grid[this->x + 1][this->y] == '*')
	{
		return true;
	}
	else if (this->Direction == "Left" && grid[this->x][this->y - 1] == '*')
	{
		return true;
	}
	else if (this->Direction == "Right" && grid[this->x][this->y + 1] == '*')
	{
		return true;
	}

	return false;
}



//移动函数
void F::move()
{
	if (this->isBarrier())
	{
		//顺时针转向
		if (this->Direction == "Up")
		{
			this->Direction = "Right";
		}
		else if (this->Direction == "Down")
		{
			this->Direction = "Left";
		}
		else if (this->Direction == "Left")
		{
			this->Direction = "Up";
		}
		else if (this->Direction == "Right")
		{
			this->Direction = "Down";
		}
	}
	else
	{
		//移动
		if (this->Direction == "Up")
		{
			this->x--;
		}
		else if (this->Direction == "Down")
		{
			this->x++;
		}
		else if (this->Direction == "Left")
		{
			this->y--;
		}
		else if (this->Direction == "Right")
		{
			this->y++;
		}
	}

	
}

void C::move()
{
	if (this->isBarrier())
	{
		//移动
		if (this->Direction == "Up")
		{
			this->Direction = "Right";
		}
		else if (this->Direction == "Down")
		{
			this->Direction = "Left";
		}
		else if (this->Direction == "Left")
		{
			this->Direction = "Up";
		}
		else if (this->Direction == "Right")
		{
			this->Direction = "Down";
		}
	}
	else
	{
		//移动
		if (this->Direction == "Up")
		{
			this->x--;
		}
		else if (this->Direction == "Down")
		{
			this->x++;
		}
		else if (this->Direction == "Left")
		{
			this->y--;
		}
		else if (this->Direction == "Right")
		{
			this->y++;
		}
	}
	
}
