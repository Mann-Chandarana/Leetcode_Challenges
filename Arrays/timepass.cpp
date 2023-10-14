#include <bits/stdc++.h>
using namespace std;

void matching_string(string A, string B)
{
    int count = 0, index = 0;
    size_t found = -1;
    for (int i = 0; i < A.size(); i++)
    {
        found = A.find(B, found + 1);
        if (found != string::npos)
        {
            cout << found << "\t\t";
            count++;
        }
        else
        {
            break;
        }
    }
    cout << "\n";
    cout << count << endl;
}

int main()
{
    string mat, pat;
    getline(cin, pat);
    getline(cin, mat);
    matching_string(pat, mat);
    return 0;
}