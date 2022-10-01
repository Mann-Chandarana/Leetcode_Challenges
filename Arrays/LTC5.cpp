//////// Question number 1470.

#include <bits/stdc++.h>
using namespace std;


///////////Optimised solution
// for (int i = n; i < 2 * n; i++)
// {
//     nums[i] = (nums[i] * 1011) + nums[i - n];
// }
// // step 2. retrive the numbers from the combined numbers;
// int idx = 0;
// for (int i = n; i < 2 * n; i++)
// {
//     nums[idx] = nums[i] % 1011;
//     nums[idx + 1] = nums[i] / 1011;
//     idx += 2;
// }
// return nums;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans(2 * n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        ans[j++] = nums[i];
        ans[j++] = nums[(n) + i];
        cout << j << " " << n + i << endl;
    }

    return ans;
}

int main()
{
    vector<int> question = {2, 5, 1, 3, 4, 7};
    question = shuffle(question, 3);

    return 0;
}