#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

void computeLPS(string pat, int m, vector<int> &LPS)
{
    int len = 0;

    LPS[0] = 0;

    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                i = LPS[len - 1];

            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string pat, string txt)
{
    int n = pat.length(), m = txt.length();
    vector<int> result;

    vector<int> LPS(n, 0);

    computeLPS(pat,m,LPS);

    int i = 0, j = 0;

    while (i < n)
    {
        if (pat[i] == txt[j])
            i++, j++;

        if (j == m)
        {
            result.push_back(i - m + 1);
            j = LPS[j - 1];
        }
        else if (pat[i] != txt[j])
        {
            if (j != 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }
    return result;
}

int main()
{

    return 0;
}