// 905. Sort Array By Parity

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/**** Approach -1) ****/

vector<int> sortArrayByParity(vector<int> &nums)
{
    int j = 0, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
    return nums;
}

/**** Approach -2) ****/

vector<int> sortArrayByParity(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n);

    int start = 0, end = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] & 1)
            answer[end--] = nums[i];
        else
            answer[start++] = nums[i];
    }
    return answer;
}

/**** Approach -3) ****/

vector<int> sortArrayByParity(vector<int> &nums)
{
    sort(all(nums), [](int &a, int &b)
         {
            if(a%2==0 and b%2==0 || a%2!=0 and b%2!=0)
              return a<b;
            return a%2==0; });
    return nums;
}

int main()
{
    return 0;
}