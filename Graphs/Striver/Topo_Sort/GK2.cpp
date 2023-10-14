/* Geeks for Geeks :- Course Schedule */

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
    vector<int> indegree(n, 0);

    vector<int> adj[n];

    for (auto it : prerequisites)
        adj[it[1]].push_back(it[0]);

    for (int i = 0; i < n; i++)
    {
        for (auto child : adj[i])
            indegree[child]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> toposort;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        toposort.push_back(node);

        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
                q.push(child);
        }
    }

    if (toposort.size() == n)
        return toposort;

    return {};
}

int main()
{
    return 0;
}