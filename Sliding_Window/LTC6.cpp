/*--------  Medium --------*/

/*- Max Consecutive Ones III -*/

//////// Question number 1004.

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0, len = 0, countZeros = 0;

    while (j < nums.size())
    {
        if (nums[j] == 0)
            countZeros++;

        while (countZeros > k)
        {
            if (nums[i] == 0)
                countZeros--;
            i++;
        }

        len = max(len, j - i + 1);
        j++;
    }
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestOnes(nums, 3) << endl;
    return 0;
}