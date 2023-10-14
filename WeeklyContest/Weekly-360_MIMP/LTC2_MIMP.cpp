/*--------  Medium --------*/

/*- Find the Punishment Number of an Integer -*/

//////// Question number 6441.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Explanation of first appraoch

as we have to find minimum sum so we take minimum element as much as possible let n = 8, target = 6;
1 + 5 = 6
2 + 4 = 6
3 + 3 = 6
so we can take sum of first target/2 values
after that we have to take (n - target/2) elements from target
like
6 7 8 9 10
so our array will be [ 1, 2, 3, 6, 7, 8, 9, 10]
sum = 1 + 2 + 3 + 6 + 7 + 8 + 9 + 10
sum = 1 + 2 + 3 + 6 + ( 6 + 1) + ( 6 + 2) + ( 6 + 3) + ( 6 + 4)
sum = 1 + 2 + 3 + 6 * 5 + 1 + 2 + 3 + 4
sum = ( sum of first half numbers ) + target*( remaining numbers ) + ( sum of first ( remaining numbers -1))
 */

// 1) First approach

/* O(1) */

long long minimumPossibleSum(int n, int target)
{
    int half = (target / 2);

    if (n <= half)
        return (n * 1LL * (n + 1) )/ 2;

    ll first_part = ((half * 1LL * (half + 1)) / 2);
    ll second_part = ((n - half) * 1LL * target);
    ll third_part =((n - half-1) * 1LL * (n - half)) / 2;

    return (first_part + second_part + third_part);
}

// 1) First approach

/******* O(N) *******/

long long minimumPossibleSum(int n, int target)
{
    int i = 1;
    unordered_set<int> st;
    ll ans = 0;

    while (n)
    {
        if (st.find(i) == st.end())
        {
            st.insert(target - i);
            n--;
            ans += i;
        }
        i++;
    }
    return ans;
}

int main()
{
    cout << minimumPossibleSum(16, 32) << endl;
    return 0;
}