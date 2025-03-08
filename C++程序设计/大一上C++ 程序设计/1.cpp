#include<iostream>
using namespace std;
class Person 
{

public:

    Person(int a) 
    {

        id = a;

    }

    int getId() {

        return id;

    }

private:

    int id;

};



int main4()
{



    int id = 200;

    Person person(id);

    id++;

    cout << person.getId();
  
    
	system("pause");
	return 0;
}