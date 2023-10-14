#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> solution;

    for (int i = 0; i < (1 << (n)); i++)
    {
        vector<int> answer;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                answer.push_back(nums[j]);
            }
        }
        solution.push_back(answer);
    }
    return solution;
}

int main()
{
    return 0;
}