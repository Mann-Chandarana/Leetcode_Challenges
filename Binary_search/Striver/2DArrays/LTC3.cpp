/*-------- Hard -----------*/

/*- Find a Peak Element II -*/

//////// Question number 1901.

#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    int start_row = 0, end_row = n - 1;

    while (start_row <= end_row)
    {
        int mid = start_row + (end_row - start_row) / 2;

        int maxRow = 0, ans = INT_MIN;

        /* To find the maximum element in the given row */
        for (int i = 0; i < mat[mid].size(); i++)
        {
            if (mat[mid][i] > ans)
            {
                ans = mat[mid][i];
                maxRow = i;
            }
        }

        if (mid == 0 and mat[mid][maxRow] > mat[mid + 1][maxRow])
            return {mid, maxRow};

        else if (mid == n - 1 and mat[mid][maxRow] > mat[mid - 1][maxRow])
            return {mid, maxRow};

        else if (mat[mid][maxRow] > mat[mid + 1][maxRow] and mat[mid][maxRow] > mat[mid - 1][maxRow])
            return {mid, maxRow};

        else if (mat[mid][maxRow] < mat[mid + 1][maxRow])
            start_row = mid + 1;

        else
            end_row = mid - 1;
    }
    return {-1, -1};
}

int main()
{
    return 0;
}