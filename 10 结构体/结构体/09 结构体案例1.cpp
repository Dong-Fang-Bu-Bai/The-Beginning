#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//�ֱ�����ʦ��ѧ���Ľṹ��

struct Student
{
	string Sname;
	int score;
};


struct Teacher
{
	string Tname;
	struct Student sArray[5];
};


//����дΪ��ʦ���Ƹ�ֵ��Ϊѧ�����ֺͳɼ���ֵ�ĺ���
void distribution( struct Teacher tArray[3],int len1)
{
	
	for (int i = 0; i < len1; i++)
	{
		char a = 'A';
		tArray[i].Tname = char(a+ i);
		for (int j = 0; j < 5; j++)
		{
			char b = 'A';
			tArray[i].sArray[j].Sname = char(b + j);
			int random = rand() % 61 + 40;
			tArray[i].sArray[j].score = random;
		}
	}
	
}





//����д����������ݵĺ���
void printall( struct Teacher tArray[3], int len1)
{
	for (int i = 0; i < len1; i++)
	{
		cout << "��ʦ����_" << tArray[i].Tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "ѧ������_" << tArray[i].sArray[j].Sname
				<< "  " << "�ɼ���" << tArray[i].sArray[j].score
				<< endl;

		}
	}
}



int main9()
{
	//�趨���������
	srand((unsigned int)time(NULL));

   //����Ҫ������ʦ��ѧ���Ľṹ������

	struct Teacher tArray[3];
	

	

	//����Ҫ�������Ȳ���len1��len2���ֱ������ʦ��ѧ��������Ԫ������
	int len1 = sizeof(tArray) / sizeof(tArray[0]);
	
	

	//����ֱ����ú���

	distribution(tArray, len1);

	printall(tArray, len1);


	system("pause");
	return 0;

}