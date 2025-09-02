using namespace std;

class Solution
{
public:
	int Search(int a[], int size, int num)
	{
		int left = 0;
		int right = size;           //区别一
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (num < a[middle])
			{
				right = middle ;   //区别二
			}
			else if (num > a[middle])
			{
				left = middle + 1;  
			}
			else  //(num==a[middle])
			{
				return middle;
			}

		}
		return -1;
	}
};

//总结：两种方式的区别在于初始时右边界的赋值；以及与中间值比较后，对右边界进行的操作。