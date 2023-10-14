/* Geeks for Geeks :- Bellman ford algorithm */

#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> distance(V, 1e8);
    distance[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (distance[u] != 1e8 and distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }
    }

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (distance[u] != 1e8 and distance[u] + w < distance[v])
            return {-1};
    }

    return distance;
}

int main()
{
    return 0;
}