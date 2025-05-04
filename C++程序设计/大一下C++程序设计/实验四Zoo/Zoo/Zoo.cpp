#include "Zoo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <algorithm>

int FoodSeller::FoodPriceList[3] = { 20, 30, 50 };

Zoo::Zoo() {
    InitializeZoo();
}

Zoo::~Zoo() {
    for (auto& pair : animalEnclosures) {
        delete pair.second;
    }
}

void Zoo::InitializeZoo() {
    // 创建动物
    animals.push_back(std::make_unique<Elephant>());
    animals.push_back(std::make_unique<Giraffe>());
    animals.push_back(std::make_unique<Giraffe>());
    animals.push_back(std::make_unique<Monkey>());
    animals.push_back(std::make_unique<Monkey>());
    animals.push_back(std::make_unique<Monkey>());

    // 创建围栏并建立映射
    for (auto& animal : animals) {
        animalEnclosures[animal.get()] = new AnimalEnclosure();
    }

    // 创建工作人员
    foodseller = std::make_unique<FoodSeller>("Alex", 22);
    zookeeper = std::make_unique<ZooKeeper>("Jack", 19);
}

void Zoo::ProcessVisitor(Adult& adult, int childCount) {
    // 买票
    adult.ReturnAdultMoney() = adult.ReturnAdultMoney() - (100 + 40 * childCount);

    // 买饲料
    float moneyForFood = adult.ReturnAdultMoney().GetSumOfCent() / 3;
    int peanuts = std::max(0.0f, moneyForFood / FoodSeller::FoodPriceList[0]);
    int carrots = std::max(0.0f, moneyForFood / FoodSeller::FoodPriceList[1]);
    int bananas = std::max(0.0f, moneyForFood / FoodSeller::FoodPriceList[2]);

    // 卖饲料
    foodseller->ReturnElephantFood().ReturnAmountOfFood() -= peanuts;
    foodseller->ReturnGiraffeFood().ReturnAmountOfFood() -= carrots;
    foodseller->ReturnMonkeyFood().ReturnAmountOfFood() -= bananas;

    // 检查食物是否售罄
    if (foodseller->ReturnElephantFood().ReturnAmountOfFood() <= 0 ||
        foodseller->ReturnGiraffeFood().ReturnAmountOfFood() <= 0 ||
        foodseller->ReturnMonkeyFood().ReturnAmountOfFood() <= 0) {
        return;
    }

    foodseller->ReturnMoneyFromFoodSold() += adult.ReturnAdultMoney().GetSumOfCent();

    // 喂动物
    FeedAnimals(peanuts, carrots, bananas);
}

void Zoo::FeedAnimals(int peanuts, int carrots, int bananas) {
    for (auto& animal : animals) {
        if (!animalEnclosures[animal.get()]->ReturnCurrentStatus()) continue;

        if (auto elephant = dynamic_cast<Elephant*>(animal.get())) {
            elephant->ReturnAmountOfFoodEaten() += peanuts;
        }
        else if (auto giraffe = dynamic_cast<Giraffe*>(animal.get())) {
            giraffe->ReturnAmountOfFoodEaten() += carrots * giraffe->GetFoodConsumptionRate();
        }
        else if (auto monkey = dynamic_cast<Monkey*>(animal.get())) {
            monkey->ReturnAmountOfFoodEaten() += bananas * monkey->GetFoodConsumptionRate();
        }
    }
}

void Zoo::CalculateDirtLevels() {
    for (auto& animal : animals) {
        auto enclosure = animalEnclosures[animal.get()];
        int dirtIncrease = animal->CalculateDirtIncrease();
        if (dirtIncrease > 0) {
            enclosure->ReturnDirtLevel() += dirtIncrease;
            animal->ReturnAmountOfFoodEaten() = 0;
        }
    }
}

void Zoo::CleanEnclosures() {
    for (auto& animal : animals) {
        auto enclosure = animalEnclosures[animal.get()];
        if (enclosure->ReturnDirtLevel() > 2000 && !zookeeper->ReturnWorkStatus()) {
            enclosure->ReturnDirtLevel() = 0;
            enclosure->ReturnCurrentStatus() = false;
            zookeeper->ReturnWorkStatus() = true;
            zookeeper->ReturnDaysOfCleaning()++;

            if (dynamic_cast<Elephant*>(animal.get())) elephantEnclosureClosedDays++;
            else if (dynamic_cast<Giraffe*>(animal.get())) giraffeEnclosureClosedDays++;
            else if (dynamic_cast<Monkey*>(animal.get())) monkeyEnclosureClosedDays++;
        }
    }
}

void Zoo::PrintClosingStats(const std::string& reason) {
    std::cout << "The zoo has been open for " << daysOperated << " days" << std::endl;
    std::cout << "The zoo closed because " << reason << std::endl;
    std::cout << "The gross number of adults is " << totalAdults << std::endl;
    std::cout << "The gross number of children is " << totalChildren << std::endl;
    std::cout << "The total amount of money made by the seller is "
        << foodseller->ReturnMoneyFromFoodSold() / 100 << " dollars and "
        << foodseller->ReturnMoneyFromFoodSold() % 100 << " cents" << std::endl;
    std::cout << "The number of days the zoo keeper spent cleaning is "
        << zookeeper->ReturnDaysOfCleaning() << std::endl;
    std::cout << "The total close day of ElephantHome is " << elephantEnclosureClosedDays << std::endl;
    std::cout << "The total close day of GiraffeHome is " << giraffeEnclosureClosedDays << std::endl;
    std::cout << "The total close day of MonkeyHome is " << monkeyEnclosureClosedDays << std::endl;
}

void Zoo::OneDaySimulation() {
    EntireSimulation();
}

void Zoo::EntireSimulation() {
    srand(static_cast<unsigned>(time(nullptr)));

    while (true) {
        daysOperated++;
        int adultCount = rand() % 21 + 20;
        totalAdults += adultCount;

        for (int i = 0; i < adultCount; i++) {
            int childCount = rand() % 3 + 1;
            totalChildren += childCount;

            Adult adult(static_cast<float>(rand() % 1001 + 1000));
            ProcessVisitor(adult, childCount);

            // 检查食物是否售罄
            if (foodseller->ReturnElephantFood().ReturnAmountOfFood() <= 0) {
                PrintClosingStats("the seller ran out of peanuts.");
                return;
            }
            if (foodseller->ReturnGiraffeFood().ReturnAmountOfFood() <= 0) {
                PrintClosingStats("the seller ran out of carrots.");
                return;
            }
            if (foodseller->ReturnMonkeyFood().ReturnAmountOfFood() <= 0) {
                PrintClosingStats("the seller ran out of bananas.");
                return;
            }
        }

        CalculateDirtLevels();
        CleanEnclosures();

        // 重置围栏状态
        for (auto& pair : animalEnclosures) {
            pair.second->ReturnCurrentStatus() = true;
        }
        zookeeper->ReturnWorkStatus() = false;

        if (zookeeper->ReturnDaysOfCleaning() >= 10) {
            PrintClosingStats("the zoo keeper had enough of cleaning and quit!");
            return;
        }
    }
}
