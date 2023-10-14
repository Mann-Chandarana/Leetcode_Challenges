/*--------Medium-----------*/

/*- Number of Provinces -*/

//////// Question number 355.

#include <bits/stdc++.h>
using namespace std;

/* Using Breadth first Search */

void bfs(vector<int> adj[], vector<int> &vis, int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto adjnode : adj[node])
        {
            if (!vis[adjnode])
            {
                q.push(adjnode);
                vis[adjnode] = 1;
            }
        }
    }
    return;
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int cnt = 0;
    int n = isConnected.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(adj, vis, i);
            cnt++;
        }
    }
    return cnt;
}

/* Using Depth first search */

void dfs(vector<vector<int>> &isConnected, int start, vector<bool> &visited)
{
    visited[start] = true;

    for (int j = 0; j < isConnected.size(); j++)
    {
        if (!visited[j] and isConnected[start][j] == 1)
            dfs(isConnected, j, visited);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int c = 0, n = isConnected.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            c++;
            dfs(isConnected, i, visited);
        }
    }

    return c;
}

int main()
{
    return 0;
}