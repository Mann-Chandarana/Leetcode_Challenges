/*-------- Medium -----------*/

/*- Combination Sum -*/

//////// Question number 39.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, vector<vector<int>> &answer, int target, int index, int n, vector<int> curr)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        answer.push_back(curr);
        return;
    }

    if (index == n)
    {
        return;
    }

    solve(candidates, answer, target - candidates[index], index, n, curr);

    solve(candidates, answer, target, index + 1, n, curr);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> answer;
    vector<int> curr;
    
    solve(candidates, answer, target, 0, candidates.size(), curr);

    return answer;
}

int main()
{
    return 0;
}