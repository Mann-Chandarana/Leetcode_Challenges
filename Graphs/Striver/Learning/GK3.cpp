/* Geeks for Geeks :- Breadth first search */

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(0);
    vector<int> arr;
    visited[0] = true;
    arr.push_back(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                visited[child] = true;
                arr.push_back(child);
                q.push(child);
            }
        }
    }
    return arr;
}

int main()
{
    return 0;
}