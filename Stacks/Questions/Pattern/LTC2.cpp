/*-------- Medium --------*/

/*- Remove K Digits -*/

//////// Question number 402.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

string removeKdigits(string num, int k)
{
    string result = ""; // it will act like a stack
    int n = num.length();

    for (int i = 0; i < n; i++)
    {
        while (result.length() > 0 && result.back() > num[i] && k > 0)
        {
            result.pop_back();
            k--;
        }

        if (result.length() > 0 || num[i] != '0')
           result.push_back(num[i]); 
    }

    while (result.length() > 0 && k > 0)
    {
        result.pop_back();
        k--;
    }

    if (result == "")
       return "0";

    return result;
}

int main()
{
    return 0;
}