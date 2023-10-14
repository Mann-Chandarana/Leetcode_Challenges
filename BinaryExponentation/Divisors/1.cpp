#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int main()
{
    int n;
    cin >> n;

    int sum = 0, ct = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << endl;
            ct += 1;
            sum += i;
            if (n / i != i)
            {
                ct += 1;
                sum += n / i;
            }
        }
    }

    return 0;
}