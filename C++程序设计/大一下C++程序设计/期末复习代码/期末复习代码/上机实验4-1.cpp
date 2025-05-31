//建立一个文本文件，从键盘输入一篇短文存放在文件中。短文由若干行构成，每行不超过 80 个字符。


//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	ofstream ofs("Passage.txt", ios::trunc);
//
//
//	//1.使用string
//	//string line;
//
//	//while (getline(cin, line)) 
//	//{
//	//	if (line.empty()) break; // 空行结束
//	//	if (line.length() > 80)  // 超过80字符则截断
//	//		line = line.substr(0, 80);
//	//	ofs << line << "\n";
//	//}
//
//
//	//2.使用字符数组
//	char buf[81]; // 80字符+1结尾符
//	while (cin.getline(buf, 81)) 
//	{
//		if (buf[0] == '\0') break; // 空行结束
//		ofs << buf << "\n";
//	}
//
//	ofs.close();
//
//
//
//
//	system("pause");
//	return 0;
//}
