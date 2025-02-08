#pragma once
#include<iostream>
using namespace std;

//点类
class Point
{
public:
	//设置x坐标
	void setX(int x);
	
	//获取x坐标
	int getX();
	
	//设置y
	void setY(int y);
	
	//获取y
	int getY();
	
private:
	int m_X;
	int m_Y;
};
