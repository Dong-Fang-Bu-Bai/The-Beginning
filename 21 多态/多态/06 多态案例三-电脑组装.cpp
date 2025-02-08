#include<iostream>
using namespace std;

//CPU抽象类
class AbstractCPU
{
public:
	virtual void work() = 0;
};
//GPU抽象类
class AbstractGPU
{
public:
	virtual void work() = 0;
};
//Memory抽象类
class AbstractMemory
{
public:
	virtual void work() = 0;
};

//电脑类
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

	//编写析构函数，对三个指针进行释放
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

	AbstractCPU* CPU;//CPU零件指针
	AbstractGPU* GPU;//GPU零件指针
	AbstractMemory* Memory;//Memory零件指针
};



//Intel的CPU
class IntelCPU:public AbstractCPU
{
public:
	virtual void work()
	{
		cout << "Intel的CPU开始工作" << endl;
	}
};
//Intel的GPU
class IntelGPU:public AbstractGPU
{
public:
	virtual void work()
	{
		cout << "Intel的GPU开始工作" << endl;
	}
};
//Intel的Memory
class IntelMemory:public AbstractMemory
{
public:   
	virtual void work()
	{
		cout << "Intel的Memory开始工作" << endl;
	}
};


//Lenovo的CPU
class LenovoCPU :public AbstractCPU
{
public:
	virtual void work()
	{
		cout << "Lenovo的CPU开始工作" << endl;
	}
};
//Lenovo的GPU
class LenovoGPU :public AbstractGPU
{
public:
	virtual void work()
	{
		cout << "Lenovo的GPU开始工作" << endl;
	}
};
//Lenovo的Memory
class LenovoMemory :public AbstractMemory
{
public:
	virtual void work()
	{
		cout << "Lenovo的Memory开始工作" << endl;
	}
};

//测试阶段
void test01()
{
	cout << "第一台电脑开始工作:" << endl;
	//创建第一台电脑
	Computer *c1=new Computer(new IntelCPU, new LenovoGPU, new IntelMemory);
	
	c1->doWork();
	delete c1;
	cout << "-------------------------" << endl;
	cout << "第二台电脑开始工作:" << endl;
	//组装第二台电脑
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