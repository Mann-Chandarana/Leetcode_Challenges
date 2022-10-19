//////// Question number 1832.

#include <bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence)
{
    unordered_map<char, int> ump;

    for (int i = 0; i < sentence.length(); i++)
    {
        ump[sentence[i]]++;
    }

    return ump.size() == 26;
}

int main()
{
    string sentence = "leetcode";
    cout << checkIfPangram(sentence) << endl;
    return 0;
}