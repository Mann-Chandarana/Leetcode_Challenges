// 1071. Greatest Common Divisor of Strings

#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1)
        return "";

    else
        return str1.substr(0, __gcd(str1.length(), str2.length()));
}

int main()
{
    return 0;
}