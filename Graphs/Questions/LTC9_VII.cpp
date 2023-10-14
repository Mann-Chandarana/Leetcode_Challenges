/*--------  Medium --------*/

/*- Minimum Fuel Cost to Report to the Capital -*/

//////// Question number 2477.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;

ll dfs(vector<int> &vis, int node, int seats, vector<int> adj[])
{
    vis[node] = 1;
    ll count = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            count += dfs(vis, it, seats, adj);
    }
    ll x = count / seats;
    if (count % seats)
        x++;
    if (node != 0)
        ans += x;

    return count;
}

long long minimumFuelCost(vector<vector<int>> &roads, int seats)
{
    int n = roads.size();
    vector<int> adj[n + 1], vis(n + 1, 0);

    for (auto it : roads)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    dfs(vis, 0, seats, adj);

    return ans;
}

int main()
{
    return 0;
}