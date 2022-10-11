/*--------Medium-----------*/

//////// Question number 2149.

#include <bits/stdc++.h>
using namespace std;

/************************ Two pointer approach ***************************/

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> answer(nums.size(),0);
    int posi = 0, negi = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            answer[posi] = nums[i];
            posi += 2;
        }
        else
        {
            answer[negi] = nums[i];
            negi += 2;
        }
    }
    return answer;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    nums = rearrangeArray(nums);

    for (auto element : nums)
    {
        cout << element << " ";
    }

    return 0;
}