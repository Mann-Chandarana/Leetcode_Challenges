#include <bits/stdc++.h>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<bool> indegree(n, false);

    for (auto element : edges)
        indegree[element[1]] = true;

    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
            answer.push_back(i);
    }

    return answer;
}

int main()
{
    return 0;
}