/* 338. Counting Bits */

#include <bits/stdc++.h>
using namespace std;

/* Using DP */

vector<int> countBits(int n)
{
    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
        v[i] = v[i / 2] + (1 & i);

    return v;
}

/* Using Inbuild function */

vector<int> countBits(int n)
{
    vector<int> answer(n + 1, 0);

    for (int i = 0; i <= n; i++)
        answer[i] = __builtin_popcount(i);

    return answer;
}

/* General approach O(nLogn) time complexity */

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        if ((n & -n) > 0)
        {
            count++;
            n = n & n - 1;
        }
    }
    return count;
}

vector<int> countBits(int n)
{
    vector<int> answer(n + 1, 0);

    for (int i = 1; i <= n; i++)
        answer[i] = countSetBits(i);

    return answer;
}

int main()
{
    return 0;
}