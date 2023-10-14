/*-------- Medium -----------*/

/*- Repeated String Match -*/

//////// Question number 686.

#include <bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b)
{
    // a = 'abcd'
    // b = 'cd abcd ab'

    // b = prefix + n*a + suffix => cd abcd ab =>  n+2
    // b = prefix + n*a  => cd (abcd) => n+1
    // b = n*a +suffix => (abcd) ab => n+1
    // b = n*a  => (abcd)  ==> n

    int len_b = b.length();
    int len_a = a.length();

    int n = (len_b / len_a);
    int cnt = n;

    string na = "";

    while (cnt--)
        na += a;

    if (na.find(b) != string::npos)
        return n;

    na += a;
    if (na.find(b) != string::npos)
        return n + 1;

    na += a;
    if (na.find(b) != string::npos)
        return n + 2;

    return -1;
}

int main()
{
    return 0;
}