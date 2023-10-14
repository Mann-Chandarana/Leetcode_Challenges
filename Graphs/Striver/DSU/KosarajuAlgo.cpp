/* Geeks for Geeks :- Strongly Connected Components (Kosaraju's Algo) */

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(child, visited, adj, st);
    }

    st.push(node);
}

void dfs3(int node, vector<bool> &visited, vector<int> adjT[])
{
    visited[node] = true;

    for (auto child : adjT[node])
    {
        if (!visited[child])
            dfs3(child, visited, adjT);
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }

    vector<int> adjT[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        for (auto element : adj[i])
        {
            adjT[element].push_back(i);
        }
    }

    int scc = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            scc++;
            dfs3(node, visited, adjT);
        }
    }

    return scc;
}

int main()
{
    return 0;
}