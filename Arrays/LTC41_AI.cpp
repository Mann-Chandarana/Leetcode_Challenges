//////// Question number 169.  

/*  Moore alogrithm  */

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int num = -1, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            num = nums[i];
            count++;
        }
        else if (nums[i] == num)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return num;
}

// int majorityElement(vector<int> &nums)
// {
//     unordered_map<int, int> mp;
//     int n = nums.size();

//     for (int i = 0; i < n; i++)
//     {
//         mp[nums[i]]++;
//     }

//     unordered_map<int, int>::iterator it;

//     for (it = mp.begin(); it != mp.end(); it++)
//     {
//         if ((*it).second > n/2)
//         {
//             return (*it).first;
//         }
//     }
// }
int main()
{

    return 0;
}