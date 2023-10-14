/*-------- Medium -----------*/

/*- Non-decreasing Subsequences -*/

//////// Question number 491.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, set<vector<int>> &ans, vector<int> &answer, int prev)
{
    if (index >= nums.size())
    {
        if (answer.size() >= 2)
            ans.insert(answer);
        return;
    }

    if (answer.size() == 0 || nums[index] >= prev)
    {
        /* Taken */
        answer.push_back(nums[index]);
        solve(nums, index + 1, ans, answer, nums[index]);

        /* Not Taken */
        answer.pop_back();
        solve(nums, index + 1, ans, answer, prev);
    }
    else
    {
        solve(nums, index + 1, ans, answer, prev);
    }
}

void solve(vector<int> nums, int index, set<vector<int>> &ans, vector<int> &answer, int prev)
{
    if (index > nums.size())
    {
        return;
    }
    if (answer.size() >= 2)
    {
        ans.insert(answer);
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (nums[i] >= prev)
        {
            answer.push_back(nums[i]);
            solve(nums, i + 1, ans, answer, nums[i]);
            answer.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    set<vector<int>> ans;
    vector<vector<int>> ansi;
    vector<int> answer;

    solve(nums, 0, ans, answer, INT_MIN);

    for (auto element : ans)
    {
        for (auto i : element)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    for (auto element : ans)
    {
        ansi.push_back(element);
    }
    return ansi;
}

// /* Most optimised approach*/

void dfs(vector<vector<int>> &res, vector<int> &seq, vector<int> &nums, int pos)
{
    if (seq.size() > 1)
        res.push_back(seq);

    unordered_set<int> hash;

    for (int i = pos; i < nums.size(); ++i)
    {
        if ((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end())
        {
            seq.push_back(nums[i]);
            dfs(res, seq, nums, i + 1);
            seq.pop_back();
            hash.insert(nums[i]);
        }
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> seq;
    dfs(res, seq, nums, 0);
    return res;
}
int main()
{
    vector<int> nums = {4, 7, 7,8};
    vector<vector<int>> answer = findSubsequences(nums);
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