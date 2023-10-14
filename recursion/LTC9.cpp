/*-------- Medium -----------*/

/*- Subsets -*/

//////// Question number 78.

#include <bits/stdc++.h>
using namespace std;

/* Using iteration */

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> answer;
    int n = nums.size();

    answer.push_back({});

    for (int i = 0; i < n; i++)
    {
        int sz = answer.size();

        for (int j = 0; j < sz; j++)
        {
            vector<int> temp = answer[j];
            temp.push_back(nums[i]);
            answer.push_back(temp);
        }
    }

    return answer;
}

/* Using bit manipulation */

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> answer;
    int n = nums.size();

    int value = pow(2, n);

    int i = 0;
    while (i < value)
    {
        vector<int> curr;
        for (int j = 0; j < n; j++)
        {
            if (i & 1 << j)
            {
                curr.push_back(nums[j]);
            }
        }
        answer.push_back(curr);
        i++;
    }
    return answer;
}

/* Recursion */

void solve(vector<int> nums, vector<vector<int>> &answer, int index, int n, vector<int> curr)
{
    if (index == n)
    {
        answer.push_back(curr);
        return;
    }

    solve(nums, answer, index + 1, n, curr);
    curr.push_back(nums[index]);
    solve(nums, answer, index + 1, n, curr);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> answer;
    vector<int> curr;
    int n = nums.size();
    solve(nums, answer, 0, n, curr);
    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer = subsets(nums);

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