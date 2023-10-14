// 1523. Count Odd Numbers in an Interval Range

#include <bits/stdc++.h>
using namespace std;

/* First approach */

int countOdds(int l, int h)
{
    return ((h + 1) / 2) - (l / 2);
}

/* Second approach */

int countOdds(int low, int high)
{
    // Initialize odd with the number of even numbers between low and high.
    int odd = (high - low) / 2;

    // If either low or high is odd, increment odd by 1.
    if (low % 2 || high % 2)
        odd++;

    // Return the number of odd numbers between low and high.
    return odd;
}

int main()
{
    return 0;
}