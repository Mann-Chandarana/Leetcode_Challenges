//////// Question number 2114.

#include <bits/stdc++.h>
using namespace std;

int mostWordsFound(vector<string> &sentences)
{
    int sum = 0, max_sum = INT_MIN;
    for (int i = 0; i < sentences.size(); i++)
    {
        int counter = 1;
        for (int j = 0; j < sentences[i].length(); j++)
        {
            if (sentences[i][j] == ' ')
            {
                counter++;
            }
        }
        max_sum = max(max_sum, counter);
    }
    return max_sum;
}

int main()
{
    vector<string> sen = {"please wait", "continue to fight", "continue to win"};

    return 0;
}