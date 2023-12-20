/*--------  Hard --------*/

/*- Number of Possible Sets of Closing Branches -*/

//////// Question number 2959.

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define ll long long
#define all(v) v.begin(), v.end()

///////// Here we are add the edge of that mask

bool isWithDistanceK(int mask, int n, vector<vi> graph, int maxDistance)
{
    int dis = 0;
    unordered_map<int, bool> taken;

    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            taken[i] = true;

        for (int k = 0; k < n; k++)
        {
            if (taken.count(k))
            {
                for (int i = 0; i < n; i++)
                {
                    if (taken.count(i))
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (taken.count(j))
                                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (taken.count(i))
        {
            for (int j = 0; j < n; j++)
            {
                if (taken.count(j))
                    dis = max(dis, graph[i][j]);
            }
        }
    }

    return dis <= maxDistance;
}

int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
{
    vector<vi> graph(n, vi(n, 1e4));

    for (int i = 0; i < n; i++)
        graph[i][i] = 0;

    for (auto &road : roads)
    {
        int u = road[0], v = road[1], w = road[2];

        graph[u][v] = min(graph[u][v], w);
        graph[v][u] = min(graph[v][u], w);
    }

    ////////////// Finding all the possible possiblities

    int ways = (1 << n), ans = 1;

    for (int mask = 1; mask < ways; mask++)
        ans += isWithDistanceK(mask, n, graph, maxDistance);

    return ans;
}

int main()
{
    return 0;
}