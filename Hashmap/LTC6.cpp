/* Easy :- 997. Find the Town Judge */

#include <bits/stdc++.h>
using namespace std;

/******* Using two vectors *******/

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> trusting(n + 1), trusted(n + 1);

    for (auto element : trust)
    {
        trusting[element[0]]++;
        trusted[element[1]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (trusting[i] == 0 and trusted[i] == n - 1)
            return i;
    }
    return -1;
}

/******* Using one vector *******/

int findJudge(int n, vector<vector<int>> &trust)
{
    if (trust.size() == 0 and n == 1)
    {
        return 1;
    }

    vector<int> count(n + 1);

    for (auto person : trust)
    {
        count[person[0]] = -1;
        count[person[1]]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] == n - 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> ques = {};
    cout << findJudge(2, ques) << endl;
    return 0;
}