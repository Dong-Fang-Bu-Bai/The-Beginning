#include<iostream>
using namespace std;

//CPU������
class AbstractCPU
{
public:
	virtual void work() = 0;
};
//GPU������
class AbstractGPU
{
public:
	virtual void work() = 0;
};
//Memory������
class AbstractMemory
{
public:
	virtual void work() = 0;
};

//������
class Computer
{
public:
	Computer(AbstractCPU* C, AbstractGPU* G,AbstractMemory*M)
	{
		CPU = C;
		GPU = G;
		Memory = M;
	}

	void doWork()
	{
		CPU->work();
		GPU->work();
		Memory->work();
	}

	//��д����������������ָ������ͷ�
	~Computer()
	{
		if (CPU != NULL)
		{
			delete CPU;
			CPU = NULL;
		}

		if (GPU != NULL)
		{
			delete GPU;
			GPU = NULL;
		}

		if (Memory != NULL)
		{
			delete Memory;
			Memory = NULL;
		}

	}

private:

	AbstractCPU* CPU;//CPU���ָ��
	AbstractGPU* GPU;//GPU���ָ��
	AbstractMemory* Memory;//Memory���ָ��
};



//Intel��CPU
class IntelCPU:public AbstractCPU
{
public:
	virtual void work()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};
//Intel��GPU
class IntelGPU:public AbstractGPU
{
public:
	virtual void work()
	{
		cout << "Intel��GPU��ʼ����" << endl;
	}
};
//Intel��Memory
class IntelMemory:public AbstractMemory
{
public:   
	virtual void work()
	{
		cout << "Intel��Memory��ʼ����" << endl;
	}
};


//Lenovo��CPU
class LenovoCPU :public AbstractCPU
{
public:
	virtual void work()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};
//Lenovo��GPU
class LenovoGPU :public AbstractGPU
{
public:
	virtual void work()
	{
		cout << "Lenovo��GPU��ʼ����" << endl;
	}
};
//Lenovo��Memory
class LenovoMemory :public AbstractMemory
{
public:
	virtual void work()
	{
		cout << "Lenovo��Memory��ʼ����" << endl;
	}
};

//���Խ׶�
void test01()
{
	cout << "��һ̨���Կ�ʼ����:" << endl;
	//������һ̨����
	Computer *c1=new Computer(new IntelCPU, new LenovoGPU, new IntelMemory);
	
	c1->doWork();
	delete c1;
	cout << "-------------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ����:" << endl;
	//��װ�ڶ�̨����
	Computer* c2 = new Computer(new LenovoCPU, new IntelGPU, new LenovoMemory);

	c2->doWork();
	delete c2;
}

int main()
{
	test01();


	system("pause");
	return 0;
}