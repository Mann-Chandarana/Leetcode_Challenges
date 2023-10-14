/* Geeks for Geeks :- Shortest Path in the Directed Graph */

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child.first])
        {
            dfs(child.first, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    unordered_map<int, vector<pair<int, int>>> adj; // node -> {neighbour,weight}

    for (auto element : edges)
        adj[element[0]].push_back({element[1], element[2]});

    vector<bool> visited(N, false);
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    // We got topological sort

    vector<int> distance(N, 1e9);
    distance[0] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto child : adj[node])
        {
            if (distance[node] + child.second < distance[child.first])
            {
                st.push(child.first);
                distance[child.first] = distance[node] + child.second;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (distance[i] == 1e9)
            distance[i] = -1;
    }

    return distance;
}
int main()
{
    return 0;
}