#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>>map(n,vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i][j] = 0;
            }
        }

        enum direction { right, left, up, down };

        struct Pointer {
        public:
            
            int dir;

            int index;
        } pointer;

        pointer.dir = right;

        int p = 0, q = 0;
        for (pointer.index = 1; pointer.index < (n * n + 1); pointer.index++)
        {
     /*       cout << pointer.index << endl;
            cout << p << ' ' << q << endl;*/
            map[p][q] = pointer.index;

            if ((p == 0 && q == n - 1)||( p == n-1 && q == n - 1)|| (p == n-1 && q == 0))
            {
                if (pointer.dir == right)
                {
                    pointer.dir = down;
                    p++;
                    continue;
                }
                else if (pointer.dir == left)
                {
                    pointer.dir = up;
                    p--;
                    continue;
                }
                else if (pointer.dir == up)
                {
                    pointer.dir = right;
                    q++;
                    continue;
                }
                else if (pointer.dir == down)
                {
                    pointer.dir = left;
                    q--;
                    continue;
                }
            }

            if (pointer.dir == right &&q!=n-1)
            {
                if (map[p][q + 1] != 0)

                {
                    pointer.dir = down;
                    p++;
                    continue;
                }
                else
                {

                        q++;
                        continue;
       

                }
            }

            if (pointer.dir == left &&q!=0)
            {
                if (map[p][q - 1] != 0)
                {
                    pointer.dir = up;
                    p--;
                    continue;
                }
                else
                
                {


                    q--;
                    continue;
                }
            }

            if(pointer.dir == up &&p!=0)
            {
                if ( map[p - 1][q] != 0)
                {
                    pointer.dir = right;
                    q++;
                    continue;
                }
               
            else
            {
 
                 p--;
                 continue;

            }
            }

             if (pointer.dir == down &&p!=n-1)
            {
                if (map[p + 1][q] != 0)
                {
                    pointer.dir = left;
                    q--;
                    continue;
                }
               
                else
                {


                    p++;
                    continue;

                }
            }


            
        }

        return map;
    }
} solution;

int main()
{
    solution.generateMatrix(10);

    system("pause");
}