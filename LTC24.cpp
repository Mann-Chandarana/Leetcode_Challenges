/* 1582. Special Positions in a Binary Matrix */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef vector<int> vi;

int numSpecial(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    vi rowCount(n, 0), colCount(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                rowCount[i]++, colCount[j]++;
        }
    }

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
                continue;
            else
            {
                if (rowCount[i] == 1 and colCount[j] == 1)
                    result++;
            }
        }
    }

    return result;
}

int main()
{
    return 0;
}