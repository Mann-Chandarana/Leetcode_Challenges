#include <bits/stdc++.h>
using namespace std;

int reversePairs(vector<int> &nums)
{
    int pairs = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i]) > (2 * nums[j]))
            {
                pairs++;
            }
        }
    }
    return pairs;
}

int main()
{

    return 0;
}