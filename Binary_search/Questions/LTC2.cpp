/*-  Longest Subsequence With Limited Sum -*/

//////// Question number 2389.

#include <bits/stdc++.h>
using namespace std;

/** Using upper_bound function **/

vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> answer;

    for (int i = 1; i < n; i++)
    {
        nums[i] += (nums[i - 1]);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int size = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        answer.push_back(size);
    }
    return answer;
}

/** Using binary search approach **/

int binary_search(vector<int> nums, int key)
{
    int low = 0, high = nums.size() - 1,mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] == key)
        {
            return mid + 1;
        }
        else if (nums[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high + 1;
}

vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> answer;

    for (int i = 1; i < n; i++)
    {
        nums[i] += (nums[i - 1]);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int size = binary_search(nums, queries[i]);
        answer.push_back(size);
    }
    return answer;
}

int main()
{
    vector<int> nums = {4, 5, 2, 1}, queries = {3, 10, 21};
    nums = answerQueries(nums, queries);

    for (auto element : nums)
    {
        cout << element << " ";
    }
    return 0;
}