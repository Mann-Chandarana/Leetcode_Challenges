/*-------- Hard -----------*/

/*- Expression Add Operators -*/

//////// Question number 282.

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(int i, string path, long res, long prevNum, string s, int target)
{
    if (i == s.length() and res == target)
    {
        ans.push_back(path);
        return;
    }

    string curNumstr = "";
    long curNum = 0;

    for (int j = i; j < s.size(); j++)
    {
        if (j > i and s[i] == '0')
            break;

        curNumstr.push_back(s[j]);
        curNum = (curNum * 10) + (s[j] - '0');

        if (i == 0)
        {
            solve(j + 1, path + curNumstr, curNum, curNum, s, target);
        }
        else
        {
            solve(j + 1, path + "+" + curNumstr, res + curNum, curNum, s, target);
            solve(j + 1, path + "-" + curNumstr, res - curNum, -curNum, s, target);
            solve(j + 1, path + "*" + curNumstr, (res - prevNum) + (curNum * prevNum), prevNum * curNum, s, target);
        }
    }
    return;
}

vector<string> addOperators(string num, int target)
{
    int cal = (num[0] - '0');
    string answer = "";
    answer.push_back(num[0]);
    solve(0, "", 0, 0, num, target);

    return ans;
}

int main()
{
    string num = "123";

    vector<string> answer = addOperators(num, 6);

    for (auto element : answer)
    {
        cout << element << endl;
    }
    return 0;
}