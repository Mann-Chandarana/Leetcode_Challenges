#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int find_sum(int node, bool once_included, vector<int> adj[], vector<int> &values)
{
    if (adj[node].size() == 0 and !once_included)
        return values[node];

    ll taken = 0, not_taken = 0;

    // Not_taken case

    for (auto child : adj[node])
        not_taken = 0 + find_sum(child, false, adj, values);

    // Taken case

    for (auto child : adj[node])
        taken = values[node] + find_sum(child, true, adj, values);

    return max(taken, not_taken);
}

long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values)
{
    int n = edges.size() + 1;
    vector<int> adj[n + 1];

    for (auto element : edges)
        adj[element[0]].push_back(element[1]);

    return find_sum(0, 0, adj, values);
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {4, 5}};
    vector<int> values = {5, 2, 5, 2, 1, 1};
    cout << maximumScoreAfterOperations(edges, values) << endl;

    return 0;
}