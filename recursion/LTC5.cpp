/*-------- Medium -----------*/

/*- String to Integer (atoi) -*/

//////// Question number 8.

#include <bits/stdc++.h>
using namespace std;

/* Use iteration */

int myAtoi(string str)
{
    int32_t i, ans, sign, backup;
    i = 0;
    while (i < str.length() && str[i] == ' ')
        i++;
    sign = 1; // positive
    if (i < str.length() && str[i] == '+')
    {
        i++;
    }
    else if (i < str.length() && str[i] == '-')
    {
        sign = -1; // negative
        i++;
    }
    ans = 0;
    while (i < str.length() && isdigit(str[i]))
    {
        backup = ans;
        if (sign == 1 && ans > (INT_MAX - (str[i] - '0')) / 10)
            return INT_MAX;
        else if (sign == -1 && ans > (INT_MAX - (str[i] - '0')) / 10)
            return INT_MIN;

        ans = ans * 10 + (str[i] - '0');
        i++;
    }
    return ans * sign;
}

/* Use recursion */

bool isrequired(char ch)
{
    if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
    {
        return true;
    }
    return false;
}

void solve(string s, int index, long long &answer, long long &multiplier)
{
    if (index < 0)
        return;

    if (isrequired(s[index]))
    {
        long long value = (s[index] - '0') * multiplier;
        answer += value;
        multiplier *= 10;
    }
    if (s[index] == '-')
        answer = (-answer);

    if (answer >= INT_MAX)
        answer = INT_MAX;

    else if (answer <= INT_MIN)
        answer = INT_MIN;

    solve(s, index - 1, answer, multiplier);
}

int myAtoi(string s)
{
    int n = s.length() - 1;
    long long multiplier = 1, answer = 0;

    solve(s, n, answer, multiplier);

    return answer;
}

int main()
{
    cout << myAtoi("-91283472332") << endl;
    return 0;
}