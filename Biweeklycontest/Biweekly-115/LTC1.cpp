#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

vector<int> lastVisitedIntegers(vector<string> &words)
{
    int count = 0;
    vector<string> answer;
    vector<int> ans;

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] != "prev")
            answer.push_back(words[i]), count = 0;

        else
        {
            count++;
            if (answer.size() - count < 0)
                ans.push_back(-1);
            else
                ans.push_back(stoi(answer[answer.size() - count]));
        }
    }
    return ans;
}

int main()
{

    return 0;
}