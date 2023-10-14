/* 989. Add to Array-Form of Integer */

#include <bits/stdc++.h>
using namespace std;

/* Efficient solutions */

vector<int> addToArrayForm(vector<int> &num, int k)
{
    int carry = 0, j = num.size() - 1;

    while (j >= 0)
    {
        int sum = k % 10 + num[j] + carry;
        k /= 10;
        num[j--] = sum % 10;
        carry = sum / 10;
    }
    while (k > 0)
    {
        int sum = (k % 10) + carry;
        k /= 10;

        num.insert(num.begin(), sum % 10);
        carry = sum / 10;
    }

    if (carry > 0)
        num.insert(num.begin(), carry);

    return num;
}

/* Solution */

vector<int> addToArrayForm(vector<int> &num, int k)
{
    vector<int> ans;
    int n = num.size();

    int carry = 0, i = n - 1;
    while (k > 0 || carry > 0 || i >= 0)
    {
        int sum = carry;
        if (k > 0)
        {
            int remi = k % 10;
            sum += remi;
            k /= 10;
        }
        if (i >= 0)
        {
            sum += num[i];
            i--;
        }
        carry = sum / 10;
        ans.push_back(sum % 10);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> num = {2, 7, 4};
    num = addToArrayForm(num, 181);

    for (auto element : num)
        cout << element << " ";
    return 0;
}