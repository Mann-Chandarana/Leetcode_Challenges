/*--------Medium-----------*/

/*- Find the City With the Smallest Number of Neighbors at a Threshold Distance -*/

//////// Question number 1334.

#include <bits/stdc++.h>
using namespace std;

/* Used FloydWarshall algorithm */

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

    for (auto it : edges)
    {
        distance[it[0]][it[1]] = it[2];
        distance[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++)
        distance[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                    continue;

                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;
    for (int city = 0; city < n; city++)
    {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++)
        {
            if (distance[city][adjCity] <= distanceThreshold)
                cnt++;
        }

        if (cnt <= cntCity)
        {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}

int main()
{
    return 0;
}