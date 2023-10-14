/*--------Medium-----------*/

/*- Course Schedule II -*/

//////// Question number 210.

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    for (auto element : prerequisites)
        adj[element[1]].push_back(element[0]);   // u->v then u should comes before v

    vector<int> indegree(numCourses, 0);
    queue<int> q;

    for (int i = 0; i < numCourses; i++)
    {
        for (auto element : adj[i])
            indegree[element]++;
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topoSort;

    while (!q.empty())
    {
        int node = q.front();
        topoSort.push_back(node);

        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
                q.push(child);
        }
    }

    if (topoSort.size() == numCourses)
        return topoSort;

    return {};
}

int main()
{
    return 0;
}