/* Safe Nodes */

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<int> adj[])
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (dfs(it, vis, pathvis, adj) == false)
            {
                return false;
            }
        }
        else if (pathvis[it] == 1)
        {
            return false;
        }
    }
    pathvis[node] = 0;
    return true;
}
vector<int> eventualSafeNodes(int n, vector<int> adj[])
{
    vector<int> vis(n, 0), pathvis(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, pathvis, adj);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (pathvis[i] == 0)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    return 0;
}