/*--------Medium-----------*/

/*- Keys and Rooms -*/

//////// Question number 841.

#include <bits/stdc++.h>
using namespace std;

/** Using BFS - breadth first search **/

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> visited(n, 0);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto element : rooms[curr])
        {
            if (!visited[element])
            {
                visited[element] = true;
                q.push(element);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

/** Using DFS - depth first search **/

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> visited(n, 0);

    stack<int>st;
    st.push(0);
    visited[0] = true;

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        for (auto element : rooms[curr])
        {
            if (!visited[element])
            {
                visited[element] = true;
                st.push(element);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}