/* Geeks for Geeks :- Depth first search */

#include <bits/stdc++.h>
using namespace std;

vector<int> dfsLt;
void dfs(int st, vector<int> adj[], int vis[])
{
    vis[st] = 1;
    dfsLt.push_back(st);
    for (auto it : adj[st])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

void dfs(int node, unordered_map<int, vector<int>> &neighbours, vector<bool> &visited, vector<int> answer)
{
    visited[node] = true;
    answer.push_back(node);

    for (auto element : neighbours[node])
    {
        if (!visited[element])
            dfs(element, neighbours, visited, answer);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    int st = 0;
    dfs(st, adj, vis);
    return dfsLt;
}

int main()
{
    return 0;
}