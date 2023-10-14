/*-------- Medium -----------*/

/*- Number of Nodes in the Sub-Tree With the Same Label  -*/

//////// Question number 1519.

#include <bits/stdc++.h>
using namespace std;

/* Optimized approach */

void dfsCountAndUpdate(int node, int prevNode, vector<vector<int>> &adjVec, string &labels, vector<int> &solution, vector<int> &freqMap)
{
    int prev_count = freqMap[labels[node] - 'a'];

    freqMap[labels[node] - 'a']++;

    for (auto element : adjVec[node])
    {
        if (element != prevNode)
            dfsCountAndUpdate(element, node, adjVec, labels, solution, freqMap);
    }
    solution[node] = freqMap[labels[node] - 'a'] - prev_count;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<vector<int>> adjVec(n, vector<int>());

    for (vector<int> &edge : edges)
    {
        adjVec[edge[0]].push_back(edge[1]);
        adjVec[edge[1]].push_back(edge[0]);
    }

    vector<int> solution(n, 0);
    vector<int> freqMap = vector<int>(26, 0);
    dfsCountAndUpdate(0, 0, adjVec, labels, solution, freqMap);

    return solution;
}

/* Not optimized approach */

vector<int> fun(vector<vector<int>> &adj, string &labels, int node, int prevNode, vector<int> &result)
{
    vector<int> ans(26, 0);
    result[node] = 1;
    ans[labels[node] - 'a'] = 1;

    for (auto element : adj[node])
    {
        if (element != prevNode)
        {
            vector<int> tmp = fun(adj, labels, element, node, result);
            for (int k = 0; k != 26; k++)
                ans[k] += tmp[k];
        }
    }

    result[node] = ans[labels[node] - 'a'];

    return ans;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<vector<int>> adj(n);
    vector<int> result(n, 0);
    for (int i = 0; i != edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    fun(adj, labels, 0, 0, result);
    return result;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    string str = "abaedcd";
    vector<int> ans = countSubTrees(str.size(), edges, str);

    for (auto element : ans)
    {
        cout << element << endl;
    }
    return 0;
}