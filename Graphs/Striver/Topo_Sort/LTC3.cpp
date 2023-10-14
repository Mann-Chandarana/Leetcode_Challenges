/*--------Medium-----------*/

/*- Find Eventual Safe States -*/

//////// Question number 802.

#include <bits/stdc++.h>
using namespace std;

/* 
   Intution :- is that the topological sort doesn't count the acyclic graph
   and the safe nodes are that node that does'nt comes in a cycle
*/

/*
1) Reverse all the edges
2) Then apply toposort on the reversed graph
*/

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        for (auto x : graph[i])
            adj[x].push_back(i);         // 0-->1 to 1-->0
    }

    vector<int> indegree(n, 0);

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

    vector<int> safeNode;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNode.push_back(node);

        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
                q.push(child);
        }
    }
    sort(safeNode.begin(), safeNode.end());
    return safeNode;
}

int main()
{
    return 0;
}