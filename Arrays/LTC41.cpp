//////// Question number 169.

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    unordered_map<int, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second > n/2)
        {
            return (*it).first;
        }
    }
}
int main()
{

    return 0;
}