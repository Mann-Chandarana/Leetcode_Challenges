/*-------- Medium -----------*/

/*- Restore IP Addresses -*/

//////// Question number 93.

#include <bits/stdc++.h>
using namespace std;

/******* Iterative appraoch *******/

vector<string> restoreIpAddresses(string s)
{
    vector<string> ret;
    string ans;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                for (int l = 1; l <= 3; l++)
                {
                    if (i + j + k + l == s.length())
                    {
                        int A = stoi(s.substr(0, i));
                        int B = stoi(s.substr(i, j));
                        int C = stoi(s.substr(i + j, k));
                        int D = stoi(s.substr(i + j + k, l));

                        if (A <= 255 and B <= 255 and C <= 255 and D <= 255)
                        {
                            if ((ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D)).length() == s.length() + 3)
                            {
                                ret.push_back(ans);
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}

/******* Recursive solution *******/

bool isValid(string s)
{
    if (s.size() > 3 || s.size() == 0)
    {
        return false;
    }
    if (s.size() > 1 and s[0] == '0')
    {
        return false;
    }
    if (s.size() and stoi(s) > 255)
    {
        return false;
    }
    return true;
}

void solve(vector<string> &ans, string answer, int index, int n, string s, int no_dots)
{
    if (no_dots == 3)
    {
        if (isValid(s.substr(index)))
        {
            ans.push_back(answer + s.substr(index));
        }
        return;
    }

    for (int i = index; i < index + 3 and i < n; i++)
    {
        if (isValid(s.substr(index, i - index + 1)))
        {
            answer.push_back(s[i]);
            solve(ans, answer + '.', i + 1, n, s, no_dots + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> answer;
    string ans = "";
    int n = s.length();

    solve(answer, ans, 0, n, s, 0);

    for (auto element : answer)
    {
        cout << element << endl;
    }
    return answer;
}

int main()
{
    restoreIpAddresses("101023");
    return 0;
}