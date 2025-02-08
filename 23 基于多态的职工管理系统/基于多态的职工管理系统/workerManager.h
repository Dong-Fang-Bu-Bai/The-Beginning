#pragma once  //防止头文件重复包含
#include<iostream>  //包含输入输出流的头文件
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;  //使用标准命名空间

#include<fstream>  //文件读写头文件
#define FILENAME "empFile.txt"  //文件名宏定义

class WorkerManager
{
public:
	//构造函数的声明
	WorkerManager();

	//展示菜单的声明
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;
	 
	//添加职工
	void Add_Emp();

	//保存文件	
	void save();	
	
	//析构函数的声明
	~WorkerManager();
};
