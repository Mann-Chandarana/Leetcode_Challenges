#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/********** Appraoch -1) **********/

int longestIdealString(string s, int k)
{
    int n = s.length();

    vector<int> answer(n, 1);
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(s[i] - s[j]) <= k)
                answer[i] = max(answer[i], answer[j] + 1);
        }
        result = max(result, answer[i]);
    }

    return result;
}

/********** Appraoch -2) **********/

int longestIdealString(string s, int k)
{
    int n = s.length();
    vector<int> t(26, 0);

    int result = 0;

    for (int i = 0; i < n; i++)
    {

        int curr = s[i] - 'a';
        int left = max(0, curr - k);
        int right = min(25, curr + k);

        int longest = 0;
        for (int j = left; j <= right; j++)
            longest = max(longest, t[j]);

        t[curr] = max(t[curr], longest + 1);
        result = max(result, t[curr]);
    }

    return result;
}

int fn(int index, int prev, int n, int k, string s)
{

    if (index == n)
        return 0;

    int take = 0, not_take = 0;

    if (prev == 0 and abs(s[prev] - s[index]) <= k)
        take = 1 + fn(index + 1, index, n, k, s);

    not_take = fn(index + 1, prev, n, k, s);

    return max(take, not_take);
}

int longestIdealString(string s, int k)
{
    int n = s.length();
    return fn(0, 0, n, k, s);
}

int main()
{
    return 0;
}