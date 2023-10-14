/*--------  Medium --------*/

/*- Find the Punishment Number of an Integer -*/

//////// Question number 6441.

#include <bits/stdc++.h>
using namespace std;

bool satisfy(string s, int sum, int n, int index, int lengthi)
{
    if (sum == n and lengthi == s.length())
        return true;

    for (int length = 1; length <= s.length() - index; length++)
    {
        sum += stoi(s.substr(index, length));
        lengthi += length;
        if (satisfy(s, sum, n, index + length, lengthi))
            return true;
        lengthi -= length;
        sum -= stoi(s.substr(index, length));
    }
    return false;
}

bool isSatisfy(int n)
{
    string s = to_string(n * n);

    if (satisfy(s, 0, n, 0, 0))
        return true;

    return false;
}

int punishmentNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isSatisfy(i))
            sum += i * i;
    }
    return sum;
}

int main()
{
    cout << punishmentNumber(10) << endl;

    return 0;
}