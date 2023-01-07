/*-------- Medium -----------*/

/*- Generate Parentheses -*/

//////// Question number 22.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &answer, int open, int close, string curr, int index, int n)
{
    if (index == 2 * n)
    {
        answer.push_back(curr);
        return;
    }
    if (open < n)
    {
        solve(answer, open + 1, close, curr + '(', index + 1, n);
    }
    if (close < open)
    {
        solve(answer, open, close + 1, curr + ')', index + 1, n);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> answer;
    string curr = "";
    solve(answer, 0, 0, curr, 0, n);
    return answer;
}

int main()
{
    vector<string> answer = generateParenthesis(1);
    for(auto element:answer)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}