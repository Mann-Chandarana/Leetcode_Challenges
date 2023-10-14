/* Search in sorted 2D matrix*/
#include <bits/stdc++.h>
using namespace std;

/* First approach */

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int start = 0, end = n * m - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int row_index = mid / m, col_index = mid % m;

        if (matrix[row_index][col_index] == target)
            return true;

        else if (matrix[row_index][col_index] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

/* Second approach */

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    int low = 0, high = m - 1;

    while (high >= 0 and low < matrix.size())
    {

        if (matrix[low][high] == target)
            return true;

        else if (matrix[low][high] < target)
            low++;

        else
            high--;
    }
    return false;
}

int main()
{
    return 0;
}