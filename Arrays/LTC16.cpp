//////// Question number 26.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    vector<int> ans;
    int left = 0, right = 0;

    while (right < nums.size())
    {
        if (nums[left] != nums[right])
        {
            left++;
            nums[left] = nums[right];
        }
        right++;
    }
    return left+1;
}

int main()
{
    vector<int> question = {1, 1, 2};
    cout << removeDuplicates(question) << endl;
    return 0;
}