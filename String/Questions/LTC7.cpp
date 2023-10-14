/* 168. Excel Sheet Column Title */

#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int N)
{
    string answer = "";

    while (N > 0)
    {
        int rem = N % 26;
        if (rem == 0)
        {
            answer += 'Z';
            N = (N / 26) - 1;
        }
        else
        {
            answer += ((rem - 1) + 'A');
            N /= 26;
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    return 0;
}