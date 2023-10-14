/* Find the row with maximum number of one  */

#include <bits/stdc++.h>
using namespace std;

/* Using binary search */

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int maxi = INT_MIN, row = -1;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1, ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[i][mid] == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (ans != -1 and m - ans > maxi)
            row = i;
    }
    return row;
}

/* Using Optimal solution O(m+n) */

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int i = 0;
    int j = m - 1;
    int max = 0, index = -1;
    int cnt = 0;

    while (i < n && j >= 0)
    {
        if (arr[i][j] == 1)
        {
            cnt++;
            j--;
        }
        else
        {
            i++;
            j = m - 1;
            cnt = 0;
        }

        if (cnt > max)
        {
            max = cnt;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 0},
                               {1, 1, 1},
                               {1, 1, 1},
                               {0, 0, 0},
                               {0, 1, 1},
                               {1, 1, 1},
                               {0, 0, 0},
                               {0, 1, 1},
                               {1, 1, 1}};

    cout << rowWithMax1s(arr, 3, 9) << endl;

    return 0;
}