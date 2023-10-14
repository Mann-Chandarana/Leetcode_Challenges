/* Geeks for Geeks :- Topological Sort */

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(child, st, adj, visited);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, st, adj, visited);
        }
    }
    vector<int> answer;
    while (!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
}

int main()
{
    return 0;
}