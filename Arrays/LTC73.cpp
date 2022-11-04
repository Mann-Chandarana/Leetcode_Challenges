///// Important question

/*-------- Medium -----------*/

/*- Shifting letters -*/

//////// Question number 848.

#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int> &shifts)
{
    int shift = 0;
    for (int i = shifts.size() - 1; i >= 0; i--)
    {
        s[i] = ((s[i] - 'a') + (shift + shifts[i]) % 26) % 26 + 'a';
        shift += shifts[i];
    }
    return s;
}

int main()
{
    string s = "bad";
    vector<int> shifts = {10, 20, 30};

    cout << shiftingLetters(s, shifts) << endl;
    return 0;
}