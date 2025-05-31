//读出一个作业.cpp 文件，删除全部注释内容，即以“/*…*/”相括的文本和以“//”开始到行末的 文本，生成一个新的.cpp 文件。

//#define _CRT_SECURE_NO_WARNINGS
//
//#include<fstream>
//#include<iostream> 
//#include<string>
//using namespace std;
//
////前置声明
//void trans(const char *, const char *);
//
//
//
//int main()
//{
//	const char* icpp = "TypeID代码.cpp";
//	const char* ocpp = "TypeID代码去注释版.cpp";
//	trans(icpp, ocpp); 
//	system("pause");
//	return 0;
//}
//
//
//
//void trans(const char* icpp, const char* ocpp)
//{
//	fstream incpp(icpp, ios::in);
//
//	fstream outcpp(ocpp, ios::out);
//
//	char c, flag = '\0'; 
//
//	while (incpp.get(c))
//	{
//		if (c == '/')
//		{
//			incpp.get(c); 
//
//			if (c != '/' && c != '*')
//				outcpp << "/" << c; //一般除号，正常输出
//			else
//			{
//				if (c == '/')
//				{
//					while (c != '\n') 
//						incpp.get(c); 
//					outcpp << c;
//				}
//				else
//				{
//		
//					// 处理 /* ... */ 注释
//					bool endOfComment = false;
//					while (!endOfComment)
//					{
//						if (!incpp.get(c)) 
//							break; // 文件结束，跳出循环
//						if (c == '*') 
//						{
//							if (!incpp.get(c))
//								break; // 文件结束
//							if (c == '/') 
//							{
//								endOfComment = true;
//							}
//								
//					}
//					}
//		
//
//				}
//			}
//		}
//		else
//		{
//			outcpp << c;
//		}
//			
//	}
//	incpp.get(c); //去掉多余空格
//	incpp.close();
//	
//
//	outcpp.close();
//}

//#include<iostream>
//#include<cstdlib>
//#include<fstream>
//#include<iomanip>
//#include<string>
//
//using namespace std;
//void removeComments(const string& inputFile, const string& outputFile) {
//    ifstream inFile(inputFile);
//    ofstream outFile(outputFile,ios::trunc);
//
//    if (!inFile.is_open()) {
//        cerr << "无法打开输入文件: " << inputFile << endl;
//        exit(EXIT_FAILURE);
//    }
//
//    if (!outFile.is_open()) {
//        cerr << "无法创建输出文件: " << outputFile << endl;
//        exit(EXIT_FAILURE);
//    }
//
//    string lines;
//    string linesWithoutComments;
//    bool inBlocks = false;
//
//    while (getline(inFile, lines)) 
//    {
//        if (inBlocks) 
//        {
//            size_t blockEnd = lines.find("*/");
//            if (blockEnd != string::npos) {
//                lines = lines.substr(blockEnd + 2);
//                inBlocks = false;
//            }
//            else 
//			  {
//                continue;
//            }
//        }
//
//        size_t blockStart = lines.find("/*");
//        size_t lineStart = lines.find("//");
//
//        if (blockStart != string::npos && (lineStart == string::npos || blockStart < lineStart)) {
//            linesWithoutComments += lines.substr(0, blockStart);
//            inBlocks = true;
//        }
//        else if (lineStart != string::npos) {
//            linesWithoutComments += lines.substr(0, lineStart);
//        }
//        else 
//        {
//            linesWithoutComments += lines;
//        }
//
//        if (!inBlocks) {
//            linesWithoutComments += "\n";
//        }
//    }
//
//    outFile << linesWithoutComments;
//
//    inFile.close();
//    outFile.close();
//}
//
//int main() 
//{
//    string inputFile = "TypeID代码.cpp";
//    string outputFile = "TypeID代码去注释版.cpp";
//    removeComments(inputFile, outputFile);
//    return 0;
//}