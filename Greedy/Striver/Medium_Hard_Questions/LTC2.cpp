/*-------- Medium -----------*/

/*- Jump Game II -*/

//////// Question number 45.

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    // The starting range of the first jump is [0, 0]
    int answer = 0, n = int(nums.size());

    int windowEnd = 0, maxiInwindow = 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxiInwindow = max(maxiInwindow, i + nums[i]);

        if (i == windowEnd)
        {
            cout << maxiInwindow << " " << windowEnd << endl;
            answer++, windowEnd = maxiInwindow;
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}