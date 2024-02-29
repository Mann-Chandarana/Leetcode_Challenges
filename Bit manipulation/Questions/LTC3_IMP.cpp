/*-------- Medium --------*/

/*- Bitwise AND of Numbers Range -*/

//////// Question number 201.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int rangeBitwiseAnd(int left, int right)
{
    int shift = 0;

    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

int rangeBitwiseAnd(int left, int right)
{
    while (right > left)
        right = right & (right - 1);
    return right;
}

int main()
{
    cout << rangeBitwiseAnd(5, 7) << endl;
    return 0;
}