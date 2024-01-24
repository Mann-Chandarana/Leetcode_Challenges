/*-------- Medium --------*/

/*- Maximum Length of a Concatenated String with Unique Characters -*/

//////// Question number 1239.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

/*** Using Bit manipulation ***/

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

/*** Using Dynamic Programming ***/

unordered_map<string, int> dp;

bool hasDuplicate(string s1, string s2)
{
    vector<int> freq(26, 0);

    for (auto ch : s1)
    {
        if (freq[ch - 'a'] > 0)
            return true;

        freq[ch - 'a']++;
    }

    for (auto ch : s2)
    {
        if (freq[ch - 'a'] > 0)
            return true;

        freq[ch - 'a']++;
    }
    return false;
}

int fn(int index, string temp, vector<string> &arr)
{
    if (index >= arr.size())
        return temp.length();

    int include = 0, exclude = 0;

    if (dp.find(temp) != dp.end())
        return dp[temp];

    if (hasDuplicate(temp, arr[index]))
    {
        exclude = fn(index + 1, temp, arr);
    }
    else
    {
        exclude = fn(index + 1, temp, arr);
        temp += arr[index];
        include = fn(index + 1, temp, arr);
    }
    return dp[temp] = max(exclude, include);
}

int maxLength(vector<string> &arr)
{
    return fn(0, "", arr);
}

int main()
{
    return 0;
}