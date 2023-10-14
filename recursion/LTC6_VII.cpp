/*-------- Medium -----------*/

/*- Pow(x, n) -*/

//////// Question number 50.

#include <bits/stdc++.h>
using namespace std;

/*
Here we have to take care for the overflow because 
1) integer value ranges from -2,147,483,648 to 2,147,483,647 so when we convert it to positive integer it may overflow so we have to solve this edge case.
--> This can be solved by multiplying one case and decreasing the value of n before converting it to positive.
*/

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        cout << x << endl;
        return 1 / x * myPow(1 / x, -(n + 1));
    }
    cout<<x<<endl;
    return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
}

int main()
{
    cout << myPow(2.00000, -2) << endl;
    return 0;
}