//https : practice.geeksforgeeks.org / problems / row - with - max - 1s0023 / 1 ? utm_source = youtube &utm_medium = collab_striver_ytdescription &utm_campaign = row - with - max - 1s

#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int r = 0, c = m - 1;

    int max_row_indices = -1;
    while (r < n and c >= 0)
    {
        if (arr[r][c] == 1)
        {
            max_row_indices = r;
            c--;
        }
        else
        {
            r++;
        }
    }
    return max_row_indices;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    cout << rowWithMax1s(arr, 4, 4);
    return 0;
}