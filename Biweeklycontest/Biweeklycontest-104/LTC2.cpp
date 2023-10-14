/*-------- Medium -----------*/

/*- Sum in a Matrix -*/

//////// Question number 2679.

#include <bits/stdc++.h>
using namespace std;

/* Using Sorting */

int matrixSum(vector<vector<int>> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sort(nums[i].begin(), nums[i].end());
    }
    for (int c = 0; c < nums[0].size(); ++c)
    {
        int t = 0;
        for (int r = 0; r < nums.size(); ++r)
        {
            t = max(t, nums[r][c]);
        }
        ans += t;
    }
    return ans;
}

/* Using Priority Queue */

int matrixSum(vector<vector<int>> &nums)
{
    priority_queue<int> pq[nums.size()];

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
            pq[i].push(nums[i][j]);
    }

    int answer = 0;

    for (int i = 0; i < nums[0].size(); i++)
    {
        int maxi = INT_MIN;
        for (int j = 0; j < nums.size(); j++)
        {
            maxi = max(maxi, pq[j].top());
            pq[j].pop();
        }
        answer += maxi;
    }

    return answer;
}

int main()
{
    return 0;
}