/* Optimised approach of Longest increaseing subsequence
1) --- using binary search or we can say using upper bound and lower bound 
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int nums[])
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = nums[i];
    }

    vector<int> temp;
    int len = 0;
    temp.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }
    return len;
}

int main()
{
    return 0;
}