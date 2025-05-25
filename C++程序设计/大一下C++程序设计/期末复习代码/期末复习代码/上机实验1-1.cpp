
//改写下述结构体：

//#include <iostream> 
//using namespace std;
//
//struct student 
//{
//	char name[20];
//	unsigned int id;
//	double score;
//};
//
//void input(student& stu) 
//{
//	cout << "name?";
//	cin >> stu.name; cout << "id?";
//	cin >> stu.id; cout << "score?";
//	cin >> stu.score;
//}
//
//void output(student& stu) 
//{ 
//	cout << "name: " << stu.name << "\tid: " << stu.id << "\tscore: " << stu.score << endl; 
//} 
//
//int main() 
//{
//	student s = { "\0", 0, 0 }; 
//	input(s);
//	output(s);
//
//	system("pause");
//	return 0;
//}


//#include <iostream> 
//#include <string> 
//using namespace std;
//class student 
//{
//	string name;
//	unsigned int id;
//	double score; 
//public:
//	void input() 
//	{
//		cout << "name? ";
//		getline(cin, name);
//		cout << "id?";
//		cin >> id;
//		cout << "score? "; 
//		cin >> score;
//	}
//
//	void output() 
//	{
//		cout <<left<< "name: " << name << "\tid: " << id << "\tscore: " << score << endl;
//	}
//}; int main() 
//{
//	student s;
//	s.input();
//	s.output();
//
//	system("pause");
//	return 0;
//
//}