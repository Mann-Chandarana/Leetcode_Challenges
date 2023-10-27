/*- Keys and Rooms -*/

//////// Question number 1971.

#include <bits/stdc++.h>
using namespace std;

/*** Using BFS ***/

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    unordered_map<int, vector<int>> neighs;
    for (int i = 0; i < edges.size(); i++)
    {
        neighs[edges[i][0]].push_back(edges[i][1]);
        neighs[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == destination)
            return true;

        for (auto neigh : neighs[curr])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    return false;
}

/*** Using DFS ***/

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    unordered_map<int, vector<int>> neighs;
    for (int i = 0; i < edges.size(); i++)
    {
        neighs[edges[i][0]].push_back(edges[i][1]);
        neighs[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, 0);
    visited[source] = true;
    stack<int> st;
    st.push(source);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        if (curr == destination)
        {
            return true;
        }

        for (auto neigh : neighs[curr])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                st.push(neigh);
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}