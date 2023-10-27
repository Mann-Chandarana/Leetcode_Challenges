/*--------  Medium --------*/

/*- Maximal Network Rank -*/

//////// Question number 1615.

#include <bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<int> count(n, 0);
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];

        count[u]++;
        count[v]++;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    int max_rank = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int rank = count[i] + count[j];

            if (matrix[i][j] == 1)
                rank -= 1;
 
            max_rank = max(max_rank, rank);
        }
    }
    return max_rank;
}
int main()
{
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    cout << maximalNetworkRank(5, roads) << endl;
    return 0;
}