#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <vector>
#include <map>
#include <memory>

// Ç°ÏòÉùÃ÷
class Animal;
class AnimalEnclosure;
class FoodSeller;
class ZooKeeper;
class Adult;

class Money {
public:
    Money(float initialMoney = 0) : SumOfCent(initialMoney), SumOfDollar(initialMoney / 100) {}

    int GetSumOfDollar() const { return SumOfDollar; }
    float GetSumOfCent() const { return SumOfCent; }

    Money operator +(int money) const {
        return Money(SumOfCent + money);
    }

    Money operator -(int money) const {
        return Money(SumOfCent - money);
    }

private:
    int SumOfDollar;
    float SumOfCent;
};

class AnimalFood {
public:
    AnimalFood(std::string foodname, int foodamount)
        : TypeOfFood(foodname), AmountOfFood(foodamount) {
    }

    std::string& ReturnTypeOfFood() { return TypeOfFood; }
    int& ReturnAmountOfFood() { return AmountOfFood; }

private:
    std::string TypeOfFood;
    int AmountOfFood;
};

class AnimalEnclosure {
public:
    int& ReturnDirtLevel() { return DirtLevel; }
    bool& ReturnCurrentStatus() { return CurrentStatus; }

private:
    int DirtLevel = 0;
    bool CurrentStatus = true;
};

class Person {
public:
    virtual ~Person() = default;
    virtual std::string GetName() const = 0;
    virtual int GetAge() const = 0;

protected:
    std::string m_name;
    int m_age = 0;
};

class ZooKeeper : public Person {
public:
    ZooKeeper(std::string name, int age) 
    {
        m_name = name;
        m_age = age;
    }
    std::string GetName() const override { return m_name; }
    int GetAge() const override { return m_age; }
    int& ReturnDaysOfCleaning() { return DaysOfCleaning; }
    bool& ReturnWorkStatus() { return WorkStatus; }

private:
    int DaysOfCleaning = 0;
    bool WorkStatus = false;
};

class FoodSeller : public Person 
{
public:
    FoodSeller(std::string name, int age)
        :
        ElephantFood("Peanuts", 10000),
        GiraffeFood("Carrots", 7000),
        MonkeyFood("Bananas", 4000) 
    {
        m_name = name;
        m_age = age;
    }

    std::string GetName() const override { return m_name; }
    int GetAge() const override { return m_age; }

    AnimalFood& ReturnElephantFood() { return ElephantFood; }
    AnimalFood& ReturnGiraffeFood() { return GiraffeFood; }
    AnimalFood& ReturnMonkeyFood() { return MonkeyFood; }
    int& ReturnMoneyFromFoodSold() { return MoneyFromFoodSold; }

    static int FoodPriceList[3];

private:
    AnimalFood ElephantFood;
    AnimalFood GiraffeFood;
    AnimalFood MonkeyFood;
    int MoneyFromFoodSold = 0;
};

class Visitor : public Person {
public:
    std::string VisitorPassIDNumber;
};

class Child : public Visitor {
public:
    Child(std::string name, int age, std::string IDNumber)
    {
        m_name = name;
        m_age = age;
        VisitorPassIDNumber = IDNumber;
    }
    std::string GetName() const override { return m_name; }
    int GetAge() const override { return m_age; }

private:
    int AnimalFoodOwned = 0;
};

class Adult : public Visitor {
public:
    Adult(std::string name, int age, std::string IDNumber)
        : AdultMoney(0)
    {
        m_name = name;
        m_age = age;
        VisitorPassIDNumber = IDNumber;
    }
    Adult(float money) : AdultMoney(money) {
        VisitorPassIDNumber = "19870532";
    }

    std::string GetName() const override { return m_name; }
    int GetAge() const override { return m_age; }
    Money& ReturnAdultMoney() { return AdultMoney; }

private:
    Money AdultMoney;
};

class Animal {
public:
    virtual ~Animal() = default;
    virtual float& ReturnAmountOfFoodEaten() = 0;
    virtual int CalculateDirtIncrease() const = 0;
    virtual int GetFoodThreshold() const = 0;
    virtual std::string GetFoodType() const = 0;
    virtual float GetFoodConsumptionRate() const = 0;

protected:
    float Weight = 30;
    float AmountOfFoodEaten = 0;
};

class Elephant : public Animal {
public:
    float& ReturnAmountOfFoodEaten() override { return AmountOfFoodEaten; }
    int CalculateDirtIncrease() const override {
        return (AmountOfFoodEaten > GetFoodThreshold()) ? (AmountOfFoodEaten - GetFoodThreshold()) : 0;
    }
    int GetFoodThreshold() const override { return 750; }
    std::string GetFoodType() const override { return "Peanuts"; }
    float GetFoodConsumptionRate() const override { return 1.0f; }

private:
    float TrunkLength = 3;
};

class Giraffe : public Animal {
public:
    float& ReturnAmountOfFoodEaten() override { return AmountOfFoodEaten; }
    int CalculateDirtIncrease() const override {
        return (AmountOfFoodEaten > GetFoodThreshold()) ? (AmountOfFoodEaten - GetFoodThreshold()) * 2 : 0;
    }
    int GetFoodThreshold() const override { return 500; }
    std::string GetFoodType() const override { return "Carrots"; }
    float GetFoodConsumptionRate() const override { return 0.5f; }

private:
    float NeckLength = 5;
};

class Monkey : public Animal {
public:
    float& ReturnAmountOfFoodEaten() override { return AmountOfFoodEaten; }
    int CalculateDirtIncrease() const override {
        return (AmountOfFoodEaten > GetFoodThreshold()) ? (AmountOfFoodEaten - GetFoodThreshold()) * 3 : 0;
    }
    int GetFoodThreshold() const override { return 300; }
    std::string GetFoodType() const override { return "Bananas"; }
    float GetFoodConsumptionRate() const override { return 0.333f; }

private:
    float ArmLength = 1.5;
};

class Zoo {
public:
    Zoo();
    ~Zoo();
    void OneDaySimulation();
    void EntireSimulation();

private:
    std::vector<std::unique_ptr<Animal>> animals;
    std::map<Animal*, AnimalEnclosure*> animalEnclosures;
    std::unique_ptr<FoodSeller> foodseller;
    std::unique_ptr<ZooKeeper> zookeeper;
    int daysOperated = 0;
    int totalAdults = 0;
    int totalChildren = 0;
    int elephantEnclosureClosedDays = 0;
    int giraffeEnclosureClosedDays = 0;
    int monkeyEnclosureClosedDays = 0;

    void InitializeZoo();
    void ProcessVisitor(Adult& adult, int childCount);
    void FeedAnimals(int peanuts, int carrots, int bananas);
    void CalculateDirtLevels();
    void CleanEnclosures();
    void PrintClosingStats(const std::string& reason);
};

#endif // ZOO_H