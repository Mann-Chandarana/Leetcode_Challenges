#include <bits/stdc++.h>
using namespace std;

/* Using BFS */

bool bfs(int V, vector<int> adj[], vector<bool> &visited, int node)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = true;

    while (!q.empty())
    {
        int node = q.front().first, parent = q.front().second;
        q.pop();

        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                visited[child] = true;
                q.push({child, node});
            }
            else if (child != parent)
                return true;
        }
    }
    return false;
}

/* Using DFS */

bool dfs(vector<int> adj[], vector<bool> &visited, int node, int parent)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            if (dfs(adj, visited, child, node))
                return true;
        }
        else if (child != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] and dfs(adj, visited, i,-1))
            return true;
    }

    return false;
}

int main()
{
    return 0;
}