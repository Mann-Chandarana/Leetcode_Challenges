#include <bits/stdc++.h>
using namespace std;

/** Solution **/

vector<vector<int>> v;
vector<int> counter, res;

void dfs(int i, int p = -1)
{
    for (auto u : v[i])
    {
        if (u == p)
            continue;
        dfs(u, i);
        counter[i] += counter[u];
        res[i] += res[u] + counter[u];
    }
    counter[i] += 1;
}

void dfs2(int i, int n, int p = -1)
{
    for (auto u : v[i])
    {
        if (u == p)
            continue;
        res[u] = res[i] - counter[u] + n - counter[u];
        dfs2(u, n, i);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    v.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    res.resize(n);
    counter.resize(n);
    dfs(0);
    dfs2(0, n);
    return res;
}

/** Will give TLE **/

void dfs(unordered_map<int, vector<int>> neighbour, int src, int distance, vector<bool> &visited, int &answer)
{
    answer += distance;
    for (auto element : neighbour[src])
    {
        if (!visited[element])
        {
            visited[element] = true;
            dfs(neighbour, element, distance + 1, visited, answer);
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> mp;
    vector<int> answer;
    for (auto element : edges)
    {
        mp[element[0]].push_back(element[1]);
        mp[element[1]].push_back(element[0]);
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        int answ = 0;
        dfs(mp, i, 0, visited, answ);
        answer.push_back(answ);
        visited.assign(n, false);
    }

    return answer;
}

int main()
{
    vector<vector<int>> edges = {};
    vector<int> answer;
    answer = sumOfDistancesInTree(1, edges);
    for (auto element : answer)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}