/*--------Medium-----------*/

/*- Critical Connections in a Network -*/

//////// Question number 1192.

#include <bits/stdc++.h>
using namespace std;

/*
tm[] --> store the time of insertion during DFS
low[] --> minimum of all the adjacent node apart from the parent
*/

int timer = 1;

void dfs(int node, int parent, vector<int> &tm, vector<int> &low, vector<int> adj[], vector<vector<int>> &bridges, vector<bool> &visited)
{
    visited[node] = true;
    tm[node] = low[node] = timer;
    timer++;

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        if (!visited[child])
        {
            dfs(child, node, tm, low, adj, bridges, visited);
            low[node] = min(low[node], low[child]);
            // node --> child
            if (low[child] > tm[node])
                bridges.push_back({child, node});
        }
        else
            low[node] = min(low[node], low[child]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> tm(n, 0), low(n, 0);
    vector<int> adj[n];
    for (auto it : connections)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<vector<int>> bridges;
    dfs(0, -1, tm, low, adj, bridges, visited);
    return bridges;
}

int main()
{
    return 0;
}