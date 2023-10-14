// 2571. Minimum Operations to Reduce an Integer to 0

#include <bits/stdc++.h>
using namespace std;

int minOperations(int n)
{
    int i = 0, c = 0;
    while (n > 0)
    {
        if (n == pow(2, i))
        {
            n = n - pow(2, i);
            cout << n << endl;
            c++;
            break;
        }
        if (pow(2, i) > n)
        {
            cout << n << endl;
            n = min((pow(2, i) - n), (n - pow(2, i - 1)));
            c++;
            i = 0;
        }
        i++;
    }
    return c;
}

int main()
{
    cout << minOperations(54) << endl;
    return 0;
}