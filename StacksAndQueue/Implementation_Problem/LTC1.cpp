/*--------  Hard --------*/

/*- Sliding Window Maximum -*/

//////// Question number 239.

#include <bits/stdc++.h>
using namespace std;

/* Method - 1 */

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

/* Method - 2 */

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();

    deque<int> dq;
    vector<int> answer;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() and nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);
    }

    answer.push_back(nums[dq.front()]);

    for (int i = k; i < n; i++)
    {
        while (!dq.empty() and i - dq.front() >= k)
            dq.pop_front();

        while (!dq.empty() and nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        answer.push_back(nums[dq.front()]);
    }

    return answer;
}

int main()
{
    vector<int> nums = {4, 3, 11};
    nums = maxSlidingWindow(nums, 3);

    for (auto element : nums)
        cout << element << endl;

    return 0;
}