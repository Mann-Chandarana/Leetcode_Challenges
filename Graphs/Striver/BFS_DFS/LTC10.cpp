/* Check Cycle in a directed graph using DFS */

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited)
{
    visited[node] = true;
    pathVisited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            if (dfs(child, adj, visited, pathVisited))
                return true;
            else if (pathVisited[child] == true)
                return true;
        }
    }
    pathVisited[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> visited(V, false), pathVisited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited))
                return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}