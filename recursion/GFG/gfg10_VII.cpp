#include <bits/stdc++.h>
using namespace std;

int solve(string nums, int index, int n, vector<int> curr)
{
    if (index == n)
    {
        return 1;
    }

    int left = solve(nums, index + 1, n, curr);

    curr.push_back(nums[index]);
    int right = solve(nums, index + 1, n, curr);

    return left + right;
}

string betterString(string str1, string str2)
{
    vector<int> curr;
    int num1 = solve(str1, 0, str1.length(), curr);
    int num2 = solve(str2, 0, str2.length(), curr);

    cout << num1 << " " << num2 << endl;
}

int main()
{
    betterString("gfg", "ggg");
    return 0;
}