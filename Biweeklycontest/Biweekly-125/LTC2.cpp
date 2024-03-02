/*-------- Medium --------*/

/*- Count Pairs of Connectable Servers in a Weighted Tree Network -*/

//////// Question number 3067.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

unordered_map<int, vector<pair<int, int>>> adj;
int n, ct, ss;

void dfs(int node, int parent, int distance)
{
    if (distance % ss == 0)
        ct++;

    for (auto [ch, dis] : adj[node])
    {
        if (ch != parent)
            dfs(ch, node, distance + dis);
    }
}

vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
{
    n = edges.size() + 1, ss = signalSpeed;
    for (auto vec : edges)
    {
        int u = vec[0], v = vec[1], w = vec[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> answer(n, 0);

    for (int par = 0; par < n; par++)
    {
        int ans = 0, sum = 0;
        vector<int> temp;

        for (auto [ch, d] : adj[par])
        {
            ct = 0;
            dfs(ch, par, d);
            temp.push_back(ct);
            sum += ct;
        }

        for (auto ele : temp)
            ans += (sum - ele) * ele;

        answer[par] = ans / 2;
    }
    return answer;
}

int main()
{
    return 0;
}