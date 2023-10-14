#include <bits/stdc++.h>
using namespace std;

int minScore(int n, vector<vector<int>> &roads)
{
    vector<vector<int>> adj[n + 1];
    for (auto a : roads)
    {
        adj[a[0]].push_back({a[1], a[2]});
        adj[a[1]].push_back({a[0], a[2]});
    }

    vector<bool> visited(n + 1, false);
    queue<vector<int>> q;
    int ans = 1e8;
    visited[1] = 1;
    q.push({1, 10000});

    while (!q.empty())
    {
        int ct = q.front()[0];
        q.pop();

        for (auto a : adj[ct])
        {
            ans = min(ans, a[1]);
            if (!visited[a[0]])
            {
                visited[a[0]] = true;
                q.push({a[0], a[1]});
            }
        }
    }
    return ans;
}

void dfs(int node, int &mini, vector<bool> &visited, vector<vector<int>> adj[])
{
    visited[node] = true;

    for (auto a : adj[node])
    {
        mini = min(mini, a[1]);
        if (!visited[a[0]])
        {
            dfs(a[0], mini, visited, adj);
        }
    }
}

int minScore(int n, vector<vector<int>> &roads)
{
    /* Creating and adjacency list */

    vector<vector<int>> adj[n + 1];
    for (auto a : roads)
    {
        adj[a[0]].push_back({a[1], a[2]});
        adj[a[1]].push_back({a[0], a[2]});
    }

    vector<bool> visited(n, false);
    int mini = INT_MAX;
    dfs(1, mini, visited, adj);
}

int main()
{
    return 0;
}