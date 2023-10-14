/*--------Medium-----------*/

/*- Cheapest Flights Within K Stops -*/

//////// Question number 787.

#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];

    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    vector<int> dis(n, 1e9);
    dis[src] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > k)
            continue;

        for (auto child : adj[node])
        {
            int adjNode = child.first;
            int edW = child.second;

            if (cost + edW < dis[adjNode] and stops <= k)
            {
                dis[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    if (dis[dst] == 1e9)
    {
        return -1;
    }

    return dis[dst];
}

int main()
{
    return 0;
}