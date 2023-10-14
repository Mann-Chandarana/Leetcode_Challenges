/*--------  Medium --------*/

/*- Min Cost to Connect All Points -*/

//////// Question number 1584.

#include <bits/stdc++.h>
#include "DSU_rank_size.cpp"
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define vppi vector<pair<pair<int, int>, int>>
#define umps unordered_map<string, vector<string>>
#define pii pair<int, int>

/********* Approach -1 *********/

int krushkalAlgo(vector<vector<int>> &adj, int v)
{
    DisjointSet d(v);
    int sum = 0;

    for (auto temp : adj)
    {
        int u = temp[1];
        int v = temp[2];

        int weight = temp[0];

        int parent_u = d.findUPar(u);
        int parent_v = d.findUPar(v);

        if (parent_u != parent_v)
        {
            sum += weight;
            d.unionBySize(u, v);
        }
    }
    return sum;
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int V = points.size();
    vector<vector<int>> adj;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            int d = abs(x1 - x2) + abs(y1 - y2);

            adj.push_back({d, i, j});
        }
    }

    sort(all(adj));
    return krushkalAlgo(adj, V);
}

/********* Approach -2 *********/

int PrimeAlgo(vector<vector<pii>> &adj, int V)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); // {weight,vertex}

    vector<bool> inMst(V, false);

    int sum = 0;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int node = p.second;

        if (inMst[node] == true)
            continue;

        inMst[node] = true;
        sum += wt;

        for (auto &temp : adj[node])
        {
            int neighbor = temp.first;
            int neighbor_wt = temp.second;

            if (inMst[neighbor] == false)
                pq.push({neighbor_wt, neighbor});
        }
    }

    return sum;
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int V = points.size();

    vector<vector<pii>> adj(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            int d = abs(x1 - x2) + abs(y1 - y2);

            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }

    return PrimeAlgo(adj, V);
}

int main()
{

    return 0;
}