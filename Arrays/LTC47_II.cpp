/*--------Medium-----------*/

//////// Question number 73.

#include <bits/stdc++.h>
using namespace std;

/**Time complexity of both the algorithm is O(M*N)**/

/**************Space complexity is equal to O(1)**************/

// void setZeroes(vector<vector<int>> &matrix)
// {
//     int col0 = 1, rows = matrix.size(), columns = matrix[0].size();
//     for (int i = 0; i < rows; i++)
//     {
//         if (matrix[i][0] == 0)
//             col0 = 0;
//         for (int j = 1; j < columns; j++)
//         {
//             if (matrix[i][j] == 0)
//                 matrix[i][0] = matrix[0][j] = 0;
//         }
//     }
//     for (int i = rows - 1; i >= 0; i--)
//     {
//         for (int j = columns - 1; j >= 1; j--)
//         {
//             if (matrix[i][0] == 0 || matrix[0][j] == 0)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//         if (col0 == 0)
//             matrix[i][0] = 0;
//     }
// }

/**************Space complexity is equal to O(N+M)**************/

void setZeroes(vector<vector<int>> &matrix)
{
    int rowsize = matrix.size();
    int columnsize = matrix[0].size();
    vector<int> rowmarker(rowsize, 1);
    vector<int> columnmarker(columnsize, 1);
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < columnsize; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowmarker[i] = 0;
                columnmarker[j] = 0;
            }
        }
    }
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < columnsize; j++)
        {
            if (rowmarker[i] == 0 or columnmarker[j] == 0)
                matrix[i][j] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);

    return 0;
}