/*-------- Medium -----------*/

/*- Count Ways To Build Good Strings -*/

//////// Question number 2466.

#include <bits/stdc++.h>
using namespace std;

/********* With out return value ***********/

// Recursion

void countstrings(int low, int high, int zero, int one, int &count, int length)
{
    if (length > high)
        return;

    if (length >= low)
    {
        count++;
    }

    countstrings(low, high, zero, one, count, length + zero);

    countstrings(low, high, zero, one, count, length + one);
}

// Memorization

void countstrings(int low, int high, int zero, int one, int &count, int length, vector<int> &dp)
{
    if (length > high)
        return;

    if (length >= low)
        dp[length] = count++;

    if (dp[length] != -1)
    {
        dp[length]++;
        return;
    }

    countstrings(low, high, zero, one, count, length + zero, dp);

    countstrings(low, high, zero, one, count, length + one, dp);
}

int countGoodStrings(int low, int high, int zero, int one)
{
    int count = 0, length = 0;
    vector<int> dp(high + 1, -1);
    countstrings(low, high, zero, one, count, length, dp);

    count = 0;
    for (auto element : dp)
    {
        if (element != -1)
            count += element;
    }

    return count;
}


/********* With return value ***********/

// Recursion

int countstrings(int low, int high, int zero, int one, int length)
{
    if (length > high)
        return 0;

    bool add_one = false;
    if (length >= low)
        add_one = true;

    int ans1 = countstrings(low, high, zero, one, length + zero);

    int ans2 = countstrings(low, high, zero, one, length + one);

    return add_one + ans1 + ans2;
}

// Memorization

int countstrings(int low, int high, int zero, int one, int length, vector<int> dp)
{
    if (length > high)
        return 0;

    bool add_one = false;

    if (length >= low)
        add_one = true;

    if (dp[length] != -1)
        return dp[length];

    int ans1 = countstrings(low, high, zero, one, length + zero, dp);

    int ans2 = countstrings(low, high, zero, one, length + one, dp);

    return dp[length] = add_one + ans1 + ans2;
}

// Tabulation

int countGoodStrings(int low, int high, int zero, int one)
{
    int count = 0, length = 0;
    vector<int> dp(high + 1, 0);

    const int M = 1e9 + 7;

    for (int length = high; length >= 0; length--)
    {
        int answer = 0;
        if (length >= low)
            answer += 1;

        if (length + zero <= high)
            answer += (dp[length + zero] % M);

        if (length + one <= high)
            answer += (dp[length + one] % M);

        dp[length] = (answer % M);
    }

    return (dp[0] % M);
}

int main()
{
    cout << countGoodStrings(2, 3, 1, 2) << endl;
    return 0;
}