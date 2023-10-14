//////// Question number 136.

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int xori = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xori ^= nums[i];
    }
    return xori;
}

int main()
{

    return 0;
}