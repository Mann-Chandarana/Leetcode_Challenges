/* 2828. Check if a String Is an Acronym of Words */

#include <bits/stdc++.h>
using namespace std;

bool isAcronym(vector<string> &words, string s)
{
    string answer = "";

    for (auto word : words)
        answer += word[0];

    if (answer == s)
        return true;

    return false;
}

int main()
{
    return 0;
}