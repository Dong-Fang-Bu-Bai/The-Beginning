//【4】       游戏的目的是用最少的步数将上图中白子和黑子的位置进行交换：游戏的规则是：(1)一次只能移动一个棋子；(2)棋子可以向空格中移动，也可以跳过一个对方的棋子进入空格，但不能向后跳，也不能跳过两个子。请用计算机实现上述游戏。例如：
//
//有三个白子和三个黑子如下图布置：
//
//○ ○ ○ _ ● ● ●
//
//游戏的目的是用最少的步数将上图中白子和黑子的位置进行交换：
//
//● ● ● _ ○ ○ ○
//
//黑白子可用不同的符号来表示。
#include<iostream>
using namespace std;
unsigned _index = 2;//index=3，3表示起始时"_"所在位置，000_111,这里写2就是先让0先移动，00_0111;
void show(char* Array) {//用于显示数组
	for (int i = 0; i < (7); i++)
		cout << Array[i];
	cout << endl;
}
bool GameOver(char* Array)//判断游戏是否结束
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (*(Array + i) == '0') return false;
	}
	for (i = 6; i >= 4; i--)
	{
		if (*(Array + i) == '1') return false;
	}
	return true;
}
void SwapPos(char* Array, unsigned& _index) {//传引用，为了随时改变本身的参数
	// _??????时
	if (_index == 0)
	{
		while (1)//最多执行两次 _01  或者_10,
		{//如果_旁边为1直接将1换位
			if (Array[_index + 1] == '1') {
				Array[_index] = '1';
				Array[_index + 1] = '_';
				_index = 1;
				break;
			}
			else {//_01
				Array[_index] = '1';
				Array[_index + 2] = '_';
				_index = 2;
				break;
			}
		}
		show(Array);
	}
	/*  ??????_时 */
	if (_index == 6)
	{
		while (1)//最多执行两次 01_  或者10_,
		{//如果_旁边为1直接将1换位
			if (Array[_index - 1] == '0') {
				Array[_index] = '0';
				Array[_index - 1] = '_';
				_index = 5;
				break;
			}
			else {//_01
				Array[_index] = '0';
				Array[_index - 2] = '_';
				_index = 4;
				break;
			}
		}
		show(Array);
	}
	//0_1情况  此时0想向右移动，而1想向左移动
	if (Array[_index - 1] == '0' && Array[_index + 1] == '1')
	{
		if (_index < 3) {//_index小于4时0先右移
			Array[_index] = '0';
			Array[_index - 1] = '_';
			_index--;
		}
		else {//_index大于3时1向左边移动
			Array[_index] = '1';
			Array[_index + 1] = '_';
			_index++;
		}
		show(Array);
	}
	// 1_0时 只有旁边的数可能移动，而且是不可能同时出现相向的 
	if (Array[_index - 1] == '1' && Array[_index + 1] == '0')
	{
		if (_index < 3) {//_index小于3先判断_的右边（也是为了防止越界）1_00是不可能出现的，因为小于4，还没有结束，0和0是不能在一起的
			Array[_index + 2] = '_';
			Array[_index] = '1';
			_index = _index + 2;
		}
		else {//_index大于3先判断_的左边边 由上面推理得只能是01_0
			Array[_index] = '0';
			Array[_index - 2] = '_';
			_index = _index - 2;
		}
		show(Array);
	}
	//0_0
	if (Array[_index - 1] == '0' && Array[_index + 1] == '0')//!!直接写连等‘0’不识别
	{
		if (Array[_index + 2] == '1') {//0_01
			Array[_index] = '1';
			Array[_index + 2] = '_';
			_index = _index + 2;
		}
		else {//0_00 时，左边的0右移
			Array[_index] = '0';
			Array[_index - 1] = '_';
			_index = _index - 1;
		}
		show(Array);
	}
	//1_1
	if (Array[_index - 1] == '1' && Array[_index + 1] == '1')
	{
		if (Array[_index - 2] == '0') {//01_1
			Array[_index] = '0';
			Array[_index - 2] = '_';
			_index = _index - 2;
		}
		else {//11_1
			Array[_index] = '1';
			Array[_index + 1] = '_';
			_index = _index + 1;
		}
		show(Array);
	}
}
int main4() {
	/*数组初始化*/
	char Array[7] = { '0','0','_','0','1','1','1' };
	/*用于显示初始化的数组*/
	show(Array);
	/*移动棋子*/
	while (!GameOver(Array)) {
		SwapPos(Array, _index);
	}
	return 0;
}
