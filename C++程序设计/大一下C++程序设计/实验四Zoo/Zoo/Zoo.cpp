#include"Zoo.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

//1 elephant, 2 giraffes and 3 monkeys.

int FoodSeller::FoodPriceList[3] = { 20,30,50 };

//void operator +(Money &m1,int money)//重载加法
//{
//	m1.SumOfCent = m1.SumOfCent + money;
//}
//
//void operator -(Money &m1, int money)//重载减法
//{
//	m1.SumOfCent = m1.SumOfCent - money;
//}

void Zoo::OneDaySimulation()
{
	//创建foodseller、zookeeper和3个AnimalEnclosure以及动物
	FoodSeller foodseller("Alex", 22);
	ZooKeeper zookeeper("Jack", 19);
	AnimalEnclosure ElephantHome;
	AnimalEnclosure GiraffeHome;
	AnimalEnclosure MonkeyHome;
	Elephant elephant;
	Giraffe giraffe1;
	Giraffe giraffe2;
	Monkey monkey1;
	Monkey monkey2;
	Monkey monkey3;

	int AdultAmount = rand() % 21 + 20;
	//开馆循环
	for (int i = 0; i < AdultAmount; i++)
	{
		int adultmoney = rand() % 1001 + 1000;
		Adult adult(adultmoney);
		int ChildAccompanied= rand() % 3 + 1;

		//买票
		adult.ReturnAdultMoney()=adult.ReturnAdultMoney() 
			- (100 + 40 * ChildAccompanied);

		
		//买饲料
		float MoneyOfEachFood = adult.ReturnAdultMoney().GetSumOfCent() / 3;
		int AmountOfPeanutsBuied = (int)MoneyOfEachFood / FoodSeller::FoodPriceList[0];
		int AmountOfCarrotsBuied = (int)MoneyOfEachFood / FoodSeller::FoodPriceList[1];
		int AmountOfBananasBuied = (int)MoneyOfEachFood / FoodSeller::FoodPriceList[2];

		//卖饲料
		foodseller.ReturnElephantFood().ReturnAmountOfFood() -= AmountOfPeanutsBuied;
		foodseller.ReturnGiraffeFood().ReturnAmountOfFood() -= AmountOfCarrotsBuied;
		foodseller.ReturnMonkeyFood().ReturnAmountOfFood() -= AmountOfBananasBuied;
			
		//判断售卖员是否卖完饲料
	    if (foodseller.ReturnElephantFood().ReturnAmountOfFood()
			&& foodseller.ReturnGiraffeFood().ReturnAmountOfFood()
			&& foodseller.ReturnMonkeyFood().ReturnAmountOfFood())
		{
			foodseller.ReturnMoneyFromFoodSold() += 
				adult.ReturnAdultMoney().GetSumOfCent();   
		}
		else
		{
			if (!foodseller.ReturnElephantFood().ReturnAmountOfFood())
			{
				cout << "The zoo closed because the seller ran out of peanuts." << endl;
				return;
			}
			else if (!foodseller.ReturnGiraffeFood().ReturnAmountOfFood())
			{
				cout << "The zoo closed because the seller ran out of carrots." << endl;
				return;

			}
			else
			{
				cout << "The zoo closed because the seller ran out of bananas." << endl;
				return;
			}
		}

		//喂动物
		if (ElephantHome.ReturnCurrentStatus())
		{
			elephant.ReturnAmountOfFoodEaten() += AmountOfPeanutsBuied;
		}

		if (GiraffeHome.ReturnCurrentStatus())
		{
			giraffe1.ReturnAmountOfFoodEaten() += AmountOfCarrotsBuied/2;
			giraffe2.ReturnAmountOfFoodEaten() += AmountOfCarrotsBuied/2;

		}

		if (MonkeyHome.ReturnCurrentStatus())
		{
			monkey1.ReturnAmountOfFoodEaten() += AmountOfBananasBuied/3;
			monkey2.ReturnAmountOfFoodEaten() += AmountOfBananasBuied/3;
			monkey3.ReturnAmountOfFoodEaten() += AmountOfBananasBuied/3;

		}

	}

	//闭馆复盘
	//计算各区域的dirtlevel
	if (elephant.ReturnAmountOfFoodEaten() > 750)
	{
		ElephantHome.ReturnDirtLevel() += (elephant.ReturnAmountOfFoodEaten() - 750);
		elephant.ReturnAmountOfFoodEaten() = 0;
	}

	if (giraffe1.ReturnAmountOfFoodEaten() > 500)
	{
		GiraffeHome.ReturnDirtLevel() += (giraffe1.ReturnAmountOfFoodEaten()- 500)*2;
		giraffe1.ReturnAmountOfFoodEaten() = 0;
		giraffe2.ReturnAmountOfFoodEaten() = 0;
	}

	if (monkey1.ReturnAmountOfFoodEaten() > 300)
	{
		MonkeyHome.ReturnDirtLevel() += (monkey1.ReturnAmountOfFoodEaten() - 300) * 3;
		monkey1.ReturnAmountOfFoodEaten() = 0;
		monkey2.ReturnAmountOfFoodEaten() = 0;
		monkey3.ReturnAmountOfFoodEaten() = 0;
	}

	//重置开放状态和zookeeper工作状态
	ElephantHome.ReturnCurrentStatus() = 1;
	GiraffeHome.ReturnCurrentStatus() = 1;
	MonkeyHome.ReturnCurrentStatus() = 1;
	zookeeper.ReturnWorkStatus() = 0;

	//判断dirtlevel是否达标,否则去清理其中之一
	if (ElephantHome.ReturnDirtLevel() > 2000&&!zookeeper.ReturnWorkStatus())
	{
		ElephantHome.ReturnDirtLevel() = 0;
		ElephantHome.ReturnCurrentStatus() = 0;
		zookeeper.ReturnWorkStatus() = 1;
		zookeeper.ReturnDaysOfCleaning() += 1;
	}
	if (GiraffeHome.ReturnDirtLevel() > 2000 && !zookeeper.ReturnWorkStatus())
	{
		GiraffeHome.ReturnDirtLevel() = 0;
		GiraffeHome.ReturnCurrentStatus() = 0;
		zookeeper.ReturnWorkStatus() = 1;
		zookeeper.ReturnDaysOfCleaning() += 1;
	}
	if (MonkeyHome.ReturnDirtLevel() > 2000 && !zookeeper.ReturnWorkStatus())
	{
		MonkeyHome.ReturnDirtLevel() = 0;
		MonkeyHome.ReturnCurrentStatus() = 0;
		zookeeper.ReturnWorkStatus() = 1;
		zookeeper.ReturnDaysOfCleaning() += 1;
	}

	if (zookeeper.ReturnDaysOfCleaning() >= 10)
	{
		cout<< "The zoo closed because the zoo keeper had enough of cleaning and quit!" 
			<< endl;
		return;
	}

}

void Zoo::EntireSimulation()
{
	//创建foodseller、zookeeper和3个AnimalEnclosure
	FoodSeller foodseller("Alex", 22);
	ZooKeeper zookeeper("Jack", 19);
	AnimalEnclosure ElephantHome;
	AnimalEnclosure GiraffeHome;
	AnimalEnclosure MonkeyHome;
	Elephant elephant;
	Giraffe giraffe1;
	Giraffe giraffe2;
	Monkey monkey1;
	Monkey monkey2;
	Monkey monkey3;

	while (1)
	{
		int AdultAmount = rand() % 21 + 20;
		//开馆循环
		for (int i = 0; i < AdultAmount; i++)
		{
			int adultmoney = rand() % 1001 + 1000;
			Adult adult(adultmoney);
			int ChildAccompanied = rand() % 3 + 1;

			//买票
			
			adult.ReturnAdultMoney()=adult.ReturnAdultMoney()
				- (100 + 40 * ChildAccompanied);


			//买饲料
			float MoneyOfEachFood = adult.ReturnAdultMoney().GetSumOfCent() / 3;
			int AmountOfPeanutsBuied = MoneyOfEachFood / FoodSeller::FoodPriceList[0];
			int AmountOfCarrotsBuied = MoneyOfEachFood / FoodSeller::FoodPriceList[1];
			int AmountOfBananasBuied = MoneyOfEachFood / FoodSeller::FoodPriceList[2];

			//卖饲料
			foodseller.ReturnElephantFood().ReturnAmountOfFood() -= AmountOfPeanutsBuied;
			foodseller.ReturnGiraffeFood().ReturnAmountOfFood() -= AmountOfCarrotsBuied;
			foodseller.ReturnMonkeyFood().ReturnAmountOfFood() -= AmountOfBananasBuied;

			//判断售卖员是否卖完饲料
			if (foodseller.ReturnElephantFood().ReturnAmountOfFood()>0
				&& foodseller.ReturnGiraffeFood().ReturnAmountOfFood()>0
				&& foodseller.ReturnMonkeyFood().ReturnAmountOfFood()>0)
			{
				foodseller.ReturnMoneyFromFoodSold() +=
					adult.ReturnAdultMoney().GetSumOfCent();
			}
			else
			{
				if (foodseller.ReturnElephantFood().ReturnAmountOfFood()<0)
				{
					cout << "The zoo closed because the seller ran out of peanuts." << endl;
					return;
				}
				else if (foodseller.ReturnGiraffeFood().ReturnAmountOfFood() < 0)
				{
					cout << "The zoo closed because the seller ran out of carrots." << endl;
					return;

				}
				else if (foodseller.ReturnMonkeyFood().ReturnAmountOfFood() < 0)
				{
					cout << "The zoo closed because the seller ran out of bananas." << endl;
					return;
				}
			}

			//喂动物
			if (ElephantHome.ReturnCurrentStatus())
			{
				elephant.ReturnAmountOfFoodEaten() += AmountOfPeanutsBuied;
			}

			if (GiraffeHome.ReturnCurrentStatus())
			{
				giraffe1.ReturnAmountOfFoodEaten() += AmountOfCarrotsBuied / 2;
				giraffe2.ReturnAmountOfFoodEaten() += AmountOfCarrotsBuied / 2;

			}

			if (MonkeyHome.ReturnCurrentStatus())
			{
				monkey1.ReturnAmountOfFoodEaten() += AmountOfBananasBuied / 3;
				monkey2.ReturnAmountOfFoodEaten() += AmountOfBananasBuied / 3;
				monkey3.ReturnAmountOfFoodEaten() += AmountOfBananasBuied / 3;

			}

		}

		//闭馆复盘
		//计算各区域的dirtlevel
		if (elephant.ReturnAmountOfFoodEaten() > 750)
		{
			ElephantHome.ReturnDirtLevel() += (elephant.ReturnAmountOfFoodEaten() - 750);
			elephant.ReturnAmountOfFoodEaten() = 0;
		}

		if (giraffe1.ReturnAmountOfFoodEaten() > 500)
		{
			GiraffeHome.ReturnDirtLevel() += (2*giraffe1.ReturnAmountOfFoodEaten() - 1000);
			giraffe1.ReturnAmountOfFoodEaten() = 0;
			giraffe2.ReturnAmountOfFoodEaten() = 0;
		}

		if (monkey1.ReturnAmountOfFoodEaten() > 300)
		{
			MonkeyHome.ReturnDirtLevel() += (3*monkey1.ReturnAmountOfFoodEaten() - 900);
			monkey1.ReturnAmountOfFoodEaten() = 0;
			monkey2.ReturnAmountOfFoodEaten() = 0;
			monkey3.ReturnAmountOfFoodEaten() = 0;
		}

		//重置开放状态和zookeeper工作状态
		ElephantHome.ReturnCurrentStatus() = 1;
		GiraffeHome.ReturnCurrentStatus() = 1;
		MonkeyHome.ReturnCurrentStatus() = 1;
		zookeeper.ReturnWorkStatus() = 0;

		//判断dirtlevel是否达标,否则去清理其中之一
		if (ElephantHome.ReturnDirtLevel() > 2000 && !zookeeper.ReturnWorkStatus())
		{
			ElephantHome.ReturnDirtLevel() = 0;
			ElephantHome.ReturnCurrentStatus() = 0;
			zookeeper.ReturnWorkStatus() = 1;
			zookeeper.ReturnDaysOfCleaning() += 1;
		}
		if (GiraffeHome.ReturnDirtLevel() > 2000 && !zookeeper.ReturnWorkStatus())
		{
			GiraffeHome.ReturnDirtLevel() = 0;
			GiraffeHome.ReturnCurrentStatus() = 0;
			zookeeper.ReturnWorkStatus() = 1;
			zookeeper.ReturnDaysOfCleaning() += 1;
		}
		if (MonkeyHome.ReturnDirtLevel() > 2000 && !zookeeper.ReturnWorkStatus())
		{
			MonkeyHome.ReturnDirtLevel() = 0;
			MonkeyHome.ReturnCurrentStatus() = 0;
			zookeeper.ReturnWorkStatus() = 1;
			zookeeper.ReturnDaysOfCleaning() += 1;
		}

		if (zookeeper.ReturnDaysOfCleaning() >= 10)
		{
			cout << "The zoo closed because the zoo keeper had enough of cleaning and quit!"
				<< endl;
			return;
		}
		cout << "Day end report:" << endl;
		cout << "Peanuts left: " << foodseller.ReturnElephantFood().ReturnAmountOfFood() << endl;
		cout << "Carrots left: " << foodseller.ReturnGiraffeFood().ReturnAmountOfFood() << endl;
		cout << "Bananas left: " << foodseller.ReturnMonkeyFood().ReturnAmountOfFood() << endl;
		cout << "Elephant dirt: " << ElephantHome.ReturnDirtLevel() << endl;
		cout << "Giraffe dirt: " << GiraffeHome.ReturnDirtLevel() << endl;
		cout << "Monkey dirt: " << MonkeyHome.ReturnDirtLevel() << endl;
		cout << "Keeper cleaning days: " << zookeeper.ReturnDaysOfCleaning() << endl;
	}
}
