/* 67. Add Binary */

#include <bits/stdc++.h>
using namespace std;

/* Efficient solution */

string addBinary(string a, string b)
{
    string answer = "";
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 2;
        answer += to_string(sum % 2);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

string addBinary(string a, string b)
{
    string answer = "";

    if (b.size() > a.size())
        swap(a, b);

    while (b.size() < a.size())
        b = "0" + b;
    char carry = '0';

    for (int i = b.size() - 1; i >= 0; i--)
    {
        if (a[i] == '1' and b[i] == '1')
        {
            if (carry == '1')
                answer = '1' + answer;

            else if (carry == '0')
                answer = '0' + answer;

            carry = '1';
        }
        else if (a[i] == '1' and b[i] == '0' || a[i] == '0' and b[i] == '1')
        {
            if (carry == '0')
                answer = '1' + answer;
            else if (carry == '1')
                answer = '0' + answer;
        }
        else
        {
            if (carry == '1')
            {
                answer = '1' + answer;
                carry = '0';
            }
            else
                answer = '0' + answer;
        }
    }
    if (carry == '1')
        answer = '1' + answer;
    return answer;
}

int main()
{
    return 0;
}