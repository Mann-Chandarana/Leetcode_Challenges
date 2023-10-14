/*--------Medium-----------*/

//////// Question number 128.

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(),nums.end());

    int curretNum = 0, streak = 0, maxstreak = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(nums[i] - 1) == st.end())
        {
            streak = 1;
            curretNum = nums[i];
            while (st.find(curretNum + 1) != st.end())
            {
                curretNum++;
                streak++;
            }
            maxstreak = max(maxstreak, streak);
        }
    }

    return maxstreak;
}

int main()
{
    vector<int> answer = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(answer) << endl;
    return 0;
}