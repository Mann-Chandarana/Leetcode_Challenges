/*-------- Medium -----------*/

/*- Palindrome Partitioning -*/

//////// Question number 131.

#include <bits/stdc++.h>
using namespace std;

// Time complexity
// O(n*(2^n))

// Space complexity
// O(n)

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }
    return true;
}

void solve(int index, string s, vector<string> answer, vector<vector<string>> &ans)
{

    if (index == s.length())
    {
        ans.push_back(answer);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            answer.push_back(s.substr(index,i-index+1));
            solve(i+ 1, s, answer, ans);
            answer.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> answer;
    vector<string> ans;
    solve(0, s, ans, answer);

    return answer;
}

int main()
{
    vector<vector<string>> answer = partition("aab");

    for (auto element : answer)
    {
        for (auto i : element)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}