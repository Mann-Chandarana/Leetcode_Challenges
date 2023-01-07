#include <bits/stdc++.h>
using namespace std;

/* Without using set */

void solve(vector<int> candidates, vector<vector<int>> &answer, vector<int> curr, int index)
{
    answer.push_back(curr);

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index and candidates[i] == candidates[i - 1])
            continue;

        curr.push_back(candidates[i]);
        solve(candidates, answer, curr, i + 1);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> answer;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    solve(nums, answer, curr, 0);

    return answer;
}

/* Using Sets */

void solve(vector<int> candidates, set<vector<int>> &answer, vector<int> curr, int index)
{
    if (index == candidates.size())
    {
        sort(curr.begin(),curr.end());
        answer.insert(curr);
        return;
    }

    solve(candidates, answer, curr, index + 1);
    curr.push_back(candidates[index]);
    solve(candidates, answer, curr, index + 1);
    curr.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> answer;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    solve(nums, answer, curr, 0);

    vector<vector<int>> ans;

    for(auto element:answer)
    {
        ans.push_back(element);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> answer = subsetsWithDup(nums);

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