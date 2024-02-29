/*-------- Medium --------*/

/*- Cheapest Flights Within K Stops -*/

//////// Question number 787.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pii> adj[n];

    for (auto path : flights)
        adj[path[0]].push_back({path[1], path[2]});

    vector<int> dist(n, 1e9);

    queue<pii> q;
    q.push({0, src});
    dist[src] = 0;

    int steps = 0;

    while (!q.empty() and steps <= k)
    {
        int n = q.size();

        while (n--)
        {
            int node = q.front().second;
            int cost = q.front().first;

            q.pop();

            for (auto neigh : adj[node])
            {
                int adjNode = neigh.first;
                int edw = neigh.second;

                if (dist[adjNode] > cost + edw)
                {
                    dist[adjNode] = cost + edw;

                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        steps;
    }

    if (dist[dst] == 1e9)
        return -1;

    return dist[dst];
}

int main()
{
    return 0;
}