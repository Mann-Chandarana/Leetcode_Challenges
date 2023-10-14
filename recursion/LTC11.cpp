/*-------- Medium -----------*/

/*- Combination Sum II -*/

//////// Question number 40.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> candidates, vector<vector<int>> &answer, vector<int> curr, int target, int index)
{
    if (target == 0)
    {
        answer.push_back(curr);
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index and candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        curr.push_back(candidates[i]);
        solve(candidates, answer, curr, target - candidates[i], i + 1);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer;
    vector<int> curr;
    solve(candidates, answer, curr, target, 0);
    return answer;
}

int main()
{
    return 0;
}