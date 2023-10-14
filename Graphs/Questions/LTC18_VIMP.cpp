/*--------  Medium --------*/

/*- Sort Items by Groups Respecting Dependencies -*/

//////// Question number 1203.

/* 
Conceputally very important 

1) First create the order of the item using topological sort
2) Then create thte order for the group using topological sort
3) Then create making for grouptoItem
4) Then add the items according to the grouporder followed by itemorder
 */

#include <bits/stdc++.h>
using namespace std;

// Writing the code for toposort

vector<int> toposort(unordered_map<int, vector<int>> &adj, vector<int> &indegree)
{
    queue<int> q;

    for (int i = 0; i < adj.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Applying BFS

    vector<int> result;
    while (!q.empty())
    {
        int u = q.front();
        result.push_back(u);
        q.pop();

        for (auto neigh : adj[u])
        {
            indegree[neigh]--;

            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    return result.size() == adj.size() ? result : vector<int>();
}

vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
{
    for (int i = 0; i < n; i++)
    {
        if (group[i] == -1)
            group[i] = m++;
    }

    // Step 2 Make itemGraph + item Indegree
    unordered_map<int, vector<int>> itemGraph;
    vector<int> itemIndegree(n, 0);

    for (int i = 0; i < n; i++)
        itemGraph[i] = vector<int>();

    // Step-3 Make GroupGraph + groupIndegree

    unordered_map<int, vector<int>> groupGraph;
    vector<int> groupIndeg(m, 0);

    for (int i = 0; i < m; i++)
        groupGraph[i] = vector<int>();

    // Step-4 (FillItemGraph, itemindegree, groupGraph, groupIndegree)

    for (int i = 0; i < n; i++)
    {
        for (int prev : beforeItems[i])
        {
            itemGraph[prev].push_back(i);
            itemIndegree[i]++;

            if (group[i] != group[prev])
            {
                int prevItemGroup = group[prev];
                int currItemGroup = group[i];

                groupGraph[prevItemGroup].push_back(currItemGroup);
                groupIndeg[currItemGroup]++;
            }
        }
    }

    // Step-5 Call Toposort for both the graph

    vector<int> itemorder = toposort(itemGraph, itemIndegree);
    vector<int> grouporder = toposort(groupGraph, groupIndeg);

    unordered_map<int, vector<int>> groupToItem;

    for (auto item : itemorder)
    {
        int itemGroup = group[item];
        groupToItem[itemGroup].push_back(item);
    }

    vector<int> result;
    for (int group : grouporder)
        result.insert(result.end(), groupToItem[group].begin(), groupToItem[group].end());

    return result;
}

int main()
{
    return 0;
}