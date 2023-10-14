/*-------- Medium -----------*/

/*- Count and Say -*/

//////// Question number 38.

#include <bits/stdc++.h>
using namespace std;

/******** Iterative solution ********/

string build(string num)
{
    int freq = 1;
    char curNum = num[0];

    string result = "";

    for (int i = 1; i < num.size(); i++)
    {
        if (curNum == num[i])
            freq++;
        else
        {
            result.push_back((char)('0' + freq));
            result.push_back(curNum);
            curNum = num[i];
            freq = 1;
        }
    }
    result.push_back(char('0' + freq));
    result.push_back(curNum);

    return result;
}

string countAndSay(int n)
{
    string initial = "1";

    for (int i = 0; i < n - 1; i++)
        initial = build(initial);

    return initial;
}

/******** Recursive solution ********/

string answer = "1", result = "";
string countAndSay(int n)
{
    int i = 0, j = 0;
    if (n == 1)
        return answer;

    while (j < answer.size())
    {
        while (j + 1 < answer.size() and answer[j] == answer[j + 1])
            j++;

        j++;
        result += to_string(j - i) + answer[i];
        i = j;
    }
    answer = result;
    result = "";
    n--;
    return countAndSay(n);
}

int main()
{
    cout << countAndSay(4) << endl;
    return 0;
}