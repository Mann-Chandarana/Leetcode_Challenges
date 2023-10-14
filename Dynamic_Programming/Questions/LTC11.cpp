/*-------- Hard -----------*/

/*- Maximize Score After N Operations -*/

//////// Question number 1799.

#include <bits/stdc++.h>
using namespace std;

int score(int index, vector<int> &nums, int &answer, int &k, int &maxi, int operation, vector<bool> &visited)
{
    if (operation >= k + 1)
        return 0;

    if (visited[index])
        return score(index + 1, nums, answer, k, maxi, operation, visited);
    else
    {
        visited[index] = true;
        for (int i = index + 1; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                answer = (operation * (__gcd(nums[index], nums[i]))) + score(index + 1, nums, answer, k, maxi, operation + 1, visited);
                maxi = max(maxi, answer);
                visited[i] = false;
            }
        }
        visited[index] = false;
    }

    return maxi;
}

/***** Recursion *****/

int score(vector<int> &nums, int operation, vector<bool> visited)
{
    int max_score = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (visited[j])
                continue;
            visited[j] = true;
            int answer = (operation * __gcd(nums[i], nums[j])) + score(nums, operation + 1, visited);
            max_score = max(max_score, answer);
            visited[j] = false;
        }
        visited[i] = false;
    }
    return max_score;
}

/***** Memorization *****/

int score(vector<int> &nums, int operation, vector<bool> &visited, unordered_map<vector<bool>, int> &dp)
{
    if (dp[visited])
        return dp[visited];

    int max_score = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (visited[j])
                continue;
            visited[j] = true;
            int answer = (operation * __gcd(nums[i], nums[j])) + score(nums, operation + 1, visited, dp);
            max_score = max(max_score, answer);
            visited[j] = false;
        }
        visited[i] = false;
    }
    return dp[visited] = max_score;
}

int maxScore(vector<int> &nums)
{
    int answer = 0, operation = 1;
    vector<bool> visited(nums.size(), false);
    unordered_map<vector<bool>, int> dp;

    return score(nums, operation, visited, dp);
}

int main()
{
    vector<int> nums = {3, 4, 6, 8};
    cout << maxScore(nums) << endl;
    return 0;
}