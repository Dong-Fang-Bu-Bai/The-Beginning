/****************************************************
*   Functions to solve mazes.                       *
*                                                   *
*   Datafile must still contain size as first data. *
*   数据文件必须仍然包含大小作为第一个数据。        *
*   Four functions are only stubs.                  * 
****************************************************/

#include <iostream>
#include <fstream>
#include "Maze.h"
using namespace std;

//	The following enumerated type indicates directions within the maze
//  下面的枚举类型指示迷宫中的方向
enum Direction {DOWN, LEFT, UP, RIGHT};

//	This struct is used for locations within the maze
//这个结构体用于迷宫中的位置

struct Position
{
	int H, V;
};

//	The maze itself is indicated by # for the walls
//	All other locations in the maze can be any other character
//	Global variables defining the maze to be solved
//迷宫本身用#表示墙
//迷宫中的其他位置可以是任何其他角色
//定义要解决的迷宫的全局变量
char *maze;//使用指向一维数组的指针来动态存储迷宫文件
int mazeWidth, mazeHeight;//定义长宽
int *posi;//使用指向一维数组的指针来动态存储所在位置
int i=0;//初始化i为0，用于记录每一步所在位置
//	These functions provide access to the maze
//	as well as provide manipulation of direction
//	of motion and maze location
//	See implementation for details
//这些函数提供对迷宫的访问
//以及提供方向操作
//运动和迷宫位置
//详情见实现

void FindEntrance(int&);
bool AtExit(int);
void ReportPosition(int);
void WheresRight(int,Direction,int&);
bool Wall(int);
void TurnRight(Direction&);
void MoveForward(int&,Direction);
void WheresAhead(int,Direction,int&);
void TurnLeft(Direction&);

//	This function loads the maze from the specified file
//	returning the maze and its dimensions
//	The height of the maze is not actually used anywhere but here
//这个函数从指定的文件中加载迷宫
//返回迷宫及其维度
//除了这里，迷宫的高度在其他地方都没有使用

bool LoadMaze(const char fname[])
{
	ifstream ifs(fname);
	
	if (ifs.good()) //good()：返回一个bool值，表示流的状态是否良好。
		            //如果流状态没有出错，并且没有到达文件末尾，则返回true，否则返回false。
	{
		ifs >> mazeWidth >> mazeHeight;//读入迷宫的宽和高
		maze = new char[mazeWidth * mazeHeight];//动态分配
		posi = new int[mazeWidth * mazeHeight]; //动态分配
		for (int i = 0; i < mazeHeight; i++)//读取迷宫文件
		{
			for (int j = 0; j < mazeWidth; j++)
			{
				ifs >> maze[i * mazeWidth + j];
			}
		}
		ifs.close();//关闭文件
		return true;//返回正常值
	}
	else//如果未能成功找到文件并打开，返回错误信息
	{
		cerr << "File not found." << endl;
		return false;
	}
}

//	This function solves the maze using the 'hand on left wall'
//	rule, printing the maze position as it proceeds
//这个函数使用‘手在左墙上’解决迷宫
//规则，打印迷宫的位置

void SolveMaze()
{	
	int pos, other;
	Direction heading;//heading变量指示此时朝向的方向
	
	FindEntrance(pos);//该函数扫描迷宫数组中第一个非墙项并将初始位置传给pos
	heading = DOWN;  //第一步一定是向下的
	bool flag1 = 1; //用于第一步时无条件记录一次位置
	while (!AtExit(pos))//当未到达出口时，持续执行此逻辑
	{
		
		if (i == 1 && pos != posi[i - 1])//用于第二步时半无条件记录一次位置
		{
			posi[i] = pos;
			i++;
		}
		if (flag1)//用于第一步时无条件记录一次位置
		{
			posi[i] = pos;
			i++;
			flag1 = 0;
			
		}
		if (pos!=posi[i-1]&&i>=2&&pos!=posi[i-2])//用于第二步后有条件记录一次位置
		{
			posi[i] = pos;
			i++;
		}
		if(i>=400)
		{
			cout<<"array too small\n";
			abort();//功能：异常终止一个进程
		}
		WheresRight(pos,heading,other);//记录右边的位置
		if (!Wall(other))//如果右边没有墙，就向右转并前进一步
		{
			TurnRight(heading);
			MoveForward(pos,heading);
		}
		else//如果右边有墙，就优先向前走一步；如果前面也有墙，那就只能向左转（不向前走）
		{
			WheresAhead(pos,heading,other);//判断前方是否有墙
			if (!Wall(other))
				MoveForward(pos,heading);
			else
				TurnLeft(heading);
		}
	}
	posi[i]=pos;//记录最后一次的位置
	i++;
	if(i>=400)//如果步数过大，输出异常并执行断点
	{
		cout<<"array too small\n";
		abort();
	}
	int counter=0;
	for(int j=0;j<i;j++)//最后输出每一步的位置
	{
		if (posi[j] < 0)
		{
			continue;
		}
		cout << "Current position: (" << posi[j]/mazeWidth << ',' << posi[j]%mazeWidth << ')' << endl;
		counter++;
	}
	cout<<"total steps:"<<counter<<endl;//输出总步数
	cout << "Maze solved" << endl;//输出成功信号

	//释放所有动态分配的内存，避免内存泄漏。
	delete[]maze;
	delete[]posi;
}

//	This function scans the maze array for the first non-wall item
//	It assumes that the entrance is in the top row of the maze array
//该函数扫描迷宫数组中第一个非墙项
//它假设入口在迷宫数组的最上面一行
	
void FindEntrance(int& pos)//使用参数的引用来记录入口位置
{
	pos= 0;	
	while (Wall(pos))
	{
		pos++;
	}
}

//	This function returns true if the maze position is the exit
//	identified by being in the last row of the array
//如果迷宫的位置是出口，函数返回true
//通过位于数组的最后一行来标识

bool AtExit(int pos)//由于出口在最后一行，且有且仅有一个，因此在位置处于最后一行时判定成功
{
	return (pos >= (mazeHeight-1)*mazeWidth);
}

//	This function displays the position in the maze
//	At this time it specifies row and column of the array
//这个函数显示迷宫中的位置
//此时指定数组的行和列
//用于测试的函数
void ReportPosition(int pos)
{
	cout << "Current position: (" << pos/mazeWidth << ',' << pos%mazeWidth << ')' << endl;
}

//	This function takes a maze position and a heading and determines
//	the position to the right of this position
//这个函数获取一个迷宫的位置和一个方向，然后确定该位置右边的位置

void WheresRight(int pos, Direction heading, int& right)
{
	right=pos;
	switch (heading) 
	{
	case DOWN:
		{
			right--;
			break;
		}
	case LEFT:
		{
			right-=mazeWidth;
			break;
		}
	case UP:
		{
			right++;
			break;
		}
	case RIGHT:
		{
			right+=mazeWidth;
		}
	}

}

//	This function returns true if maze position is wall

bool Wall(int pos)//判断该位置是否为墙的函数
{
	return (maze[pos] == '#');
}

//	This function changes heading by turning right
//	Take current heading and adjust so that direction is to the right
//这个函数通过右转来改变方向
//取当前的方向并调整，使方向向右

void TurnRight(Direction& heading)
{
	switch (heading)
	{
	case DOWN:
	{
		heading = LEFT;
		break;
	}
	case LEFT:
	{
		heading = UP;
		break;
	}
	case UP:
	{
		heading = RIGHT;
		break;
	}
	case RIGHT:
	{
		heading = DOWN;
	}
	}
}

//	This function changes position in the maze by determining
//	the next position in the current direction
//这个函数通过确定当前方向上的下一个位置来改变迷宫中的位置

void MoveForward(int& pos, Direction heading)
{
	switch (heading)
	{
		case DOWN:
		{
			pos += mazeWidth;
		
			break;
		}
		case LEFT:
		{
			pos--;
		
			break;
		}
		case UP:
		{
			pos -= mazeWidth;
		
			break;
		}
		case RIGHT:
		{
			pos++;
		}
	}
}

//	This function determines the position in the direction
//	currently heading
//该函数确定当前方向的位置

void WheresAhead(int pos, Direction heading, int& ahead)
{
	ahead = pos;
	switch (heading)
	{
		case DOWN:
		{
			ahead += mazeWidth;
		
			break;
		}
		case LEFT:
		{
			ahead--;
		
			break;
		}
		case UP:
		{
			ahead -= mazeWidth;
		
			break;
		}
		case RIGHT:
		{
			ahead++;
		}
	}
}

//	This function changes heading by turning left
//这个函数通过左转来改变方向

void TurnLeft(Direction& heading)
{
	switch (heading)
	{
	case DOWN:
	{
		heading = RIGHT ;
		break;
	}
	case LEFT:
	{
		heading = DOWN;
		break;
	}
	case UP:
	{
		heading = LEFT;
		break;
	}
	case RIGHT:
	{
		heading = UP;
		
	}
	}
}
