/*--------Medium-----------*/

/*- Count and say -*/

//////// Question number 38.

#include <bits/stdc++.h>
using namespace std;

string answer = "1", result = "";
string countAndSay(int n)
{
    int i = 0, j = 0;
    /// base case
    if (n == 1)
    {
        return answer;
    }

    // calculation part of the window
    while (j < answer.size())
    {
        while (j + 1 < answer.size() and answer[j] == answer[j + 1])
        {
            j++;
        }
        j++;
        result += (to_string(j - i) + answer[i]);
        i = j;
    }

    answer = result;
    result = "";
    n--;

    /// recurisive part
    return countAndSay(n);
}

int main()
{
    cout << countAndSay(5) << endl;

    return 0;
}