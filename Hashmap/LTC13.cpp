/* 1436. Destination City */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

////////////// Graph Approach

string destCity(vector<vector<string>> &paths)
{
    unordered_map<string, vector<string>> mp;
    unordered_map<string, bool> visited;

    for (auto path : paths)
    {
        mp[path[0]].push_back(path[1]);
        visited[path[0]] = false, visited[path[1]] = false;
    }

    string source = paths[0][0], destination;

    queue<string> q;
    q.push(source);

    while (!q.empty())
    {
        string src = q.front();
        q.pop();
        visited[src] = true;

        destination = src;

        for (auto element : mp[src])
        {
            if (!visited[element])
                q.push(element);
        }
    }
    return destination;
}

////////////// Approach -1)

string destCity(vector<vector<string>> &paths)
{
    unordered_set<string> st;

    for (auto &path : paths)
    {
        string dest = path[0];
        st.insert(dest);
    }

    for (auto &path : paths)
    {
        string dest = path[1];

        if (st.find(dest) == st.end())
            return dest;
    }
    return "";
}

////////////// Approach -2)

string destCity(vector<vector<string>> &paths)
{
    unordered_map<string, int> mp;

    for (auto &path : paths)
        mp[path[0]] = 1;

    for (auto &path : paths)
    {
        if (mp.find(path[1]) == mp.end())
            return path[1];
    }
    return "";
}

int main()
{
    return 0;
}