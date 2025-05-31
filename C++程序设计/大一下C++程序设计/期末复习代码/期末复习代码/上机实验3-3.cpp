////(³ÌÐòÌî¿Õ)In the following class definition, 
//// Employee is the virtual base class of Salesman, 
//// and SalseLeader is derived from class Salesman.
//// The way of inheritance is all public.
//#include <iostream>
//#include <string>
//using namespace std; 
//
//class Employee 
//{
//private:
//    string ID;
//    string name;
//    double baseSalary;
//public:
//
//    Employee(string id, string nm, double bS) 
//    {
//        ID = id;
//        name = nm;
//        baseSalary = bS;
//    }
//
//    //__(1)__ declare a function getName() which returns String
//    string getName()
//    { 
//        return name;
//    }
//    virtual double getSalary() 
//    {
//        return baseSalary;
//    }
//};
//
//class Salesman :public Employee 
//{
//private:
//    double salesVolume;
//    double commission;
//public:
//    Salesman(string Id, string theName, double theBaseSalary, double
//        theSalesVolume, double theCommission) :Employee(Id, theName, theBaseSalary) {
//       // __(2)__
//        salesVolume = theSalesVolume;
//       // __(3)__
//        commission = theCommission;
//    }
//
//    void setSalesVolume(double salesVolume) 
//    {
//        this->salesVolume = salesVolume;
//    }
//
//    double getSalesVolume()
//    {
//        return salesVolume;
//    }
//
//    void setCommission(double commission) 
//    {
//        this->commission = commission;
//    }
//
//    double getCommission() 
//    {
//        return commission;
//    }
//
//    double getSalary() 
//    {
//        return Employee::getSalary() + salesVolume * commission;
//    }
//
//    void salesing() 
//    {
//        //__(4)__
//        cout << Employee::getName() << " is salesing" << endl; // print the Salesman¡¯s name
//    }
//};
//
//
//class SalseLeader : public Salesman  // __(5)__ 
//{
//
//private:
//
//    double bonus;
//
//public:
//
//    SalseLeader(string Id, string theName, double theBaseSalary, double
//        theBonus, double theSalesVolume, double theCommission)
//        : Salesman(Id, theName, theBaseSalary, theSalesVolume, theCommission) // __(6)__ create base class object
//    {
//        bonus = theBonus;
//    };
//    double getBonurs() 
//    {
//        return bonus;
//    }
//
//    double getSalary() 
//    {
//        // the salary of SalseLeader is baseSalary + bonus + salesVolume*commission
//        //__(7)__
//        return Salesman::getSalary() + bonus;
//
//    }
//    void leadering() 
//    {
//        cout << Employee::getName() << " is leadering" << endl;
//    }
//};
//
//int main() 
//{
//    SalseLeader salseleader1("10002", "Li Qiang", 5000, 400, 500, 0.05);
//
//    Salesman salesman1("10001", "Zhang Wei", 4000, 1000, 0.05);
//
//    Employee* emp[2];
//
//    emp[0] = &salseleader1;
//
//    emp[1] = &salesman1;
//
//    cout << "Li Qiang¡¯s salary is " << emp[0]->getSalary() << endl;
//
//    // Call the salesing function of Zhang Wei, use pointer
//    //__(8)__
//    (&salesman1)->salesing();
//    dynamic_cast<Salesman*>(emp[1])->salesing();
//
//    system("pause");
//
//    return 0;
//
//
//}