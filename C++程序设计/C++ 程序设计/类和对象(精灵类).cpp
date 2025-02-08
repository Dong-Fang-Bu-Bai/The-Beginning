//�����һ��������Spirit�����ԱҪ�����£�
//
//1.����private��data members
//
//��1��name����������֣���������
//
//��2��x�������λ������X���ֵ����������
//
//��3��y�������λ������Y���ֵ����������
//
//��4��health�������health��������ֵ��Ϊ1000
//
//��5��aliveState�����������״̬����ֵ��Ϊtrue
//
//2.���о�̬���ݳ�Ա
//
//��1��number����¼�Ѿ������ľ�����������ֵΪ0
//
//��2��alivenumber����¼����״̬Ϊtrue�ľ�����������ֵΪ0
//
//3.���е�public��member function
//
//��1�����캯��1���޲����Ĺ��캯��������������󲢳�ʼ����number + 1��alivenumber + 1
//
//��2�����캯��2���в����Ĺ��캯������������ֺ�λ�����꣩���������󲢳�ʼ����number + 1��alivenumber + 1
//
//��3��takeDamage������ʵ�ֶԾ�����˺���������Ҫ�ж�aliveState��ֵ�������true����health - damage�����˺���ľ���health <= 0����health��Ϊ0����aliveState��Ϊfalse��alivenumber - 1
//
//��4��setPosition��������Ҫ�ж���λ���Ƿ���0 - 200֮�䣬����ǵĻ��������þ�����λ�ã����򱨴��Ա���ԭλ�ã������������ʾ��Ϣ��
//
//��5��getPositionX���������ؾ����λ������X
//
//��6��getPositionY���������ؾ����λ������Y
//
//��7��getName���������ؾ��������
//
//��8��getHealth���������ؾ��������ֵ
//
//��9��getNumber���������ؾ�������һ���ж��پ���
//
//��10��getAliveNumber���������ؾ�������һ���ж���alive�ľ���
//
//��11��getInfo�������������ĸ�����Ϣ����������������ֵ������״̬�������
//
//4.main��������
//
//��1����main������ͨ����ͬ�Ĺ��캯��������ͬ���顣
//
//��2������takeDamage���������Ծ��������״̬��
//
//��3���������ж�������к���������������λ�ã��������ĸ�����Ϣ�ȡ�
//
//��4�����ö����������10�����鲢��ʼ��
//
//��5���������ģ��10������¼������Ծ���i��k���˺�����������Ϣ������¼�������������ж���Ļ�����Ϣ
//
//5.ѡ������
//
//��1����������Ļ���÷��ţ����硰 * ���������飬�Ծ�������Ϊ��Ļ���к��У�����Ļ�ϡ����������о���
//
//��2����Ӧ�����¼�����Ļ����չ����Ӧ�仯�������������飬���������������ƶ�
//
//��3����Ӿ����¼����κ���ϣ������߱��ļ���
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int number = 1;
int alivenumber = 1;



//����������
class Spirit
{
public:
	Spirit()
	{
		
	}
	Spirit(string name1, int X1, int Y1)
	{
		name = name1;
		X = X1;
		Y = Y1;
	}
	void takeDamage(int damage)
	{
		if (health > damage)
		{
			health = health - damage;
			state = 0;
		}
		else
		{
			health = 0;
			aliveState = false;
			alivenumber--;
			state = 0;
		}
	}
	void setPosition(int x, int y)
	{
			X = x;
			Y = y;
	}
	void getPositionX()
	{
		cout <<"X���꣺" << X << endl;
	}
	void getPositionY()
	{
		cout<<"Y���꣺" << Y << endl;
	}
	void getName()
	{
		
		cout <<"������" << name << endl;
	}
	void getHealth()
	{
		cout<<"����ֵ��" << health << endl;
	}
	static void getNumber()
	{
		cout << number << endl;
	}
	static void getAliveNumber()
	{
		cout << alivenumber << endl;
	}
	void getInfo()
	{
		getName();
		getHealth();
		getPositionX();
		getPositionY();
		cout <<"����״̬��" << aliveState << endl;
	}

	bool state = 1;
private:
	string name;
	int X = rand() % 201;
	int Y = rand() % 201;
	int health = 1000;
	bool aliveState = true;

	
};



int main5()
{
	//�趨���������
	srand((unsigned int)time(NULL));

	Spirit array[100];

	
	while (1)
	{
		cout << "�����������������֣���ɶԾ�������Ĵ���!" << endl;
		cout << "1.����һ��������û��������·��С����" << endl;
		cout << "2.����һ���Ҹ������������мҵ�С����" << endl;
		cout << "3.�鿴һλС�����ȫ����Ϣ" << endl;
		cout << "4.����ΪһλС�����ҵ���" << endl;
		cout << "5.����һ���Ӵ���ʮ�����������С���鲢������������" << endl;
		cout << "6.������������а�����������֣��㴴���С������ʮ��������" << endl;
		cout << "7.�����˻㱨�������絮�������پ��飬���ж��پ�����Ȼ���ֵ�������" << endl;
		cout << "8.�˳���������" << endl;
		cout << "���������֣�" << endl;

		int i = 0;
		cin >> i;

		switch (i)
		{
		case 1:
		{
			cout << "�ɹ���" << endl;
			cout << "���Ǿ���������ڹ��ĵ�" << endl;
			cout << number << endl;
			cout << "������" << endl;
			number++;
			alivenumber++;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			string name;
			int X;
			int Y;
			cin >> name >> X >> Y;
			if (X>= 0 && X <= 200 && Y >= 0 && Y <= 200)
			{
				Spirit s(name, X, Y);
				array[number -1] = s;
				cout << "�ɹ���" << endl;
				cout << "���Ǿ���������ڹ��ĵ�" << endl;
				cout << number << endl;
				cout << "������" << endl;
				number++;
				alivenumber++;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "��ѽ������ˣ�������һ�Σ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 3:
		{
			cout << "���Ѵ�����" << endl;
			cout << number -1 << endl;
			cout << "������" << endl;
			cout << "������Ҫ���ʵľ�������" << endl;
			int i;
			cin >> i;
			array[i - 1].getInfo();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			cout << "���Ѵ�����" << endl;
			cout << number - 1 << endl;
			cout << "������" << endl;
			cout << "������Ҫ���ʵľ�������" << endl;
			int i;
			cin >> i;
			cout << "������Ҫ�ı�����꣺" << endl;
			while (1)
			{
				int x, y;
				cin >> x >> y;
				if (x >= 0 && x <= 200 && y >= 0 && y <= 200)
				{
					array[i-1].setPosition(x, y);
					cout << "���ĳɹ���" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					cout << "�������λ�ò����Ϲ淶������������" << endl;
				}
				
			}
			break;
		}
		case 5:
		{
			cout << "����10��С����ɹ���" << endl;
			number = number + 10;
			alivenumber = alivenumber + 10;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			if (alivenumber < 11)
			{
				cout << "С�����������㣬�����³��ԣ�" << endl;
			}
			else
			{
				for (int k = 0; k < number - 1; k++)
				{
					array[k].state = 1;
				}
				for (int i = 0; i < 10; i++)
				{
					while (1)
					{
						int j = rand() % (number - 1);
						if (array[j].state)
						{
							array[j].takeDamage(rand() % 1500 + 1);
							break;
						}
					}
				}
				cout << "а��������С�����ǿ��ܰ���" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			cout << "�������絮��������������" << number - 1 << endl;
			if (alivenumber > 1)
			{
				cout << "��Ȼ���ֵ������ŵľ���������" << alivenumber - 1 << endl;
			}
			else
			{
				alivenumber = 1;
				cout << "������������Ϳ̿���ڴ���Υ��������" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			cout << "�����ټ���" << endl;
			system("pause");
			return 0;
		}
		default:
			cout << "��ѽ������ˣ�������һ�Σ�" << endl;
			system("pause");
			system("cls");
		}

		
	}


	
}
//4.main��������
//
//��1����main������ͨ����ͬ�Ĺ��캯��������ͬ���顣
//
//��2������takeDamage���������Ծ��������״̬��
//
//��3���������ж�������к���������������λ�ã��������ĸ�����Ϣ�ȡ�
//
//��4�����ö����������10�����鲢��ʼ��
//
//��5���������ģ��10������¼������Ծ���i��k���˺�����������Ϣ������¼�������������ж���Ļ�����Ϣ
//
//5.ѡ������
//
//��1����������Ļ���÷��ţ����硰 * ���������飬�Ծ�������Ϊ��Ļ���к��У�����Ļ�ϡ����������о���
//
//��2����Ӧ�����¼�����Ļ����չ����Ӧ�仯�������������飬���������������ƶ�
//
//��3����Ӿ����¼����κ���ϣ������߱��ļ���