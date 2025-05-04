#include<iostream>
using namespace std;



int A[200];
int B[200];

void Play(int n,int n_A,int n_B)
{
	int CountA = 0;
	int CountB = 0;

	for (int i = 0; i < n_A; i++)
	{
		cin >> A[i];
	}

	for (int i = n_A; i < n; i++)
	{
		for (int j = 0; j < n_A; j++)
		{
			if ((i % n_A) == j)
			{
				A[i] = A[j];
			}
		}
	}

	for (int i = 0; i < n_B; i++)
	{
		cin >> B[i];
	}

	for (int i = n_B; i < n; i++)
	{
		for (int j = 0; j < n_B; j++)
		{
			if ((i % n_B) == j)
			{
				B[i] = B[j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (A[i] == B[i])
		{
			
		}
		else
		{
			if (A[i] == 0)
			{
				if (B[i] == 1||B[i]==4)
				{
					CountB++;
					
					
				}
				else
				{
					CountA++;
				
				}

			}
			else if (A[i] == 1)
			{
				if (B[i] == 2 || B[i] == 4)
				{
					CountB++;
					
					
				}	
				else
				{
					CountA++;
					
					
				}
			}
			else if (A[i] == 2)
			{
				if (B[i] == 3||B[i]==0)
				{
					CountB++;
					
					
				}
				else
				{
					CountA++;
					
					
				}
			}
			else if(A[i]==3)
			{
				if (B[i] == 0 || B[i] == 1)
				{
					CountB++;
					
					
				}
				else
				{
					CountA++;
					
					
				}
			}
			else
			{
				if (B[i] == 2 || B[i] == 3)
				{
					CountB++;
					
					
				}
				else
				{
					CountA++;
					
					
				}
			}
			
			
		}
	}

	cout << CountA << " " << CountB << endl;



}

int main()
{
	int N, N_A, N_B;
	cin>> N>>N_A>> N_B;
	Play(N, N_A, N_B);



	system("pause");
	return 0;
}
