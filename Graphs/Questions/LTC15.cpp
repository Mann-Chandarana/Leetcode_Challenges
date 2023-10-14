/*--------  Medium --------*/

/*- Time Needed to Inform All Employees -*/

//////// Question number 1376.

#include <bits/stdc++.h>
using namespace std;

/* Approach - 1) */

int dfs(int headId, vector<int> &informTime, vector<int> adj[])
{

    int maxTime = 0;

    for (auto it : adj[headId])
        maxTime = max(maxTime, dfs(it, informTime, adj));

    return informTime[headId] + maxTime;
}
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{

    vector<int> adj[n];

    for (int i = 0; i < manager.size(); i++)
        if (manager[i] != -1)
            adj[manager[i]].push_back(i);

    return dfs(headID, informTime, adj);
}

/* Approach -2 */

int maxTime = INT_MIN;

void DFS(unordered_map<int, vector<int>> &adj, vector<int> &informTime, int curr_employee, int curr_time)
{
    maxTime = max(maxTime, curr_time);

    for (int &v : adj[curr_employee])
    {

        DFS(adj, informTime, v, curr_time + informTime[curr_employee]);
    }
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < manager.size(); i++)
    {
        int child = i;
        int manager_i = manager[i];

        if (manager_i != -1)
            adj[manager_i].push_back(child);
    }

    DFS(adj, informTime, headID, 0);
    return maxTime;
}

int main()
{
    return 0;
}