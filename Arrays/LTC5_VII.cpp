//////// Question number 1470.

/* New Learning :-
---> How to store 2 number on the same index
*/

#include <bits/stdc++.h>
using namespace std;

/* Using bit manipulation */

vector<int> shuffle(vector<int> &nums, int n)
{
    int tenBitNum = pow(2, 10) - 1;
    for (int i = 0; i < n; i++)
    {
        int secNum = nums[n + i] << 10;
        nums[i] = nums[i] | secNum;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        nums[2 * i + 1] = nums[i] >> 10;
        nums[2 * i] = nums[i] & tenBitNum;
    }
    return nums;
}

/* Using factorization method */

// vector<int> shuffle(vector<int> &nums, int n)
// {
//     for (int i = 0; i < n; i++)
//         nums[i] = (nums[i] * 10000 + nums[i + n]);

//     int j = n-1;
//     int i = (2 * n)-1;

//     while (i >= 0)
//     {
//         nums[i--] = nums[j] % 10000;
//         nums[i--] = nums[j] / 10000;

//         j--;
//     }
//     return nums;
// }

// /* Using naive approach */

// vector<int> shuffle(vector<int> &nums, int n)
// {
//     vector<int> ans(2 * n);
//     int j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans[j++] = nums[i];
//         ans[j++] = nums[(n) + i];
//         cout << j << " " << n + i << endl;
//     }

//     return ans;
// }

int main()
{
    cout<<"Hello"<<endl;
    vector<int> question = {2, 5, 1, 3, 4, 7};
    question = shuffle(question, 3);

    return 0;
}