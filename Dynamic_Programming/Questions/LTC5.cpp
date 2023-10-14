/*-------- Medium -----------*/

/*- Flip String to Monotone Increasing -*/

//////// Question number 926.

#include <bits/stdc++.h>
using namespace std;

/* Recursion + memorization */

int solve(string s, int curr_index, int prev_val, int n, vector<vector<int>> t)
{
    if (curr_index >= n)
        return 0;

    int flip = INT_MAX, no_flip = INT_MAX;

    if (t[curr_index][prev_val] != -1)
    {
        return t[curr_index][prev_val];
    }

    if (s[curr_index] == '0')
    {
        if (prev_val == 1)
        {
            flip = 1 + solve(s, curr_index + 1, 1, n, t);
        }
        else
        {
            flip = 1 + solve(s, curr_index + 1, 1, n, t);
            no_flip = solve(s, curr_index + 1, 0, n, t);
        }
    }
    else if (s[curr_index] == '1')
    {
        if (prev_val == 1)
        {
            no_flip = solve(s, curr_index + 1, 1, n, t);
        }
        else
        {
            flip = 1 + solve(s, curr_index + 1, 0, n, t);
            no_flip = solve(s, curr_index + 1, 1, n, t);
        }
    }

    return t[curr_index][prev_val] = min(flip, no_flip);
}

int minFlipsMonoIncr(string s)
{
    int n = s.length();

    vector<vector<int>> t(n, vector<int>(2, -1));
    return solve(s, 0, 0, n, t);
}

/* Tabulation */

int minFlipsMonoIncr(string s)
{
    int n = s.length();

    vector<vector<int>> t(n + 1, vector<int>(2, 0));

    for (int curr_index = n - 1; curr_index >= 0; curr_index--)
    {
        for (int prev_val = 0; prev_val <= 1; prev_val++)
        {
            int flip = INT_MAX, no_flip = INT_MAX;
            if (s[curr_index] == '0')
            {
                if (prev_val == 1)
                {
                    flip = 1 + t[curr_index + 1][1];
                }
                else
                {
                    flip = 1 + t[curr_index + 1][1];
                    no_flip = t[curr_index + 1][0];
                }
            }
            else if (s[curr_index] == '1')
            {
                if (prev_val == 1)
                {
                    no_flip = t[curr_index + 1][1];
                }
                else
                {
                    flip = 1 + t[curr_index + 1][0];
                    no_flip = t[curr_index + 1][1];
                }
            }
            t[curr_index][prev_val] = min(flip, no_flip);
        }
    }

    return t[0][0];
}

/* Refactored code */

int minFlipsMonoIncr(string s)
{
    int count_one = 0, inverse = 0;

    for (auto i : s)
    {
        if (i == '1')
        {
            count_one++;
        }
        else
        {
            inverse++;
        }
        inverse = min(inverse, count_one);
    }

    return inverse;
}

int main()
{
    cout << minFlipsMonoIncr("010110") << endl;
    return 0;
}