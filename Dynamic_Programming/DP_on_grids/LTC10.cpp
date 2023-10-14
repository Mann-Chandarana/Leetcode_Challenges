// Ninja Training :- geeks for geeks

// https://practice.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

#include <bits/stdc++.h>
using namespace std;

/** Using memorizaton technique **/

int find_max(vector<vector<int>> &points, int idx, int prev_idx, vector<vector<int>> dp)
{
    if (dp[idx][prev_idx] != -1)
    {
        return dp[idx][prev_idx];
    }

    if (idx == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i <= 2; i++)
        {
            if (i != prev_idx)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[idx][prev_idx] = maxi;
    }
    int sum = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != prev_idx)
        {
            int value = points[idx][i] + find_max(points, idx - 1, i, dp);
            sum = max(sum, value);
        }
    }
    return dp[idx][prev_idx] = sum;
}

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return find_max(points, n - 1, 3, dp);
}

/** Using tabulation technique **/

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return dp[n - 1][3];
}

/** Using space optimization **/

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    vector<int> prev(4, 0), curr(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + prev[task];
                    curr[last] = max(curr[last], activity);
                }
            }
        }
        prev = curr;
    }

    return prev[3];
}

int main()
{
    return 0;
}