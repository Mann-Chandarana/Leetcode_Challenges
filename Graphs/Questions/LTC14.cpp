/*--------  Medium --------*/

/*- Is Graph Bipartite? -*/

//////// Question number 785.

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &color)
{
    if (color[node] == -1)
        color[node] = 1;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (dfs(it, adj, color) == false)
                return false;
        }
        else if (color[node] == color[it])
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, graph, color) == false)
                return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}