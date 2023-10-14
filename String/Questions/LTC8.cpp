/*--------  Medium --------*/

/*- Text Justification -*/

//////// Question number 68.

#include <bits/stdc++.h>
using namespace std;

string findline(int i, int j, int space, int extraSpace, vector<string> &words, int &maxwidth)
{
    string line;

    for (int k = i; k < j; k++)
    {
        line += words[k];

        if (k == j - 1) // last word me koi space nahi dalna hai
            continue;
        for (int z = 0; z < space; z++)
            line += " ";

        if (extraSpace > 0)
            line += " ", extraSpace--;
    }

    while (line.length() < maxwidth)
        line += " ";

    return line;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int n = words.size();

    int i = 0;

    while (i < n)
    {
        int letterCount = words[i].length();
        int j = i + 1;
        int gaddhe = 0;

        while (j < n and words[j].length() + 1 + gaddhe + letterCount <= maxWidth)
        {
            letterCount += words[j].length();
            gaddhe++;
            j++;
        }

        int remaining_slots = maxWidth - letterCount;

        int space = gaddhe == 0 ? 0 : (remaining_slots / gaddhe);
        int extraSpace = gaddhe == 0 ? 0 : (remaining_slots % gaddhe);

        if (j == n)
        {
            // Answer should be left justified
            space = 1;
            extraSpace = 0;
        }

        result.push_back(findline(i, j, space, extraSpace, words, maxWidth));
        i = j;
    }

    return result;
}

int main()
{
    return 0;
}