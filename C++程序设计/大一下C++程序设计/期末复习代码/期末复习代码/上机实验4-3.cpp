
//1、定义一个score类，保存每个学生的成绩
//2、读入附件的数据，每行数据转换到score对象，然后保存为随机文件。数据成员不能用string类型。
//3、编写一个功能菜单，可连续操作：
//(1)Append Data : 新增学生成绩，保存到随机文件的最后
//(2)Update Data : 输入学生的学号，可修改成绩，并且把新成绩保存到随机文件。如果学生不存在，要有提示
//(3)Delete Data : 输入学生的学号，删除该学生的成绩。如果学号不存在，要有提示信息。只删除学生信息，不移动数据。
//(4)Print Data : 按总分从高到低显示全部学生的成绩，注意要对齐
//(5)Defrag Data : 碎片整理。随机文件经过删除后，会有一些空间没使用，碎片整理就是读入随机文件，把有效数据保存到一个新的文件，再把原来的文件删除。
//以上每步操作都需要单独打开文件，读写完毕要及时关闭文件。

/*评分标准
不用随机文件来保存数据，扣30分
*/
//#include<cstring>
//#include<fstream>
//#include<iomanip>
//#include<iostream>
//#include <string>
//
//const char* const RandomFileName = "score.dat";
//
//using namespace std;
//
//
//class MyInput
//{
//private:
//	string data[10];
//	int len;
//public:
//	MyInput(string in = "")  // 把输入的字符串按逗号分成单独的字符串
//	{
//		int j = 0;
//		string temp = "";
//		len = 0;
//		for (int i = 0; i < in.size(); i++)
//		{
//			if (in[i] == ',')
//			{
//				data[j++] = temp;
//				temp = "";
//			}
//			else
//				temp = temp + in[i];
//		}
//
//		data[j] = temp;
//		len = j + 1;
//	}
//
//	string GetInput(int index)
//	{
//		return data[index];
//	}
//
//	int GetLen()
//	{
//		return len;
//	}
//};
//
////把s2复制到s1，如果直接用 strcpy会出错。会出错那就自己写个函数
//void MyCopy(char* s1, string s2)
//{
//	for (int i = 0; i < s2.size(); i++)
//		s1[i] = s2[i];
//	s1[s2.size()] = '\0';   //注意要加上结束符
//}
//
//class Score
//{
//private:
//	char no[10]{ 0 }, name[10]{ 0 };
//	int score[3];
//public:
//	Score(string s = "")
//	{
//		MyInput in(s);
//		if (in.GetLen() == 5)  //每行应该有5个数据
//		{
//			MyCopy(no, in.GetInput(0));
//			MyCopy(name, in.GetInput(1));
//			score[0] = stoi(in.GetInput(2));
//			score[1] = stoi(in.GetInput(3));
//			score[2] = stoi(in.GetInput(4));
//		}
//	}
//	char* GetName()
//	{
//		return name;
//	}
//	char* GetNo()
//	{
//		return no;
//	}
//
//	void SetName(char* _name)
//	{
//		strcpy(name, _name);
//	}
//	void SetNo(char* _no)
//	{
//		strcpy(no, _no);
//	}
//	int TotalScore()
//	{
//		return score[0] + score[1] + score[2];
//	}
//	void Display()
//	{
//		cout << no << "\t" << name << "\t" << score[0] << "\t" << score[1] << "\t" << score[2] << endl;
//	}
//};
//
////把顺序文件转换为随机文件
//void Seq2Ramdom(const char* sName)
//{
//
//	ifstream inFile(sName, ios::in);
//	if (!inFile)
//	{
//		cout << "Open file error!" << endl;
//		exit(1);
//	}
//	ofstream outFile(RandomFileName, ios::out | ios::binary);
//	if (!outFile)
//	{
//		cout << "Open random file error!" << endl;
//		exit(1);
//	}
//	string s;
//
//	while (getline(inFile, s))
//	{
//		Score score(s);
//		if (score.GetName()[0] != '\0') //判断是否是有效名字
//			outFile.write(reinterpret_cast<char*>(&score), sizeof(score));
//	}
//
//	inFile.close();
//	outFile.close();
//}
//
////显示随机文件的内容
//void ShowRamdomFile()
//{
//	ifstream inFile(RandomFileName, ios::in | ios::binary);
//	if (!inFile)
//	{
//		cout << "Open random file error!" << endl;
//		exit(1);
//	}
//
//	Score score("");
//	//计算记录个数
//	inFile.seekg(0, ios::end);
//	int record = inFile.tellg() / sizeof(score);
//	inFile.seekg(0, ios::beg);  //把文件指针移动开头
//	for (int i = 0; i < record; i++)
//	{
//		inFile.read(reinterpret_cast<char*>(&score), sizeof(score));
//		score.Display();
//	}
//	inFile.close();
//}
//
//void DeleteFromFile()
//{
//	char _no[10];
//
//	cout << "Input no to be deleted:";
//	cin >> _no;
//
//	fstream inFile(RandomFileName, ios::in | ios::out | ios::binary);
//
//	if (!inFile)
//	{
//		cout << "Open random file error!" << endl;
//		exit(1);
//	}
//	Score score("");
//	//计算记录个数
//	inFile.seekg(0, ios::end);
//	int record = inFile.tellg() / sizeof(score);
//	inFile.seekg(0, ios::beg);  //把文件指针移动开头
//	for (int i = 0; i < record; i++)
//	{
//		int p = inFile.tellg();
//		inFile.read(reinterpret_cast<char*>(&score), sizeof(score));
//		if (strcmp(score.GetNo(), _no) == 0)
//		{
//			cout << "delete " << _no << "  pos:" << p << endl;
//			char a[20];
//			sprintf(a, "%d", i);
//			score.SetNo(a);
//			//现在指针是在被删除记录的下一个记录位置
//			//写回原来的位置，就要把指针向后移动一个单位
//			//inFile.seekg(p,ios::beg);
//			inFile.seekg(-sizeof(score), ios::cur);
//			inFile.write(reinterpret_cast<char*>(&score), sizeof(score));
//			break;
//		}
//	}
//	inFile.close();
//}
//
//int main()
//{
//	//Seq2Ramdom("score.txt");
//	ShowRamdomFile();
//	DeleteFromFile();
//	ShowRamdomFile();
//}