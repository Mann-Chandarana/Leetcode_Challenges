/*--------  Medium --------*/

/*- Find Champion II -*/

//////// Question number 100116.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

void topoSort(int n, int node, vector<int> adj[], stack<int> &st, vector<int> &visited)
{
    visited[node] = true;

    for (auto neigh : adj[node])
    {
        if (!visited[neigh])
            topoSort(n, neigh, adj, st, visited);
    }

    st.push(node);
}

int findChampion(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];

    for (int i = 0; i < edges.size(); i++)
        adj[edges[i][0]].push_back(edges[i][1]);

    stack<int> st;
    vector<int> visited(n, false);
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSort(n, i, adj, st, visited);
            if (st.size() == n)
            {
                ans = i;
                break;
            }
            st = stack<int>();
            visited = vector<int>(n, false);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{1,0}};
    cout << findChampion(2, edges) << endl;
    return 0;
}