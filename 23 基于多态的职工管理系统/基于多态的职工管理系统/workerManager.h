#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>  //���������������ͷ�ļ�
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;  //ʹ�ñ�׼�����ռ�

#include<fstream>  //�ļ���дͷ�ļ�
#define FILENAME "empFile.txt"  //�ļ����궨��

class WorkerManager
{
public:
	//���캯��������
	WorkerManager();

	//չʾ�˵�������
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;
	 
	//���ְ��
	void Add_Emp();

	//�����ļ�	
	void save();	
	
	//��������������
	~WorkerManager();
};
