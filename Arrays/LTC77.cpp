// 118 Pascal's triangle

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascals(numRows);

    for (int i = 0; i < numRows; i++)
    {
        if (i == 0)
        {
            pascals[0].push_back(1);
        }
        else if (i == 1)
        {
            pascals[1].push_back(1);
            pascals[1].push_back(1);
        }
        else
        {
            int val1 = 0, val2 = 1;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 or j == i)
                {
                    pascals[i].push_back(1);
                    continue;
                }
                int val = pascals[i - 1][val1] + pascals[i - 1][val2];
                pascals[i].push_back(val);
                val1++;
                val2++;
            }
        }
    }
    return pascals;
}

int main()
{
    vector<vector<int>> pascals = generate(5);
    for (auto row : pascals)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}