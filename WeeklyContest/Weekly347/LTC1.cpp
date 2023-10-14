/* 6457. Remove Trailing Zeros From a String */

#include <bits/stdc++.h>
using namespace std;

string removeTrailingZeros(string num)
{
    int n = num.length();
    string answer = "";
    bool trail_zero = true;

    for (int i = n - 1; i >= 0; i--)
    {
        if (num[i] == '0' and trail_zero)
            continue;

        else
            trail_zero = false, answer.push_back(num[i]);
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    cout << removeTrailingZeros("51230100") << endl;
    return 0;
}