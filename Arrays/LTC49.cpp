/*--------Medium-----------*/

//////// Question number 54.

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int col_start = 0, row_start = 0, row_end = matrix.size() - 1, col_end = matrix[0].size() - 1;
    vector<int> answer;

    while (col_start <= col_end && row_start <= row_end)
    {
        for (int i = col_start; i <= col_end && row_start <= row_end; i++)
        {
            answer.push_back(matrix[row_start][i]);
        }
        row_start++;

        for (int i = row_start; i <= row_end && col_start <= col_end; i++)
        {
            // cout << i << " ";
            answer.push_back(matrix[i][col_end]);
        }
        col_end--;

        for (int i = col_end; i >= col_start and row_start <= row_end; i--)
        {
            answer.push_back(matrix[row_end][i]);
        }
        row_end--;

        for (int i = row_end; i >= row_start && col_start <= col_end; i--)
        {
            answer.push_back(matrix[i][col_start]);
        }
        col_start++;
    }

    return answer;
}

// vector<int> spiralOrder(vector<vector<int>> &matrix)
// {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int top = 0, left = 0;
//     int bottom = m - 1, right = n - 1;
//     vector<int> result;
//     while (top <= bottom && left <= right)
//     {
//         for (int i = left; i <= right && top <= bottom; i++)
//         {
//             result.push_back(matrix[top][i]);
//         }
//         top++;

//         for (int i = top; i <= bottom && left <= right; i++)
//         {
//             result.push_back(matrix[i][right]);
//         }
//         right--;

//         for (int i = right; i >= left && top <= bottom; i--)
//         {
//             result.push_back(matrix[bottom][i]);
//         }
//         bottom--;

//         for (int i = bottom; i >= top && left <= right; i--)
//         {
//             result.push_back(matrix[i][left]);
//         }
//         left++;
//     }
//     return result;
// }

int main()
{
    vector<vector<int>> matrix = {{7}, {9}, {6}};
    vector<int> answer = spiralOrder(matrix);

    for (auto element : answer)
    {
        cout << element << " ";
    }

    return 0;
}