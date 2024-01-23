/*-------- Medium --------*/

/*- Maximum Length of a Concatenated String with Unique Characters -*/

//////// Question number 1239.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

void convert(string str, vector<int> &ArrAsBits)
{
    int charBitset = 0;
    for (auto ch : str)
    {
        int mask = 1 << (ch - 'a');
        if (charBitset & mask)
            return;

        charBitset += mask;
    }

    int length = str.length() << 26;

    ArrAsBits.push_back(charBitset | length);
}

int solve(int index, int prev, vector<int> &ArrAsBits)
{
    int oldchar = ((1 << 26) - 1) & prev;
    int oldlength = prev >> 26;
    int best = oldlength;

    if (index >= ArrAsBits.size())
        return best;

    int newchar = ((1 << 26) - 1) & ArrAsBits[index];

    if (!(oldchar & newchar))
    {
        int newlength = ArrAsBits[index] >> 26;
        int newRes = (newchar | oldchar | (newlength + oldlength << 26));

        best = max(best, solve(index + 1, newRes, ArrAsBits));
    }
    best = max(best, solve(index + 1, prev, ArrAsBits));

    return best;
}

int maxLength(vector<string> &arr)
{
    int n = arr.size();
    vector<int> ArrAsBits;

    for (auto str : arr)
        convert(str, ArrAsBits);

    return solve(0, 0, ArrAsBits);
}

int main()
{
    return 0;
}