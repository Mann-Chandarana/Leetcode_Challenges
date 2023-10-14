/* 2220. Minimum Bit Flips to Convert Number */

#include <bits/stdc++.h>
using namespace std;

/* Approach - 1 */

int countBitsFlip(int a, int b)
{
    // Your logic here
    int k = a ^ b; // XOR of these numbers
    int count = 0;
    while (k > 0)
    {
        k = (k & (k - 1)); // This expression makes the last set bit as zero!!
        count++;
    }
    return count;
}

/* Approach - 2 */

int minBitFlips(int start, int goal)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (goal & 1)
            count = start & 1 ? count : count + 1;
        else
            count = start & 1 ? count + 1 : count;
        goal = goal >> 1;
        start = start >> 1;
    }
    return count;
}

int main()
{
    cout << minBitFlips(3, 4) << endl;
    return 0;
}