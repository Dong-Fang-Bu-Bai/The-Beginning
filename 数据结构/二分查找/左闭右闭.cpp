using namespace std;

class Solution
{
public:
	int Search(int a[], int size,int num)
	{
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (num < a[middle])
			{
				right = middle - 1;
			}
			else if (num > a[middle])
			{
				left = middle + 1;
			}
			else
			{
				return middle;
			}
			
		}
		return -1;
	}
};