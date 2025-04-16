#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 递归生成矩阵
void generateMatrix(vector<vector<int>>& matrix, int x, int y, int size)
{
    if (size == 2)
    {
        matrix[x][y] = 0; // 左上角的单元格被赦免
        return;
    }

    int half = size / 2;

    //将左上角矩阵置零
    for (int i = x; i < x + half; i++)
    {
        for (int j = y; j < y + half; j++)
        {
            matrix[i][j] = 0;
        }
    }


    // 递归处理剩下三个子矩阵
    generateMatrix(matrix, x, y + half, half);      // 右上角
    generateMatrix(matrix, x + half, y, half);      // 左下角  
    generateMatrix(matrix, x + half, y + half, half); // 右下角

   
}

int main()
{
    int n;
    cin >> n;

    int size = pow(2, n);
    vector<vector<int>> matrix(size, vector<int>(size, 1)); // 初始化全1

    generateMatrix(matrix, 0, 0, size);

    // 输出矩阵
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << matrix[i][j] << (j == size - 1 ? "\n" : " ");
        }
    }

    system("pause");
    return 0;
}