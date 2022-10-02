//////// Question number 74.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row_index = 0;
    int col_index = matrix[0].size() - 1;
    while (col_index >= 0 && row_index < matrix.size())
    {
        // cout << row_index << " " << col_index << endl;
        if (matrix[row_index][col_index] == target)
        {
            return true;
        }
        else if (matrix[row_index][col_index] < target)
        {
            row_index++;
        }
        else
        {
            col_index--;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    cout << searchMatrix(matrix, 3) << endl;
    return 0;
}