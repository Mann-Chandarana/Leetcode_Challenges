/* Geeks for Geeks :- Floyd Warshall */

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity :- O(n^3)
Space complexity :- O(n^2)

multisource to multidestination shortest path algorithm
*/

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // To check whether the graphs contains the negative cycle or not
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            // contains negative cycle
            return;
        }
    }

    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main()
{
    return 0;
}