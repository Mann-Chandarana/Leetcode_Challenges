/* 2843. Count Symmetric Integers */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

bool isValid(int number)
{
    string num = to_string(number);
    int n = num.length();

    if (n % 2 != 0)
        return false;

    int left_sum = 0, right_sum = 0;

    for (int i = 0; i < n / 2; i++)
        left_sum += (num[i] - '0');

    for (int i = n / 2; i < n; i++)
        right_sum += (num[i] - '0');

    return left_sum == right_sum;
}

int countSymmetricIntegers(int low, int high)
{
    int ans = 0;
    for (int i = low; i <= high; i++)
        ans += (isValid(i) ? 1 : 0);

    return ans;
}

int main()
{
    return 0;
}