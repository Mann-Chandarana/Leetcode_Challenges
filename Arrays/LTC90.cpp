/* 2643. Row With Maximum Ones */

#include <bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &v)
{
    int onecount = 0;
    int rowidx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
                count++;
        }
        if (onecount < count)
        {
            onecount = count;
            rowidx = i;
        }
    }
    return {rowidx, onecount};
}

int main()
{
    return 0;
}