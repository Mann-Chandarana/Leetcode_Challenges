//////// Question number 1512.

#include <bits/stdc++.h>
using namespace std;

/* Optimal solution in O(N) time complexity and space complexity will be O(N) */

/* [1,2,3,1,1,3,1,1,3]
there are 5 ones in an array
so for 1st one there will be 4 option to club
and for 2nd one there will be 3 option to club
and for 3rd one there will be 2 option to club
and for 4nd one there will be 1 option to club
and for 5th one there will be 0 option to club

so solution will be (n-1)+(n-2)+.....+1 = (n*(n-1))/2
 */

int numIdenticalPairs(vector<int> &nums)
{

    unordered_map<int, int> hashmap;
    int goodPairs = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        hashmap[nums[i]] += 1;
    }

    for (auto element : hashmap)
    {
        goodPairs += element.second * (element.second - 1) / 2;
    }

    return goodPairs;
}

// int numIdenticalPairs(vector<int> &nums)
// {
//     int counter = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if ((nums[i] == nums[j]) && (i < j))
//             {
//                 counter++;
//             }
//         }
//     }
//     return counter;
// }

int main()
{

    return 0;
}