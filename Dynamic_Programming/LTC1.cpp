/*--------  Medium --------*/

/*- Find Closest Node to Given Two Nodes -*/

//////// Question number 2359.

#include <bits/stdc++.h>
using namespace std;

/**** Will give solution ****/

/* Memorization */

const int inf = 1e8;

int dfs(int node, int k, int dest, vector<vector<int>> &cost, vector<int> adj[], vector<vector<int>> dp)
{
    if (k < 0)
        return inf;

    if (node == dest)
        return 0;

    if (dp[node][k] != -1)
        return dp[node][k];

    int ans = inf;
    for (auto i : adj[node])
        ans = min(ans, cost[node][i] + dfs(i, k - 1, dest, cost, adj, dp));

    return dp[node][k] = ans;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<int>> dp(n, vector<int>(k + 2, -1));

    vector<vector<int>> cost(n, vector<int>(n));
    vector<int> adj[n];
    for (auto e : flights)
    {
        adj[e[0]].push_back(e[1]);
        cost[e[0]][e[1]] = e[2];
    }

    int ans = dfs(src, k + 1, dst, cost, adj, dp);
    return ans == inf ? -1 : ans;
}

/***** Tabulation *****/

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<int>> dp(n, vector<int>(k + 2, 0));

    vector<vector<int>> cost(n, vector<int>(n));
    vector<int> adj[n];
    for (auto e : flights)
    {
        adj[e[0]].push_back(e[1]);
        cost[e[0]][e[1]] = e[2];
    }

    for (int source = n - 1; source >= 0; source--)
    {
        for (int stops = 0; stops <= k + 1; stops++)
        {
            if (source == dst)
                dp[source][stops] = 0;

            else
            {
                int ans = inf;
                for (auto i : adj[source])
                {
                    int tp = stops == 0 ? 1e7 : cost[source][i] + dp[i][stops - 1];
                    ans = min(ans, tp);
                }

                dp[source][stops] = ans;
            }
        }
    }

    int val = dp[src][k + 1];
    return (val == inf ? -1 : val);
}


/* ------------------------------------------------------------------------------------------------------------------ */

/**** Will give TLE :- Because of the use of the map ****/

int infi = 1e8;

int dfs(int src, int dst, int k, unordered_map<int, vector<pair<int, int>>> neighbour, vector<vector<int>> &dp)
{
    if (src == dst)
        return 0;

    if (k < 0)
        return infi;

    if (dp[src][k] != -1)
        return dp[src][k];

    int ans = infi;
    for (auto node : neighbour[src])
    {
        ans = min(ans, (node.second + dfs(node.first, dst, k - 1, neighbour, dp)));
    }
    return dp[src][k] = ans;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    unordered_map<int, vector<pair<int, int>>> neighbour;

    for (auto element : flights)
        neighbour[element[0]].push_back({element[1], element[2]});

    int ans = dfs(src, dst, k, neighbour, dp);

    return ans == infi ? -1 : ans;
}

int main()
{
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << findCheapestPrice(3, flights, 0, 2, 0);
    return 0;
}