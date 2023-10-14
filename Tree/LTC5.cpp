/*-------- Medium -----------*/

/*- Minimum Time to Collect All Apples in a Tree  -*/

//////// Question number 1443.

#include <bits/stdc++.h>
using namespace std;

int dfs(int curr, int parent, vector<bool> &hasApple, unordered_map<int,vector<int>> adj)
{
    int time = 0;

    for (auto element : adj[curr])
    {
        if (element == parent)
            continue;

        int child_time = dfs(element, curr, hasApple, adj);

        if (child_time > 0 || hasApple[element])
            time += 2 + child_time;
    }
    return time;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    unordered_map<int,vector<int>> adj;

    for (auto element : edges)
    {
        int u = element[0];
        int v = element[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return dfs(0, -1, hasApple, adj);
}

int main()
{
    vector<vector<int>> edjes = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    vector<bool> hasApple = {false, false, true, false, true, true, false};

    cout << minTime(hasApple.size(), edjes, hasApple) << endl;
    return 0;
}