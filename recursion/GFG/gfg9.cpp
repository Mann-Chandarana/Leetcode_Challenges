// Generate all binary strings :- geeks for geekss

/* Medium */

#include <bits/stdc++.h>
using namespace std;

void solve(int index, int n, string curr, bool last_one)
{
    if (index == n)
    {
        cout<<curr<<" ";
        return;
    }
    solve(index + 1, n, curr + '0', true);
    if (last_one)
    {
        solve(index + 1, n, curr + '1', false);
    }
}

void generateBinaryStrings(int num)
{
    string curr;
    bool last_one = true;

    solve(0, num, curr, last_one);

}

int main()
{
    generateBinaryStrings(4);
    return 0;
}