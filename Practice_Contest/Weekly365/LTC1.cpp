/* 2873. Maximum Value of an Ordered Triplet I */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

long long maximumTripletValue(vector<int> &nums)
{
    long long answer = 0;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
                answer = max(answer, (nums[i] - nums[j]) * 1LL * nums[k]);
        }
    }
    return answer;
}

int main()
{
    return 0;
}