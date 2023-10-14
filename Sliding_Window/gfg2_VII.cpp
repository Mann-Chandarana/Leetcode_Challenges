/******* Minimum Window Subsequence ***** */

/* Very import question */

#include <bits/stdc++.h>
using namespace std;

string minWindow(string str1, string str2)
{
    int j = 0, start = -1, length = INT_MAX, Tidx = 0, Tlen = str2.length();
    string ret;

    while (j < str1.length())
    {
        if (str1[j] == str2[Tidx])
        {
            Tidx++;

            if (Tidx == Tlen)
            {
                int end = j + 1;
                Tidx--;

                while (Tidx >= 0)
                {
                    if (str1[j] == str2[Tidx])
                        Tidx--;
                    j--;
                }
                j++;
                Tidx++;
                if (end - j < length)
                {
                    length = end - j;
                    start = j;
                }
            }
        }
        j++;
    }
    if (start != -1)
    {
        for (int i = start; i < start + length; i++)
            ret.push_back(str1[i]);
    }
    return ret;
}

int main()
{
    return 0;
}