/*--------  Medium --------*/

/*- Determine the Minimum Sum of a k-avoiding Array -*/

//////// Question number 2829.

#include <bits/stdc++.h>
using namespace std;

int minimumSum(int n, int k)
{
    int sum = (n * (n + 1)) / 2;
    if (sum < k)
        return sum;

    unordered_set<int> st;
    int size = 0, i = 1;
    sum = 0;

    for (i = 1; i <= k; i++)
    {
        if (st.find(k - i) == st.end())
        {
            sum += i;
            size++;
            st.insert(i);
        }
        if (size == n)
            return sum;
    }

    while (size < n)
        sum += (i++),size++;

    return sum;
}

int main()
{
    cout<<minimumSum(5,4)<<endl;
    return 0;
}