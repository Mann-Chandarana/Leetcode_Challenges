/* Print longest increasing subsequence :- geeks for geeks */

#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> dp(n, 1), hash(n, 1);
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[i] > arr[prev] and 1 + dp[prev] > dp[i])
            {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = -1, last_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            last_index = i;
        }
    }

    vector<int> answer;
    answer.push_back(arr[last_index]);
    while (hash[last_index] != last_index)
    {
        last_index = hash[last_index];
        answer.push_back(arr[last_index]);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    arr = longestIncreasingSubsequence(n, arr);

    for (auto element : arr)
    {
        cout << element << " ";
    }

    return 0;
}