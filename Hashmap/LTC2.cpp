/*--------Medium-----------*/

/*- Longest Palindrome by Concateninig two letter words -*/

//////// Question number 2131.

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string> &words)
{
    unordered_map<string, int> ump;
    int answer = 0;
    int unpaired = 0;

    for (auto w : words)
    {
        if (w[0] == w[1])
        {
            if (ump[w] > 0)
            {
                answer += 4;
                ump[w]--;
                unpaired--;
            }
            else
            {
                unpaired++;
                ump[w]++;
            }
        }
        else
        {
            string r = w;
            reverse(r.begin(), r.end());
            if (ump[r] > 0)
            {
                answer += 4;
                ump[r]--;
            }
            else
            {
                ump[w]++;
            }
        }
    }
    if (unpaired > 0)
    {
        answer += 2;
    }

    return answer;
}

int main()
{
    vector<string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << longestPalindrome(words) << endl;

    return 0;
}