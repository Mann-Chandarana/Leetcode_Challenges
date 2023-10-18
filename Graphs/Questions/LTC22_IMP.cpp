/*--------  Hard --------*/

/*- Parallel Courses III -*/

//////// Question number 2050.

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

/***** Approach -1) *****/

int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    vector<vi> graph(n + 1);
    vi indegree(n + 1, 0), Total_Time(n + 1, 0);

    for (int i = 0; i < relations.size(); i++)
    {
        int prev = relations[i][0];
        int curr = relations[i][1];

        graph[prev].pb(curr);
        indegree[curr]++;
    }

    queue<int> q;
    int max_Time = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            Total_Time[i] = time[i - 1];
            max_Time = max(max_Time, Total_Time[i]);
        }
    }

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        for (int nextNode : graph[currNode])
        {
            Total_Time[nextNode] = max(Total_Time[nextNode], time[nextNode - 1] + Total_Time[currNode]);
            max_Time = max(max_Time, Total_Time[nextNode]);
            indegree[nextNode]--;
            if (indegree[nextNode] == 0)
                q.push(nextNode);
        }
    }

    return max_Time;
}

/***** Approach -2) *****/

int calculateTime(int course, vector<int> &dp, vector<vector<int>> &graph, vector<int> &time)
{
    if (dp[course] != -1)
        return dp[course];

    if (graph[course].empty())
    {
        dp[course] = time[course - 1];
        return dp[course];
    }

    int prev_time = 0;

    for (auto prev_course : graph[course])
        prev_time = max(prev_time, calculateTime(prev_course, dp, graph, time));

    dp[course] = prev_time + time[course - 1];

    return dp[course];
}

int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < relations.size(); i++)
    {
        int prev = relations[i][0];
        int curr = relations[i][1];

        graph[curr].pb(prev);
    }

    vector<int> dp(n + 1, -1);

    int overallTime = 0;

    for (int i = 1; i <= n; i++)
        overallTime = max(overallTime, calculateTime(i, dp, graph, time));

    return overallTime;
}

int main()
{
    return 0;
}