#ifndef ZOO_H
#define ZOO_H

#include<string>

class Zoo
{
public:
	void OneDaySimulation();

	void EntireSimulation();
};

class Money
{
public:
	Money(float InitialMoney)//有参构造
	{
		SumOfCent = InitialMoney;
	}

	Money()//无参构造
	{
		SumOfCent = 0;
	}

	int GetSumOfDollar() 
	{
		SumOfDollar = SumOfCent / 100;
		return SumOfDollar;
	}
	float GetSumOfCent() 
	{
		return SumOfCent;
	}

	Money operator +(int money)//重载加法
	{
		Money m2;
		m2.SumOfCent = this->SumOfCent + money;
		return m2;
	}

	Money operator -(int money)//重载减法
	{
		Money m2;
		m2.SumOfCent = this->SumOfCent - money;
		return m2;
	}


	//float SumOfMoney;
	int SumOfDollar;
	int SumOfCent;// 1 dollar == 100 cents , in the unit of cent
};

class AnimalFood//For recording the type and amount of food.
{
public:
	AnimalFood(std::string foodname,int foodamount)
	{
		TypeOfFood = foodname;
		AmountOfFood = foodamount;
	}

	std::string& ReturnTypeOfFood()//接口 1
	{
		return TypeOfFood;
	}

	int& ReturnAmountOfFood()//接口 2
	{
		return AmountOfFood;
	}

private:
	std::string TypeOfFood;/*peanuts for the elephant; 
							carrots for the giraffes; 
							bananas for the monkeys.*/

	int AmountOfFood;//单位：份（题目定义）
};

class AnimalEnclosure
{
public:
//For housing the animal(s).
//This should record the dirt level 
//and current status(i.e.open / close to visitors).
	int& ReturnDirtLevel()
	{
		return DirtLevel;
	}

	bool& ReturnCurrentStatus()
	{
		return CurrentStatus;
	}

private:
	int DirtLevel = 0;//整洁程度
	bool CurrentStatus = 1;//开放状态
};

class Animal//抽象类
{
public:
	float Weight;//in the unit of KG
	float AmountOfFoodEaten = 0;//单位：份（题目定义）
};

class Elephant:public Animal
{
public:
	float& ReturnAmountOfFoodEaten()
	{
		return AmountOfFoodEaten;
	}

private:

	float TrunkLength;//象鼻长： 米
};

class Giraffe :public Animal
{
public:
	float& ReturnAmountOfFoodEaten()
	{
		return AmountOfFoodEaten;
	}

private:

	float NeckLength;//长颈鹿脖长： 米
};

class Monkey  :public Animal
{
public:
	float& ReturnAmountOfFoodEaten()
	{
		return AmountOfFoodEaten;
	}

private:

	float ArmLength;//猴子臂长： 米
};

class Person//抽象类
{
public:

	virtual std::string GetName() = 0;
	virtual int GetAge() = 0;

	std::string m_name;
	int m_age;
};

class ZooKeeper:public Person
{
public:
	ZooKeeper(std::string name, int age) 
	{
		m_name = name;
		m_age = age;
	}

	std::string GetName() override
	{
		return m_name;
	}
	int GetAge() override
	{
		return m_age;
	}

	int& ReturnDaysOfCleaning()
	{
		return DaysOfCleaning;
	}

	bool& ReturnWorkStatus()
	{
		return WorkStatus;
	}

private:
	int DaysOfCleaning = 0;
	bool WorkStatus = 0;//初始为未工作
};

class FoodSeller:public Person
{
public:
	FoodSeller(std::string name,int age):
		ElephantFood("Peanuts",10000), 
		GiraffeFood("Carrots", 7000),
		MonkeyFood("Bananas", 4000)
	{
		m_name = name;
		m_age = age;
	}

	std::string GetName() override
	{
		return m_name;
	}
	int GetAge() override
	{
		return m_age;
	}

	AnimalFood& ReturnElephantFood()//接口 1
	{
		return ElephantFood;
	}

	AnimalFood& ReturnGiraffeFood()//接口 2
	{
		return GiraffeFood;
	}

	AnimalFood& ReturnMonkeyFood()//接口 3
	{
		return MonkeyFood;
	}

	float& ReturnMoneyFromFoodSold()//接口 4
	{
		return MoneyFromFoodSold;
	}

	static int FoodPriceList[3];
private:
	AnimalFood ElephantFood;
	AnimalFood GiraffeFood;
	AnimalFood MonkeyFood;
	float MoneyFromFoodSold = 0;
};

class Vistor:public Person
{
public:

	//Vistor(std::string name, int age, std::string IDNumber)
	//	: VisitorPassIDNumber(IDNumber)
	//{
	//	m_name = name;
	//	m_age = age;
	//}


	std::string VisitorPassIDNumber;
};

class Child :public Vistor
{
public:

	Child(std::string name, int age, std::string IDNumber)
	{
		m_name = name;
		m_age = age;
		VisitorPassIDNumber = IDNumber;
	}

	std::string GetName() override
	{
		return m_name;
	}
	int GetAge() override
	{
		return m_age;
	}

private:
	int AnimalFoodOwned = 0;
};

class Adult :public Vistor
{
public:
	Adult(std::string name, int age, std::string IDNumber)
	{
		m_name = name;
		m_age = age;
		VisitorPassIDNumber = IDNumber;
	}

	Adult(float money) :AdultMoney(money){}


	std::string GetName() override
	{
		return m_name;
	}
	int GetAge() override
	{
		return m_age;
	}

	Money& ReturnAdultMoney()//接口 
	{
		return AdultMoney;
	}

private:

	Money AdultMoney;
};













#endif //ZOO_H