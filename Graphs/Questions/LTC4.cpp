/*-------- Medium -----------*/

/*- All Paths From Source to Target -*/

//////// Question number 797.

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> answer;

void dfs(int src, vector<vector<int>> &graph, int end)
{
    ans.push_back(src);
    if (src == end)
    {
        answer.push_back(ans);
    }

    for (auto element : graph[src])
    {
        dfs(element,graph, end);
    }

    ans.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size() - 1;

    dfs(0, graph, n);

    return answer;
}

int main()
{
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    vector<vector<int>> answer = allPathsSourceTarget(graph);

    for (auto element : answer)
    {
        for (auto i : element)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}