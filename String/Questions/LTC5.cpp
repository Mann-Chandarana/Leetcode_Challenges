/*--------  Medium --------*/

/*- Zigzag Conversion -*/

//////// Question number 6.

#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows <= 1)
        return s;

    vector<string> table(numRows, "");
    int row = 0, isup = false;

    for (int i = 0; i < s.length(); i++)
    {
        table[row] += s[i];
        if (row == numRows - 1)
            isup = true;
        if (row == 0)
            isup = false;

        if (isup)
            row--;

        else
            row++;
    }
    string ans = "";
    for (int i = 0; i < numRows; i++)
        ans += table[i];

    return ans;
}

int main()
{
    cout << convert("PAYPALISHIRING", 3) << endl;
    return 0;
}