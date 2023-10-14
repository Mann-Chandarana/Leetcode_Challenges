/*-------- Medium -----------*/

/*- Letter Combinations of a Phone Number -*/

//////// Question number 17.

#include <bits/stdc++.h>
using namespace std;

vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve(int index, vector<string> &answer, string digit, string curr)
{
    if (index == digit.length())
    {
        if (curr.length() > 0)
        {
            answer.push_back(curr);
        }
        return;
    }
    for (int i = 0; i < keypad[digit[index] - '0'].length(); i++)
    {
        curr.push_back(keypad[digit[index] - '0'][i]);
        solve(index + 1, answer, digit, curr);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> answer;
    string curr;
    solve(0, answer, digits, curr);
    return answer;
}

int main()
{
    string digits = "23";
    vector<string> answer = letterCombinations(digits);

    for (auto element : answer)
    {
        cout << element << " ";
    }
    return 0;
}