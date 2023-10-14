/*-------- Hard -----------*/

/*- Search a 2D Matrix II -*/

//////// Question number 240.

#include <bits/stdc++.h>
using namespace std;

/* Main points here is
 1) Start from either row = n-1 and col = 0
     or from
 2) Start from either row =0 and col = m-1
 */

/* Approach -1)
 -- Start from either row =0 and col = m-1
 */

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    int row = 0, col = m - 1;

    while (row < n and col >= 0)
    {
        if (matrix[row][col] == target)
            return true;

        else if (matrix[row][col] > target)
            col--;
        else
            row++;
    }
    return false;
}

/* Approach -2)
-- Start from either row = n-1 and col = 0
 */

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    int row = n - 1, col = 0;

    while (row >= 0 and col < m)
    {
        if (matrix[row][col] == target)
            return true;

        else if (matrix[row][col] > target)
            row--;
        else
            col++;
    }
    return false;
}

int main()
{
    return 0;
}