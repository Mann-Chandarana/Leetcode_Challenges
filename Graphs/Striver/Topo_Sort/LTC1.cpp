/*--------Medium-----------*/

/*- Course Schedule -*/

//////// Question number 207.

#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0);

    vector<int> adj[numCourses];

    for (auto it : prerequisites)
        adj[it[1]].push_back(it[0]);

    for (int i = 0; i < numCourses; i++)
    {
        for (auto child : adj[i])
            indegree[child]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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

    if (toposort.size() == numCourses)
        return true;

    return false;
}



int main()
{
    return 0;
}