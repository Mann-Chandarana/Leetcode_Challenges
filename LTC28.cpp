/* 1422. Maximum Score After Splitting a String */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

int maxScore(string s)
{
    int n = s.length(), zero = 0, one = 0;

    for (int i = 0; i < n; i++)
        s[i] == '0' ? zero++ : one++;

    int score = INT_MIN;

    int left = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            left++;

        else
            one--;

        score = max(score, left + one);
    }
    return score;
}

/* Approach -2) */

int maxScore(string s)
{
    int n = s.length(), one = 0, zero = 0, score = INT_MIN;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '1')
            one++;
        else
            zero++;

        score = max(score, zero - one);
    }
    if (s[n - 1] == '1')
        one++;

    return score + one;
}

int main()
{
    return 0;
}